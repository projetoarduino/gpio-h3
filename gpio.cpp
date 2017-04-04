//Cria string
//Local<String> str = args[0]->ToString();
/*
if(obj->IsArray()){

     v8::Local<v8::Array> arr= v8::Local<v8::Array>::Cast(args[0]);
     v8::String::Utf8Value key(arr->Get(0));
     v8::String::Utf8Value value(arr->Get(1));

 }
*/
#include <node.h>
#include <string.h>


extern "C"{
#include "gpio_lib.h"

}

using namespace v8;

void init(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    sunxi_gpio_init();    

    args.GetReturnValue().Set(SETUP_OK);
}

void pin(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  int32_t gpio = args[1]->ToInteger()->Value();
  int32_t result_pin = 0;

  v8::String::Utf8Value arg2(args[0]->ToString());
  
  if(strcmp(*arg2, "PA") == 0){
    result_pin =  SUNXI_GPA(gpio);
  }
  if(strcmp(*arg2, "PC") == 0){
    result_pin =  SUNXI_GPC(gpio);
  }  
	if(strcmp(*arg2, "PG") == 0){
    result_pin =  SUNXI_GPG(gpio);
  } 
  args.GetReturnValue().Set(result_pin);    
}

void dir(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  int32_t gpio = args[0]->ToInteger()->Value();
  
  v8::String::Utf8Value arg3(args[1]->ToString());

  if(strcmp(*arg3, "IN") == 0){
    sunxi_gpio_set_cfgpin(gpio, SUNXI_GPIO_INPUT);
  }
  if(strcmp(*arg3, "OUT") == 0){
    sunxi_gpio_set_cfgpin(gpio, SUNXI_GPIO_OUTPUT);
  }  
}

void write(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    int32_t gpio = args[0]->ToInteger()->Value();
    int32_t state = args[1]->ToInteger()->Value();
    
    
    sunxi_gpio_output(gpio, state);
    args.GetReturnValue().Set(state);  
}

void read(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    
    int32_t result;
    int32_t gpio = args[0]->ToInteger()->Value();

    result = sunxi_gpio_input(gpio);

    if(result == -1){
        isolate->ThrowException(
             Exception::TypeError(String::NewFromUtf8(isolate,"Reading pin failed"))
        );
    }

    args.GetReturnValue().Set(result);
}

void Init(Handle<Object> exports) {  
  NODE_SET_METHOD(exports, "init", init);
  NODE_SET_METHOD(exports, "write", write);
  NODE_SET_METHOD(exports, "read", read);
  NODE_SET_METHOD(exports, "pin", pin);
  NODE_SET_METHOD(exports, "dir", dir);
}

NODE_MODULE(addon, Init)
