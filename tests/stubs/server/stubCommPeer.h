// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubCommPeer_custom.h file.

#include "server/CommPeer.h"
#include "stubCommPeer_custom.h"

#ifndef STUB_SERVER_COMMPEER_H
#define STUB_SERVER_COMMPEER_H

#ifndef STUB_CommPeer_CommPeer
//#define STUB_CommPeer_CommPeer
   CommPeer::CommPeer(const std::string & name, boost::asio::io_service& io_service)
    : CommAsioClient(name, io_service)
  {
    
  }
#endif //STUB_CommPeer_CommPeer

#ifndef STUB_CommPeer_CommPeer_DTOR
//#define STUB_CommPeer_CommPeer_DTOR
   CommPeer::~CommPeer()
  {
    
  }
#endif //STUB_CommPeer_CommPeer_DTOR

#ifndef STUB_CommPeer_connect
//#define STUB_CommPeer_connect
  void CommPeer::connect(const std::string &, int)
  {
    
  }
#endif //STUB_CommPeer_connect

#ifndef STUB_CommPeer_connect
//#define STUB_CommPeer_connect
  void CommPeer::connect(const boost::asio::ip::tcp::endpoint&)
  {
    
  }
#endif //STUB_CommPeer_connect

#ifndef STUB_CommPeer_setup
//#define STUB_CommPeer_setup
  void CommPeer::setup(Link *)
  {
    
  }
#endif //STUB_CommPeer_setup

#ifndef STUB_CommPeer_checkAuth
//#define STUB_CommPeer_checkAuth
  void CommPeer::checkAuth()
  {
    
  }
#endif //STUB_CommPeer_checkAuth


#endif