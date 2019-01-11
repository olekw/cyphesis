// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubEntity_custom.h file.

#ifndef STUB_RULES_SIMULATION_ENTITY_H
#define STUB_RULES_SIMULATION_ENTITY_H

#include "rules/simulation/Entity.h"
#include "stubEntity_custom.h"

#ifndef STUB_Entity_Entity
//#define STUB_Entity_Entity
   Entity::Entity(const std::string & id, long intId)
    : LocatedEntity(id, intId)
  {
    
  }
#endif //STUB_Entity_Entity

#ifndef STUB_Entity_Entity_DTOR
//#define STUB_Entity_Entity_DTOR
   Entity::~Entity()
  {
    
  }
#endif //STUB_Entity_Entity_DTOR

#ifndef STUB_Entity_setType
//#define STUB_Entity_setType
  void Entity::setType(const TypeNode * t)
  {
    
  }
#endif //STUB_Entity_setType

#ifndef STUB_Entity_setAttr
//#define STUB_Entity_setAttr
  PropertyBase* Entity::setAttr(const std::string & name, const Atlas::Message::Element &)
  {
    return nullptr;
  }
#endif //STUB_Entity_setAttr

#ifndef STUB_Entity_getProperty
//#define STUB_Entity_getProperty
  const PropertyBase* Entity::getProperty(const std::string & name) const
  {
    return nullptr;
  }
#endif //STUB_Entity_getProperty

#ifndef STUB_Entity_modProperty
//#define STUB_Entity_modProperty
  PropertyBase* Entity::modProperty(const std::string & name, const Atlas::Message::Element& def_val )
  {
    return nullptr;
  }
#endif //STUB_Entity_modProperty

#ifndef STUB_Entity_setProperty
//#define STUB_Entity_setProperty
  PropertyBase* Entity::setProperty(const std::string & name, PropertyBase * prop)
  {
    return nullptr;
  }
#endif //STUB_Entity_setProperty

#ifndef STUB_Entity_addToMessage
//#define STUB_Entity_addToMessage
  void Entity::addToMessage(Atlas::Message::MapType &) const
  {
    
  }
#endif //STUB_Entity_addToMessage

#ifndef STUB_Entity_addToEntity
//#define STUB_Entity_addToEntity
  void Entity::addToEntity(const Atlas::Objects::Entity::RootEntity &) const
  {
    
  }
#endif //STUB_Entity_addToEntity

#ifndef STUB_Entity_ActuateOperation
//#define STUB_Entity_ActuateOperation
  void Entity::ActuateOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_ActuateOperation

#ifndef STUB_Entity_AppearanceOperation
//#define STUB_Entity_AppearanceOperation
  void Entity::AppearanceOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_AppearanceOperation

#ifndef STUB_Entity_AttackOperation
//#define STUB_Entity_AttackOperation
  void Entity::AttackOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_AttackOperation

#ifndef STUB_Entity_CombineOperation
//#define STUB_Entity_CombineOperation
  void Entity::CombineOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_CombineOperation

#ifndef STUB_Entity_CreateOperation
//#define STUB_Entity_CreateOperation
  void Entity::CreateOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_CreateOperation

#ifndef STUB_Entity_DeleteOperation
//#define STUB_Entity_DeleteOperation
  void Entity::DeleteOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_DeleteOperation

#ifndef STUB_Entity_DisappearanceOperation
//#define STUB_Entity_DisappearanceOperation
  void Entity::DisappearanceOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_DisappearanceOperation

#ifndef STUB_Entity_DivideOperation
//#define STUB_Entity_DivideOperation
  void Entity::DivideOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_DivideOperation

#ifndef STUB_Entity_EatOperation
//#define STUB_Entity_EatOperation
  void Entity::EatOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_EatOperation

#ifndef STUB_Entity_GetOperation
//#define STUB_Entity_GetOperation
  void Entity::GetOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_GetOperation

#ifndef STUB_Entity_ImaginaryOperation
//#define STUB_Entity_ImaginaryOperation
  void Entity::ImaginaryOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_ImaginaryOperation

#ifndef STUB_Entity_InfoOperation
//#define STUB_Entity_InfoOperation
  void Entity::InfoOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_InfoOperation

#ifndef STUB_Entity_LookOperation
//#define STUB_Entity_LookOperation
  void Entity::LookOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_LookOperation

#ifndef STUB_Entity_MoveOperation
//#define STUB_Entity_MoveOperation
  void Entity::MoveOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_MoveOperation

#ifndef STUB_Entity_NourishOperation
//#define STUB_Entity_NourishOperation
  void Entity::NourishOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_NourishOperation

#ifndef STUB_Entity_SetOperation
//#define STUB_Entity_SetOperation
  void Entity::SetOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_SetOperation

