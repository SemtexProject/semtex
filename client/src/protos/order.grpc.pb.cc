// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: order.proto

#include "order.pb.h"
#include "order.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace exchange {

static const char* ExchangeService_method_names[] = {
  "/exchange.ExchangeService/SubmitOrder",
};

std::unique_ptr< ExchangeService::Stub> ExchangeService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ExchangeService::Stub> stub(new ExchangeService::Stub(channel, options));
  return stub;
}

ExchangeService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SubmitOrder_(ExchangeService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ExchangeService::Stub::SubmitOrder(::grpc::ClientContext* context, const ::exchange::Order& request, ::exchange::SubmitOrderResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::exchange::Order, ::exchange::SubmitOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SubmitOrder_, context, request, response);
}

void ExchangeService::Stub::async::SubmitOrder(::grpc::ClientContext* context, const ::exchange::Order* request, ::exchange::SubmitOrderResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::exchange::Order, ::exchange::SubmitOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SubmitOrder_, context, request, response, std::move(f));
}

void ExchangeService::Stub::async::SubmitOrder(::grpc::ClientContext* context, const ::exchange::Order* request, ::exchange::SubmitOrderResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SubmitOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::exchange::SubmitOrderResponse>* ExchangeService::Stub::PrepareAsyncSubmitOrderRaw(::grpc::ClientContext* context, const ::exchange::Order& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::exchange::SubmitOrderResponse, ::exchange::Order, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SubmitOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::exchange::SubmitOrderResponse>* ExchangeService::Stub::AsyncSubmitOrderRaw(::grpc::ClientContext* context, const ::exchange::Order& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSubmitOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

ExchangeService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ExchangeService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ExchangeService::Service, ::exchange::Order, ::exchange::SubmitOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ExchangeService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::exchange::Order* req,
             ::exchange::SubmitOrderResponse* resp) {
               return service->SubmitOrder(ctx, req, resp);
             }, this)));
}

ExchangeService::Service::~Service() {
}

::grpc::Status ExchangeService::Service::SubmitOrder(::grpc::ServerContext* context, const ::exchange::Order* request, ::exchange::SubmitOrderResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace exchange

