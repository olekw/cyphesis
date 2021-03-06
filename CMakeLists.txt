cmake_minimum_required(VERSION 3.2)

project(Cyphesis)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/tools/cmake)
set(CMAKE_CXX_STANDARD 14)

include(GNUInstallDirs)
include(FindPkgConfig)
include(CheckFunctionExists)
include(CheckIncludeFiles)
include(GetGitRevisionDescription)
include(CMakeDependentOption)

# Version setup

set(CYPHESIS_VERSION_MAJOR 0)
set(CYPHESIS_VERSION_MINOR 7)
set(CYPHESIS_VERSION_PATCH 0)

set(VERSION ${CYPHESIS_VERSION_MAJOR}.${CYPHESIS_VERSION_MINOR}.${CYPHESIS_VERSION_PATCH})

option(PYTHON_USE_MALLOC "Use malloc instead of Python's own allocator. This helps with diagnosing memory usage, but us slightly slower." FALSE)

# Set compiler flags
set(WF_WARNING_FLAGS -Wall -Winit-self -Wcast-qual -Wwrite-strings -Wextra -Wundef -Wmissing-declarations -Wno-unused-parameter -Wshadow -Wno-missing-field-initializers -Wno-long-long)

add_definitions(-DHAVE_CONFIG_H)

include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/external ${PROJECT_BINARY_DIR}/generated)

enable_testing()

# Meta data
get_git_head_revision(GIT_REFSPEC GIT_SHA1)
set(DESCRIPTION "The Worldforge server.")
set(SOCKET_DIR ${CMAKE_INSTALL_FULL_LOCALSTATEDIR}/tmp)
set(PACKAGE_BUGREPORT "erik@ogenvik.org")

check_function_exists(getuid HAVE_GETUID)
check_function_exists(nice HAVE_NICE)
check_function_exists(sigaction HAVE_SIGACTION)
check_function_exists(fork HAVE_FORK)
check_function_exists(gettimeofday HAVE_GETTIMEOFDAY)
check_function_exists(uname HAVE_UNAME)
check_function_exists(localtime_r HAVE_LOCALTIME_R)
check_function_exists(syslog HAVE_SYSLOG)

check_include_files(syslog.h HAVE_SYSLOG_H)
check_include_files(sys/utsname.h HAVE_SYS_UTSNAME_H)
check_include_files(sys/un.h HAVE_SYS_UN_H)
check_include_files(sys/wait.h HAVE_SYS_WAIT_H)
check_include_files(io.h HAVE_IO_H)
check_include_files(getopt.h HAVE_GETOPT_H)
check_include_files(dirent.h HAVE_DIRENT_H)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
link_libraries(Threads::Threads)

pkg_check_modules(WF REQUIRED varconf-1.0>=0.6.7 mercator-0.4>=0.4.0 atlascpp-0.7>=0.7.0 wfmath-1.0>=1.0.3)
link_directories(${WF_LIBRARY_DIRS})
include_directories(${WF_INCLUDE_DIRS})
link_libraries(${WF_LIBRARIES})

pkg_check_modules(SIGCPP REQUIRED sigc++-2.0>=2.0.0)
link_directories(${SIGCPP_LIBRARY_DIRS})
include_directories(${SIGCPP_INCLUDE_DIRS})
link_libraries(${SIGCPP_LIBRARIES})

find_package(PythonLibs 3.3 REQUIRED)
link_directories(${PYTHON_LIBRARY_DIRS})
include_directories(${PYTHON_INCLUDE_DIRS})

if (PYTHON_USE_MALLOC)
    add_compile_definitions(PYTHON_MALLOC)
endif ()

find_package(PythonInterp 3 REQUIRED)

find_package(GCrypt 1.2 REQUIRED)
link_directories(${GCRYPT_LIBRARY_DIRS})
include_directories(${GCRYPT_INCLUDE_DIRS})

#The default FindBullet.cmake macro doesn't look in pkg-config first, so we'll do that ourselves.
pkg_check_modules(BULLET bullet>=2.81)
if (NOT BULLET_FOUND)
    find_package(Bullet 2.81 REQUIRED)
