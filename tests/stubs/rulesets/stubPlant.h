// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubPlant_custom.h file.

#ifndef STUB_RULESETS_PLANT_H
#define STUB_RULESETS_PLANT_H

#include "rulesets/Plant.h"
#include "stubPlant_custom.h"

#ifndef STUB_Plant_handleFruiting
//#define STUB_Plant_handleFruiting
  void Plant::handleFruiting(OpVector & res, Property<int>& fruits_prop)
  {
    
  }
#endif //STUB_Plant_handleFruiting

#ifndef STUB_Plant_dropFruit
//#define STUB_Plant_dropFruit
  void Plant::dropFruit(OpVector & res, const std::string& fruit_name)
  {
    
  }
#endif //STUB_Plant_dropFruit

#ifndef STUB_Plant_scaleArea
//#define STUB_Plant_scaleArea
  void Plant::scaleArea()
  {
    
  }
#endif //STUB_Plant_scaleArea

#ifndef STUB_Plant_Plant
//#define STUB_Plant_Plant
   Plant::Plant(const std::string & id, long intId)
    : Thing(id, intId)
  {
    
  }
#endif //STUB_Plant_Plant

#ifndef STUB_Plant_NourishOperation
//#define STUB_Plant_NourishOperation
  void Plant::NourishOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Plant_NourishOperation

#ifndef STUB_Plant_TickOperation
//#define STUB_Plant_TickOperation
  void Plant::TickOperation(const Operation &, OpVector &)
  {
    
  }
#endif //STUB_Plant_TickOperation


#endif