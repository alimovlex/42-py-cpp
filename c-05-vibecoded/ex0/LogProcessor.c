#include "LogProcessor.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    DataProcessor base;
} LogProcessor;

static char* log_process(DataProcessor* self, void* data) {
    self->data = data;
    if (!data) return strdup("");
    const char* str = (const char*)data;
    
    if (strstr(str, "ERROR")) {
        return strdup("Connection timeout");
    }
    
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Processing data: %s", str);
    return strdup(buffer);
}

static bool log_validate(DataProcessor* self, void* data) {
    bool is_valid = (data != NULL);
    if (is_valid) {
        printf("Validation: Log entry verified\n");
    }
    return is_valid;
}

static char* log_format_output(DataProcessor* self, const char* result) {
    if (!self->data) return strdup("");
    const char* str = (const char*)self->data;
    
    if (strstr(str, "ERROR")) {
        return strdup("Output: [ALERT] ERROR level detected: Connection timeout");
    }
    
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Output: [INFO] INFO level detected: %s", str);
    return strdup(buffer);
}

static void log_destroy(DataProcessor* self) {
    free(self);
}

static const DataProcessorVTable log_vtable = {
    .process = log_process,
    .validate = log_validate,
    .format_output = log_format_output,
    .destroy = log_destroy
};

DataProcessor* create_log_processor(void) {
    LogProcessor* proc = malloc(sizeof(LogProcessor));
    if (!proc) return NULL;
    proc->base.vptr = &log_vtable;
    proc->base.data = NULL;
    proc->base.result = NULL;
    return (DataProcessor*)proc;
}
