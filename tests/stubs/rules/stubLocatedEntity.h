// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubLocatedEntity_custom.h file.

#ifndef STUB_RULES_LOCATEDENTITY_H
#define STUB_RULES_LOCATEDENTITY_H

#include "rules/LocatedEntity.h"
#include "stubLocatedEntity_custom.h"

#ifndef STUB_LocatedEntity_immutables
//#define STUB_LocatedEntity_immutables
  const std::set<std::string>& LocatedEntity::immutables()
  {
    static std::set<std::string> instance; return instance;
  }
#endif //STUB_LocatedEntity_immutables

#ifndef STUB_LocatedEntity_collectObserversForChild
//#define STUB_LocatedEntity_collectObserversForChild
  void LocatedEntity::collectObserversForChild(const LocatedEntity& child, std::set<const LocatedEntity*>& receivers) const
  {
    
  }
#endif //STUB_LocatedEntity_collectObserversForChild

#ifndef STUB_LocatedEntity_LocatedEntity
//#define STUB_LocatedEntity_LocatedEntity
   LocatedEntity::LocatedEntity(const std::string& id, long intId)
    : Router(id, intId)
    , m_type(nullptr)
  {
    
  }
#endif //STUB_LocatedEntity_LocatedEntity

#ifndef STUB_LocatedEntity_LocatedEntity_DTOR
//#define STUB_LocatedEntity_LocatedEntity_DTOR
   LocatedEntity::~LocatedEntity()
  {
    
  }
#endif //STUB_LocatedEntity_LocatedEntity_DTOR

#ifndef STUB_LocatedEntity_clearProperties
//#define STUB_LocatedEntity_clearProperties
  void LocatedEntity::clearProperties()
  {
    
  }
#endif //STUB_LocatedEntity_clearProperties

#ifndef STUB_LocatedEntity_setType
//#define STUB_LocatedEntity_setType
  void LocatedEntity::setType(const TypeNode* t)
  {
    
  }
#endif //STUB_LocatedEntity_setType

#ifndef STUB_LocatedEntity_hasAttr
//#define STUB_LocatedEntity_hasAttr
  bool LocatedEntity::hasAttr(const std::string& name) const
  {
    return false;
  }
#endif //STUB_LocatedEntity_hasAttr

#ifndef STUB_LocatedEntity_getAttr
//#define STUB_LocatedEntity_getAttr
  int LocatedEntity::getAttr(const std::string& name, Atlas::Message::Element&) const
  {
    return 0;
  }
#endif //STUB_LocatedEntity_getAttr

#ifndef STUB_LocatedEntity_getAttrType
//#define STUB_LocatedEntity_getAttrType
  int LocatedEntity::getAttrType(const std::string& name, Atlas::Message::Element&, int type) const
  {
    return 0;
  }
#endif //STUB_LocatedEntity_getAttrType

#ifndef STUB_LocatedEntity_setAttr
//#define STUB_LocatedEntity_setAttr
  PropertyBase* LocatedEntity::setAttr(const std::string& name, const Atlas::Message::Element&)
  {
    return nullptr;
  }
#endif //STUB_LocatedEntity_setAttr

#ifndef STUB_LocatedEntity_getProperty
//#define STUB_LocatedEntity_getProperty
  const PropertyBase* LocatedEntity::getProperty(const std::string& name) const
  {
    return nullptr;
  }
#endif //STUB_LocatedEntity_getProperty

#ifndef STUB_LocatedEntity_modProperty
//#define STUB_LocatedEntity_modProperty
  PropertyBase* LocatedEntity::modProperty(const std::string& name, const Atlas::Message::Element& def_val )
  {
    return nullptr;
  }
#endif //STUB_LocatedEntity_modProperty

#ifndef STUB_LocatedEntity_setProperty
//#define STUB_LocatedEntity_setProperty
  PropertyBase* LocatedEntity::setProperty(const std::string& name, std::unique_ptr<PropertyBase> prop)
  {
    return nullptr;
  }
#endif //STUB_LocatedEntity_setProperty

#ifndef STUB_LocatedEntity_installDelegate
//#define STUB_LocatedEntity_installDelegate
  void LocatedEntity::installDelegate(int, const std::string&)
  {
    
  }
#endif //STUB_LocatedEntity_installDelegate

#ifndef STUB_LocatedEntity_removeDelegate
//#define STUB_LocatedEntity_removeDelegate
  void LocatedEntity::removeDelegate(int, const std::string&)
  {
    
  }
#endif //STUB_LocatedEntity_removeDelegate

#ifndef STUB_LocatedEntity_onContainered
//#define STUB_LocatedEntity_onContainered
  void LocatedEntity::onContainered(const Ref<LocatedEntity>& oldLocation)
  {
    
  }
#endif //STUB_LocatedEntity_onContainered

#ifndef STUB_LocatedEntity_onUpdated
//#define STUB_LocatedEntity_onUpdated
  void LocatedEntity::onUpdated()
  {
    
  }
#endif //STUB_LocatedEntity_onUpdated

#ifndef STUB_LocatedEntity_destroy
//#define STUB_LocatedEntity_destroy
  void LocatedEntity::destroy()
  {
    
  }