endif (NOT BULLET_FOUND)

link_directories(${BULLET_LIBRARY_DIRS})
include_directories(${BULLET_INCLUDE_DIRS})

find_package(Avahi)
if (AVAHI_FOUND)
    link_directories(${AVAHI_LIBRARY_DIRS})
    include_directories(${AVAHI_INCLUDE_DIR})
    set(HAVE_AVAHI 1)
endif (AVAHI_FOUND)


find_package(PostgreSQL 7.1)
cmake_dependent_option(CYPHESIS_USE_POSTGRES "Use PostgreSQL for storage" FALSE "PostgreSQL_FOUND" FALSE)

find_package(SQLite3 REQUIRED)
if (NOT SQLITE3_FOUND)
    message(FATAL_ERROR "Could not find SQLite 3 development package.")
endif (NOT SQLITE3_FOUND)

pkg_check_modules(XDG REQUIRED libxdg-basedir>=1.0.0)
link_directories(${XDG_LIBRARY_DIRS})
link_libraries(${XDG_LIBRARIES})
include_directories(${XDG_INCLUDE_DIRS})

find_package(Readline REQUIRED)
link_directories(${READLINE_LIBRARY_DIRS})
include_directories(${READLINE_INCLUDE_DIRS})

find_package(Boost
    1.46.0
    REQUIRED
    COMPONENTS filesystem system)

link_directories(${Boost_LIBRARY_DIRS})
link_libraries(${Boost_LIBRARIES})
include_directories(${Boost_INCLUDE_DIRS})

set(ASSETS_DIR assets-${VERSION})
set(ASSETSREPO_DIR ${PROJECT_SOURCE_DIR}/assetsrepo)

find_program(SUBVERSION_CMD NAMES svn)
find_program(PYTHON_CMD NAMES python)
find_program(RSYNC_CMD NAMES rsync)

add_custom_target(assets-download)
if (RSYNC_CMD)
    add_custom_command(
        TARGET assets-download
        COMMAND ${CMAKE_COMMAND} -E echo "I will now use rsync to install the assets from amber.worldforge.org into ${ASSETS_DIR}."
        COMMAND ${CMAKE_COMMAND} -E make_directory ${ASSETS_DIR}
        #We'll for now only copy ".mesh" files.
        COMMAND rsync -rtzu --include='*.mesh' --include='*/' --exclude='*' amber.worldforge.org::ember-media/ember-media-0.8.0/media/assets ${ASSETS_DIR}
        COMMAND ${CMAKE_COMMAND} -E echo "Copying ${ASSETS_DIR} to ${CMAKE_INSTALL_FULL_DATADIR}/cyphesis/assets."
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_DIR} ${CMAKE_INSTALL_FULL_DATADIR}/cyphesis/
        COMMAND ${CMAKE_COMMAND} -E echo "Done."
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )
else (RSYNC_CMD)
    add_custom_command(
        TARGET assets-download
        COMMAND ${CMAKE_COMMAND} -E echo "Could not find the Rsync command. The target 'assets-download' is disabled."
    )
endif (RSYNC_CMD)


add_custom_target(assetsrepo-checkout)
if (SUBVERSION_CMD)
    add_custom_command(
        TARGET assetsrepo-checkout
        COMMAND ${CMAKE_COMMAND} -E echo "Using Subversion to checkout https://svn.worldforge.org:886/svn/media/trunk/assets to ${ASSETSREPO_DIR}/assets."
        COMMAND ${CMAKE_COMMAND} -E make_directory ${ASSETSREPO_DIR}
        COMMAND ${SUBVERSION_CMD} co https://svn.worldforge.org:886/svn/media/trunk/assets ${ASSETSREPO_DIR}/assets
    )
else (SUBVERSION_CMD)
    add_custom_command(
        TARGET assetsrepo-checkout
        COMMAND ${CMAKE_COMMAND} -E echo "Could not find the Subversion command 'svn'. The target 'assetsrepo-checkout' is disabled."
    )
