#include "NumericProcessor.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    DataProcessor base;
} NumericProcessor;

static char* numeric_process(DataProcessor* self, void* data) {
    self->data = data;
    if (!data) return strdup("Bad any cast");
    IntVector* vec = (IntVector*)data;
    
    char buffer[512] = "Processing data: ";
    for (size_t i = 0; i < vec->count; i++) {
        char num[32];
        snprintf(num, sizeof(num), "%d%s", vec->values[i], (i == vec->count - 1 ? "" : " "));
        strcat(buffer, num);
    }
    return strdup(buffer);
}

static bool numeric_validate(DataProcessor* self, void* data) {
    bool is_valid = (data != NULL);
    if (is_valid) {
        printf("Validation: Numeric data verified\n");
    }
    return is_valid;
}

static char* numeric_format_output(DataProcessor* self, const char* result) {
    if (!self->data) return strdup("Invalid argument");
    IntVector* vec = (IntVector*)self->data;
    
    int sum = 0;
    for (size_t i = 0; i < vec->count; i++) {
        sum += vec->values[i];
    }
    int average = vec->count > 0 ? sum / (int)vec->count : 0;

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Output: Processed %zu numeric values, sum= %d, avg=%d", 
             vec->count, sum, average);
    return strdup(buffer);
}

static void numeric_destroy(DataProcessor* self) {
    free(self);
}

static const DataProcessorVTable numeric_vtable = {
    .process = numeric_process,
    .validate = numeric_validate,
    .format_output = numeric_format_output,
    .destroy = numeric_destroy
};

DataProcessor* create_numeric_processor(void) {
    NumericProcessor* proc = malloc(sizeof(NumericProcessor));
    if (!proc) return NULL;
    proc->base.vptr = &numeric_vtable;
    proc->base.data = NULL;
    proc->base.result = NULL;
    return (DataProcessor*)proc;
}
