#include <node.h>
#include <time.h>
#include <nan.h>

using namespace v8;

void send_time_event(const Nan::FunctionCallbackInfo<Value>& args) {
  time_t rawtime;
  struct tm* timeinfo;
  char buffer[80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);

  Local<Object> event_obj = Nan::New<Object>();
  Nan::Set(event_obj, Nan::New("time").ToLocalChecked(), Nan::New(buffer).ToLocalChecked());

  Local<Value> argv[] = { event_obj };
  Nan::Callback(args[0].As<Function>()).Call(1, argv);
}


void init(Local<Object> exports) {
  Nan::Set(exports, Nan::New("sendTimeEvent").ToLocalChecked(),
           Nan::GetFunction(Nan::New<FunctionTemplate>(send_time_event)).ToLocalChecked());
}

NODE_MODULE(addon, init)
