// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubCommHttpClient_custom.h file.

#ifndef STUB_SERVER_COMMHTTPCLIENT_H
#define STUB_SERVER_COMMHTTPCLIENT_H

#include "server/CommHttpClient.h"
#include "stubCommHttpClient_custom.h"

#ifndef STUB_CommHttpClient_do_read
//#define STUB_CommHttpClient_do_read
  void CommHttpClient::do_read()
  {
    
  }
#endif //STUB_CommHttpClient_do_read

#ifndef STUB_CommHttpClient_read
//#define STUB_CommHttpClient_read
  bool CommHttpClient::read()
  {
    return false;
  }
#endif //STUB_CommHttpClient_read

#ifndef STUB_CommHttpClient_write
//#define STUB_CommHttpClient_write
  void CommHttpClient::write()
  {
    
  }
#endif //STUB_CommHttpClient_write

#ifndef STUB_CommHttpClient_CommHttpClient
//#define STUB_CommHttpClient_CommHttpClient
   CommHttpClient::CommHttpClient(const std::string & name, boost::asio::io_context& io_context)
    : std::enable_shared_from_this(name, io_context)
  {
    
  }
#endif //STUB_CommHttpClient_CommHttpClient

#ifndef STUB_CommHttpClient_CommHttpClient_DTOR
//#define STUB_CommHttpClient_CommHttpClient_DTOR
   CommHttpClient::~CommHttpClient()
  {
    
  }
#endif //STUB_CommHttpClient_CommHttpClient_DTOR

#ifndef STUB_CommHttpClient_serveRequest
//#define STUB_CommHttpClient_serveRequest
  void CommHttpClient::serveRequest()
  {
    
  }
#endif //STUB_CommHttpClient_serveRequest

#ifndef STUB_CommHttpClient_getSocket
//#define STUB_CommHttpClient_getSocket
  boost::asio::ip::tcp::socket& CommHttpClient::getSocket()
  {
    return *static_cast<boost::asio::ip::tcp::socket*>(nullptr);
  }
#endif //STUB_CommHttpClient_getSocket


#endif