#endif //STUB_LocatedEntity_destroy

#ifndef STUB_LocatedEntity_getDomain
//#define STUB_LocatedEntity_getDomain
  Domain* LocatedEntity::getDomain()
  {
    return nullptr;
  }
#endif //STUB_LocatedEntity_getDomain

#ifndef STUB_LocatedEntity_getDomain
//#define STUB_LocatedEntity_getDomain
  const Domain* LocatedEntity::getDomain() const
  {
    return nullptr;
  }
#endif //STUB_LocatedEntity_getDomain

#ifndef STUB_LocatedEntity_setDomain
//#define STUB_LocatedEntity_setDomain
  void LocatedEntity::setDomain(std::unique_ptr<Domain> domain)
  {
    
  }
#endif //STUB_LocatedEntity_setDomain

#ifndef STUB_LocatedEntity_sendWorld
//#define STUB_LocatedEntity_sendWorld
  void LocatedEntity::sendWorld(const Operation& op)
  {
    
  }
#endif //STUB_LocatedEntity_sendWorld

#ifndef STUB_LocatedEntity_setScript
//#define STUB_LocatedEntity_setScript
  void LocatedEntity::setScript(std::unique_ptr<Script> scrpt)
  {
    
  }
#endif //STUB_LocatedEntity_setScript

#ifndef STUB_LocatedEntity_makeContainer
//#define STUB_LocatedEntity_makeContainer
  void LocatedEntity::makeContainer()
  {
    
  }
#endif //STUB_LocatedEntity_makeContainer

#ifndef STUB_LocatedEntity_changeContainer
//#define STUB_LocatedEntity_changeContainer
  void LocatedEntity::changeContainer(const Ref<LocatedEntity>&)
  {
    
  }
#endif //STUB_LocatedEntity_changeContainer

#ifndef STUB_LocatedEntity_merge
//#define STUB_LocatedEntity_merge
  void LocatedEntity::merge(const Atlas::Message::MapType&)
  {
    
  }
#endif //STUB_LocatedEntity_merge

#ifndef STUB_LocatedEntity_addChild
//#define STUB_LocatedEntity_addChild
  void LocatedEntity::addChild(LocatedEntity& childEntity)
  {
    
  }
#endif //STUB_LocatedEntity_addChild

#ifndef STUB_LocatedEntity_removeChild
//#define STUB_LocatedEntity_removeChild
  void LocatedEntity::removeChild(LocatedEntity& childEntity)
  {
    
  }
#endif //STUB_LocatedEntity_removeChild

#ifndef STUB_LocatedEntity_addListener
//#define STUB_LocatedEntity_addListener
  void LocatedEntity::addListener(OperationsListener* listener)
  {
    
  }
#endif //STUB_LocatedEntity_addListener

#ifndef STUB_LocatedEntity_removeListener
//#define STUB_LocatedEntity_removeListener
  void LocatedEntity::removeListener(OperationsListener* listener)
  {
    
  }
#endif //STUB_LocatedEntity_removeListener

#ifndef STUB_LocatedEntity_applyProperty
//#define STUB_LocatedEntity_applyProperty
  void LocatedEntity::applyProperty(const std::string& name, PropertyBase* prop)
  {
    
  }
#endif //STUB_LocatedEntity_applyProperty

#ifndef STUB_LocatedEntity_collectObservers
//#define STUB_LocatedEntity_collectObservers
  void LocatedEntity::collectObservers(std::set<const LocatedEntity*>& observers) const
  {
    
  }
#endif //STUB_LocatedEntity_collectObservers

#ifndef STUB_LocatedEntity_broadcast
//#define STUB_LocatedEntity_broadcast
  void LocatedEntity::broadcast(const Atlas::Objects::Operation::RootOperation& op, OpVector& res, Visibility visibility) const
  {
    
  }
#endif //STUB_LocatedEntity_broadcast

#ifndef STUB_LocatedEntity_processAppearDisappear
//#define STUB_LocatedEntity_processAppearDisappear
  void LocatedEntity::processAppearDisappear(std::set<const LocatedEntity*> previousObserving, OpVector& res) const
  {
    
  }
#endif //STUB_LocatedEntity_processAppearDisappear

#ifndef STUB_LocatedEntity_isVisibleForOtherEntity
//#define STUB_LocatedEntity_isVisibleForOtherEntity
  bool LocatedEntity::isVisibleForOtherEntity(const LocatedEntity* watcher) const
  {
    return false;
  }
#endif //STUB_LocatedEntity_isVisibleForOtherEntity

#ifndef STUB_LocatedEntity_canReach
//#define STUB_LocatedEntity_canReach
  bool LocatedEntity::canReach(const EntityLocation& entityLocation, float extraReach ) const
  {
    return false;
  }
#endif //STUB_LocatedEntity_canReach

#ifndef STUB_LocatedEntity_describeEntity
//#define STUB_LocatedEntity_describeEntity
  std::string LocatedEntity::describeEntity() const
  {
    return "";
  }
#endif //STUB_LocatedEntity_describeEntity


#endif