#include <stdio.h>
#include <string.h>
#include "NumericProcessor.h"
#include "TextProcessor.h"
#include "LogProcessor.h"

void test_data_processor(DataProcessor* test, void* data) {
    bool val = validate(test, data);
    printf("%s\n", val ? "true" : "false");
    
    char* proc_res = process(test, data);
    printf("%s\n", proc_res);
    free(proc_res);
    
    test->data = data; // Simulating setting state like in C++
    char* fmt_res = format_output(test, "hello");
    printf("%s\n", fmt_res);
    free(fmt_res);
}

int main(void) {
    int list_vals[] = {1, 2, 3, 4, 5};
    IntVector list_data = {list_vals, 5};
    
    int new_list_vals[] = {1, 2, 3};
    IntVector new_list_data = {new_list_vals, 3};
    
    const char* str_data = "Hello Nexus World";
    const char* data_log = "INFO: System ready, ERROR";
    const char* new_str_data = "helloo Nexus";
    const char* new_data_log = "System ready";

    printf("=== CODE NEXUS - DATA PROCESSOR FOUNDATION (C VERSION) ===\n\n");

    printf("Initializing Numeric Processor...\n");
    DataProcessor* num_proc = create_numeric_processor();
    test_data_processor(num_proc, &list_data);
    destroy(num_proc);

    printf("\nInitializing Text Processor...\n");
    DataProcessor* txt_proc = create_text_processor();
    test_data_processor(txt_proc, (void*)str_data);
    destroy(txt_proc);

    printf("\nInitializing Log Processor...\n");
    DataProcessor* log_proc = create_log_processor();
    test_data_processor(log_proc, (void*)data_log);
    destroy(log_proc);

    printf("\n=== Polymorphic Processing Demo ===\n\n");
    printf("Processing multiple data types through same interface...\n");

    DataProcessor* processors[3];
    processors[0] = create_numeric_processor();
    processors[1] = create_text_processor();
    processors[2] = create_log_processor();

    void* test_data[3];
    test_data[0] = &new_list_data;
    test_data[1] = (void*)new_str_data;
    test_data[2] = (void*)new_data_log;

    for (int i = 0; i < 3; i++) {
        test_data_processor(processors[i], test_data[i]);
        destroy(processors[i]);
    }

    printf("\nFoundation system online. Nexus ready for advanced streams.\n");

    return 0;
}