#ifndef STUB_Entity_SightOperation
//#define STUB_Entity_SightOperation
  void Entity::SightOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_SightOperation

#ifndef STUB_Entity_SoundOperation
//#define STUB_Entity_SoundOperation
  void Entity::SoundOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_SoundOperation

#ifndef STUB_Entity_TalkOperation
//#define STUB_Entity_TalkOperation
  void Entity::TalkOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_TalkOperation

#ifndef STUB_Entity_TickOperation
//#define STUB_Entity_TickOperation
  void Entity::TickOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_TickOperation

#ifndef STUB_Entity_TouchOperation
//#define STUB_Entity_TouchOperation
  void Entity::TouchOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_TouchOperation

#ifndef STUB_Entity_UpdateOperation
//#define STUB_Entity_UpdateOperation
  void Entity::UpdateOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_UpdateOperation

#ifndef STUB_Entity_UseOperation
//#define STUB_Entity_UseOperation
  void Entity::UseOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_UseOperation

#ifndef STUB_Entity_WieldOperation
//#define STUB_Entity_WieldOperation
  void Entity::WieldOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_WieldOperation

#ifndef STUB_Entity_RelayOperation
//#define STUB_Entity_RelayOperation
  void Entity::RelayOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_RelayOperation

#ifndef STUB_Entity_ThoughtOperation
//#define STUB_Entity_ThoughtOperation
  void Entity::ThoughtOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_ThoughtOperation

#ifndef STUB_Entity_externalOperation
//#define STUB_Entity_externalOperation
  void Entity::externalOperation(const Operation & op, Link &)
  {
    
  }
#endif //STUB_Entity_externalOperation

#ifndef STUB_Entity_operation
//#define STUB_Entity_operation
  void Entity::operation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_operation

#ifndef STUB_Entity_callDelegate
//#define STUB_Entity_callDelegate
  HandlerResult Entity::callDelegate(const std::string &, const Operation &, OpVector &)
  {
    return *static_cast<HandlerResult*>(nullptr);
  }
#endif //STUB_Entity_callDelegate

#ifndef STUB_Entity_callOperation
//#define STUB_Entity_callOperation
  void Entity::callOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Entity_callOperation

#ifndef STUB_Entity_installDelegate
//#define STUB_Entity_installDelegate
  void Entity::installDelegate(int, const std::string &)
  {
    
  }
#endif //STUB_Entity_installDelegate

#ifndef STUB_Entity_removeDelegate
//#define STUB_Entity_removeDelegate
  void Entity::removeDelegate(int, const std::string &)
  {
    
  }
#endif //STUB_Entity_removeDelegate

#ifndef STUB_Entity_addChild
//#define STUB_Entity_addChild
  void Entity::addChild(LocatedEntity& childEntity)
  {
    
  }
#endif //STUB_Entity_addChild

#ifndef STUB_Entity_removeChild
//#define STUB_Entity_removeChild
  void Entity::removeChild(LocatedEntity& childEntity)
  {
    
  }
#endif //STUB_Entity_removeChild

#ifndef STUB_Entity_onContainered
//#define STUB_Entity_onContainered
  void Entity::onContainered(const Ref<LocatedEntity>& oldLocation)
  {
    
  }
#endif //STUB_Entity_onContainered

#ifndef STUB_Entity_onUpdated
//#define STUB_Entity_onUpdated
  void Entity::onUpdated()
  {
    
  }
#endif //STUB_Entity_onUpdated

#ifndef STUB_Entity_destroy
//#define STUB_Entity_destroy
  void Entity::destroy()
  {
    
  }
#endif //STUB_Entity_destroy

#ifndef STUB_Entity_getDomain
//#define STUB_Entity_getDomain
  Domain* Entity::getDomain()
  {
    return nullptr;
  }
#endif //STUB_Entity_getDomain

#ifndef STUB_Entity_getDomain
//#define STUB_Entity_getDomain
  const Domain* Entity::getDomain() const
  {
    return nullptr;
  }
#endif //STUB_Entity_getDomain

#ifndef STUB_Entity_sendWorld
//#define STUB_Entity_sendWorld
  void Entity::sendWorld(const Operation & op)
  {
    
  }
#endif //STUB_Entity_sendWorld

#ifndef STUB_Entity_addListener
//#define STUB_Entity_addListener
  void Entity::addListener(OperationsListener* listener)
  {
    
  }
#endif //STUB_Entity_addListener

#ifndef STUB_Entity_removeListener
//#define STUB_Entity_removeListener
  void Entity::removeListener(OperationsListener* listener)
  {
    
  }
#endif //STUB_Entity_removeListener


#endif