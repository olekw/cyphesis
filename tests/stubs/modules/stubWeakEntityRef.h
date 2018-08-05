// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubWeakEntityRef_custom.h file.

#ifndef STUB_MODULES_WEAKENTITYREF_H
#define STUB_MODULES_WEAKENTITYREF_H

#include "modules/WeakEntityRef.h"
#include "stubWeakEntityRef_custom.h"

#ifndef STUB_WeakEntityRef_onEntityDeleted
//#define STUB_WeakEntityRef_onEntityDeleted
  void WeakEntityRef::onEntityDeleted()
  {
    
  }
#endif //STUB_WeakEntityRef_onEntityDeleted

#ifndef STUB_WeakEntityRef_setup
//#define STUB_WeakEntityRef_setup
  void WeakEntityRef::setup()
  {
    
  }
#endif //STUB_WeakEntityRef_setup

#ifndef STUB_WeakEntityRef_WeakEntityRef
//#define STUB_WeakEntityRef_WeakEntityRef
   WeakEntityRef::WeakEntityRef(const Ref<LocatedEntity>&)
    : sigc::trackable(???)
    , m_inner(nullptr)
  {
    
  }
#endif //STUB_WeakEntityRef_WeakEntityRef

#ifndef STUB_WeakEntityRef_WeakEntityRef
//#define STUB_WeakEntityRef_WeakEntityRef
   WeakEntityRef::WeakEntityRef(LocatedEntity*)
    : sigc::trackable(LocatedEntity)
    , m_inner(nullptr)
  {
    
  }
#endif //STUB_WeakEntityRef_WeakEntityRef

#ifndef STUB_WeakEntityRef_WeakEntityRef
//#define STUB_WeakEntityRef_WeakEntityRef
   WeakEntityRef::WeakEntityRef(const WeakEntityRef& ref)
    : sigc::trackable(ref)
    , m_inner(nullptr)
  {
    
  }
#endif //STUB_WeakEntityRef_WeakEntityRef


#endif