#include <ruby.h>
#include <stdint.h>

extern int32_t blinking_light_demo();

VALUE tiktoken_module = Qnil;

VALUE tiktoken_blinking_light_demo(VALUE klass) {
    int32_t result = blinking_light_demo();
    return LONG2FIX(result);
}

void Init_tiktoken(void) {
    tiktoken_module = rb_define_module("Tiktoken");
    rb_define_module_function(tiktoken_module, "blinking_light_demo", tiktoken_blinking_light_demo, 0);

}