endif (SUBVERSION_CMD)

##TODO: check for binreloc?

#We'll use xmllint for validating schemas of some of our xml files.
find_program(XMLLINT xmllint)

set(STUB_HEADERS "")

macro(wf_generate_stubs DIRECTORY)

    file(GLOB_RECURSE H_FILES RELATIVE "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/src/${DIRECTORY}/*.h")

    set(STUB_DIRECTORY ${CMAKE_SOURCE_DIR}/tests/stubs)

    foreach (FILE ${H_FILES})
        set(STUB_FILE ${STUB_DIRECTORY}/stub${FILE}.h)
        set(STUB_CUSTOM_FILE ${STUB_DIRECTORY}/stub${FILE}.h)
        set(SOURCE_FILE "${CMAKE_SOURCE_DIR}/src/${FILE}")

        add_custom_command(TARGET stubs
            COMMAND ${CMAKE_COMMAND} -E echo "Generating stubs for ${FILE}\n"
            COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_SOURCE_DIR}/tools/scripts/generator/generate_stub.py ${FILE} ${STUB_DIRECTORY}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src
            )

        list(APPEND STUB_HEADERS ${STUB_FILE})
    endforeach (FILE)

endmacro()


# Add a "check" target, which builds and runs the tests.
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} -E Benchmark)

# Add a "benchmark" target, which builds and runs the benchmarks.
add_custom_target(benchmark COMMAND ${CMAKE_CTEST_COMMAND} -R Benchmark)

configure_file(tools/Version.tmpl.h generated/Version.h @ONLY)
configure_file(tools/config.tmpl.h generated/config.h @ONLY)


add_subdirectory(src)
add_subdirectory(external)
add_subdirectory(data)
add_subdirectory(tools)
add_subdirectory(docs)
#Only build tests if the "check" target is used.
add_subdirectory(tests EXCLUDE_FROM_ALL)

configure_file(docs/Doxyfile.in Doxyfile @ONLY)
configure_file(docs/Doxyfile-python.in Doxyfile-python @ONLY)

install(FILES README.md COPYING AUTHORS THANKS NEWS DESTINATION ${CMAKE_INSTALL_DATADIR}/doc/cyphesis)
install(DIRECTORY DESTINATION ${SOCKET_DIR})

## Doxygen support, exports a "dox" target.

find_package(Doxygen)

if (DOXYGEN_FOUND)

    set(DOXYGEN_OUTPUT doc)

    add_custom_command(
        OUTPUT ${DOXYGEN_OUTPUT}
        COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile-python
        COMMAND ${CMAKE_COMMAND} -E echo "Done."
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile-python
    )

    add_custom_target(dox DEPENDS ${DOXYGEN_OUTPUT})

endif (DOXYGEN_FOUND)

add_custom_command(
    OUTPUT ChangeLog
    COMMAND ${CMAKE_SOURCE_DIR}/tools/support/generate-ChangeLog.sh ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR} cce66ef4a196a4871ebaebe82cd91c8dd733be13
)
add_custom_target(changelog DEPENDS ChangeLog)

# Packaging

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${DESCRIPTION})
set(CPACK_PACKAGE_VENDOR "Worldforge")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${CYPHESIS_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CYPHESIS_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${CYPHESIS_VERSION_PATCH}")
#set(CPACK_INSTALL_SCRIPT "sh ${CMAKE_SOURCE_DIR}/support/generate-ChangeLog.sh ${CMAKE_SOURCE_DIR} ${CPACK_PACKAGE_INSTALL_DIRECTORY} 8bd480b053190ffde2afe33af66f484953036f5a")

set(CPACK_SOURCE_GENERATOR TBZ2 ZIP)

set(CPACK_SOURCE_PACKAGE_FILE_NAME "${PROJECT_NAME}-${VERSION}" CACHE INTERNAL "tarball basename")

set(CPACK_SOURCE_IGNORE_FILES
    # no hidden files
    "/\\\\..+$"
    "~$"
    )

include(CPack)
