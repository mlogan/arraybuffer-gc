
#include <node.h>
#include <v8.h>

namespace module {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Value;
using v8::ArrayBuffer;

void Recycle(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  if (not args[0]->IsArrayBuffer()) { return; }
  auto buffer = Local<ArrayBuffer>::Cast(args[0]);
  auto contents = buffer->Externalize();
  buffer->Neuter();

  auto newBuffer = ArrayBuffer::New(isolate, contents.Data(), contents.ByteLength(),
                                    v8::ArrayBufferCreationMode::kInternalized);
  args.GetReturnValue().Set(newBuffer);
}

void Create(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  auto newBuffer = ArrayBuffer::New(isolate, 1024 * 1024);
  args.GetReturnValue().Set(newBuffer);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "recycle", Recycle);
  NODE_SET_METHOD(exports, "create", Create);
}

}

NODE_MODULE(arraybufferrecycler, module::init)
