#include <node.h>
#include "nokia5110_kk1.h"

namespace nokia5110_kk1_binding {

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;


// lcd contrast
//may be need modify to fit your screen!  normal: 30- 90 ,default is:45 !!!maybe modify this value!
int contrast = 60;


void init(const FunctionCallbackInfo<Value>& args) {
  LcdInitialise();
  LcdClear();
  LcdString("1.Hello Test");
}

void setcontrast(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // Check the number of arguments passed.
  if (args.Length() < 1) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  // Check the argument types
  if (!args[0]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  //LCDsetContrast((uint8_t)args[0]->NumberValue());
}

void clear(const FunctionCallbackInfo<Value>& args) {
  LCDclear();
}

void drawstring(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // Check the number of arguments passed.
  if (args.Length() < 3) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  // Check the argument types
  if (!args[0]->IsNumber() || args[1]->IsNumber() || args[2]->IsString()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  LCDdrawstring_P((args.Length() > 0) ? *v8::String::Utf8Value(args[0]->ToString()) : "");
}


void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "init", init);
  NODE_SET_METHOD(exports, "setcontrast", setcontrast);
  NODE_SET_METHOD(exports, "clear", clear);
  NODE_SET_METHOD(exports, "drawstring", drawstring);
}

NODE_MODULE(nokia5110_kk1_binding, Initialize)


}
