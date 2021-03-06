// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubOperationsDispatcher_custom.h file.

#ifndef STUB_COMMON_OPERATIONSDISPATCHER_H
#define STUB_COMMON_OPERATIONSDISPATCHER_H

#include "common/OperationsDispatcher.h"
#include "stubOperationsDispatcher_custom.h"

#ifndef STUB_OpQueEntry_OpQueEntry
//#define STUB_OpQueEntry_OpQueEntry
  template <typename T>
   OpQueEntry<T>::OpQueEntry(Operation o, T& f)
  {
    
  }
#endif //STUB_OpQueEntry_OpQueEntry

#ifndef STUB_OpQueEntry_OpQueEntry
//#define STUB_OpQueEntry_OpQueEntry
  template <typename T>
   OpQueEntry<T>::OpQueEntry(const OpQueEntry& o)
  {
    
  }
#endif //STUB_OpQueEntry_OpQueEntry

#ifndef STUB_OpQueEntry_OpQueEntry
//#define STUB_OpQueEntry_OpQueEntry
  template <typename T>
   OpQueEntry<T>::OpQueEntry(OpQueEntry&& o)
  {
    
  }
#endif //STUB_OpQueEntry_OpQueEntry

#ifndef STUB_OpQueEntry_OpQueEntry_DTOR
//#define STUB_OpQueEntry_OpQueEntry_DTOR
  template <typename T>
   OpQueEntry<T>::~OpQueEntry()
  {
    
  }
#endif //STUB_OpQueEntry_OpQueEntry_DTOR


#ifndef STUB_OperationsHandler_idle
//#define STUB_OperationsHandler_idle
  bool OperationsHandler::idle(int numberOfOpsToProcess)
  {
    return false;
  }
#endif //STUB_OperationsHandler_idle

#ifndef STUB_OperationsHandler_timeUntilNextOp
//#define STUB_OperationsHandler_timeUntilNextOp
  std::chrono::microseconds OperationsHandler::timeUntilNextOp() const
  {
    return *static_cast<std::chrono::microseconds*>(nullptr);
  }
#endif //STUB_OperationsHandler_timeUntilNextOp

#ifndef STUB_OperationsHandler_isQueueDirty
//#define STUB_OperationsHandler_isQueueDirty
  bool OperationsHandler::isQueueDirty() const
  {
    return false;
  }
#endif //STUB_OperationsHandler_isQueueDirty

#ifndef STUB_OperationsHandler_markQueueAsClean
//#define STUB_OperationsHandler_markQueueAsClean
  void OperationsHandler::markQueueAsClean()
  {
    
  }
#endif //STUB_OperationsHandler_markQueueAsClean

#ifndef STUB_OperationsHandler_clearQueues
//#define STUB_OperationsHandler_clearQueues
  void OperationsHandler::clearQueues()
  {
    
  }
#endif //STUB_OperationsHandler_clearQueues

#ifndef STUB_OperationsHandler_getQueueSize
//#define STUB_OperationsHandler_getQueueSize
  size_t OperationsHandler::getQueueSize() const
  {
    return 0;
  }
#endif //STUB_OperationsHandler_getQueueSize


#ifndef STUB_OperationsDispatcher_OperationsDispatcher
//#define STUB_OperationsDispatcher_OperationsDispatcher
  template <typename T>
   OperationsDispatcher<T>::OperationsDispatcher(std::function<void(const Operation&, Ref<T>)> operationProcessor, std::function<double()> timeProviderFn)
    : OperationsHandler(operationProcessor, timeProviderFn)
  {
    
  }
#endif //STUB_OperationsDispatcher_OperationsDispatcher

#ifndef STUB_OperationsDispatcher_OperationsDispatcher_DTOR
//#define STUB_OperationsDispatcher_OperationsDispatcher_DTOR
  template <typename T>
   OperationsDispatcher<T>::~OperationsDispatcher()
  {
    
  }
#endif //STUB_OperationsDispatcher_OperationsDispatcher_DTOR

#ifndef STUB_OperationsDispatcher_idle
//#define STUB_OperationsDispatcher_idle
  template <typename T>
  bool OperationsDispatcher<T>::idle(int numberOfOpsToProcess)
  {
    return false;
  }
#endif //STUB_OperationsDispatcher_idle

#ifndef STUB_OperationsDispatcher_timeUntilNextOp
//#define STUB_OperationsDispatcher_timeUntilNextOp
  template <typename T>
  std::chrono::microseconds OperationsDispatcher<T>::timeUntilNextOp() const
  {
    return *static_cast<std::chrono::microseconds*>(nullptr);
  }
#endif //STUB_OperationsDispatcher_timeUntilNextOp

#ifndef STUB_OperationsDispatcher_isQueueDirty
//#define STUB_OperationsDispatcher_isQueueDirty
  template <typename T>
  bool OperationsDispatcher<T>::isQueueDirty() const
  {
    return false;
  }
#endif //STUB_OperationsDispatcher_isQueueDirty

#ifndef STUB_OperationsDispatcher_markQueueAsClean
//#define STUB_OperationsDispatcher_markQueueAsClean
  template <typename T>
  void OperationsDispatcher<T>::markQueueAsClean()
  {
    
  }
#endif //STUB_OperationsDispatcher_markQueueAsClean

#ifndef STUB_OperationsDispatcher_clearQueues
//#define STUB_OperationsDispatcher_clearQueues
  template <typename T>
  void OperationsDispatcher<T>::clearQueues()
  {
    
  }
#endif //STUB_OperationsDispatcher_clearQueues

#ifndef STUB_OperationsDispatcher_addOperationToQueue
//#define STUB_OperationsDispatcher_addOperationToQueue
  template <typename T>
  void OperationsDispatcher<T>::addOperationToQueue(Operation, Ref<T>)
  {
    
  }
#endif //STUB_OperationsDispatcher_addOperationToQueue

#ifndef STUB_OperationsDispatcher_getQueueSize
//#define STUB_OperationsDispatcher_getQueueSize
  template <typename T>
  size_t OperationsDispatcher<T>::getQueueSize() const
  {
    return 0;
  }
#endif //STUB_OperationsDispatcher_getQueueSize

#ifndef STUB_OperationsDispatcher_dispatchOperation
//#define STUB_OperationsDispatcher_dispatchOperation
  template <typename T>
  void OperationsDispatcher<T>::dispatchOperation(OpQueEntry<T>& opQueueEntry)
  {
    
  }
#endif //STUB_OperationsDispatcher_dispatchOperation

#ifndef STUB_OperationsDispatcher_getTime
//#define STUB_OperationsDispatcher_getTime
  template <typename T>
  double OperationsDispatcher<T>::getTime() const
  {
    return 0;
  }
#endif //STUB_OperationsDispatcher_getTime


#endif