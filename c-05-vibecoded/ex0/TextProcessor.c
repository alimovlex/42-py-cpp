#include "TextProcessor.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct {
    DataProcessor base;
} TextProcessor;

static char* text_process(DataProcessor* self, void* data) {
    if (!data) return strdup("Type error: expected string");
    const char* str = (const char*)data;
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Processing data: %s", str);
    return strdup(buffer);
}

static bool text_validate(DataProcessor* self, void* data) {
    bool is_valid = (data != NULL);
    if (is_valid) {
        printf("Validation: Text data verified\n");
    }
    return is_valid;
}

static char* text_format_output(DataProcessor* self, const char* result) {
    if (!self->data) return strdup("It has to be a string!");
    const char* text = (const char*)self->data;
    size_t length = strlen(text);
    size_t words = 0;
    bool in_word = false;

    for (size_t i = 0; i < length; i++) {
        if (!isspace((unsigned char)text[i])) {
            if (!in_word) {
                words++;
                in_word = true;
            }
        } else {
            in_word = false;
        }
    }

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Output: Processed %zu characters, %zu words", length, words);
    return strdup(buffer);
}

static void text_destroy(DataProcessor* self) {
    free(self);
}

static const DataProcessorVTable text_vtable = {
    .process = text_process,
    .validate = text_validate,
    .format_output = text_format_output,
    .destroy = text_destroy
};

DataProcessor* create_text_processor(void) {
    TextProcessor* proc = malloc(sizeof(TextProcessor));
    if (!proc) return NULL;
    proc->base.vptr = &text_vtable;
    proc->base.data = NULL;
    proc->base.result = NULL;
    return (DataProcessor*)proc;
}
