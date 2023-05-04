#include <ruby.h>
#include <stdint.h>

extern int32_t blinking_light_demo();
extern int32_t count_tokens(const char *, size_t);

VALUE tiktoken_module = Qnil;

VALUE tiktoken_blinking_light_demo(VALUE klass) {
    int32_t result = blinking_light_demo();
    return LONG2FIX(result);
}

// Returns a token count, or -1 on error.
VALUE tiktoken_count_tokens(VALUE klass, VALUE text) {
    // TODO: force UTF-8 encoding
    int32_t count = count_tokens(RSTRING_PTR(text), RSTRING_LEN(text));
    return LONG2FIX(count);
}

void Init_tiktoken(void) {
    tiktoken_module = rb_define_module("Tiktoken");
    rb_define_module_function(tiktoken_module, "blinking_light_demo", tiktoken_blinking_light_demo, 0);
    rb_define_module_function(tiktoken_module, "count_tokens", tiktoken_count_tokens, 1);
}
