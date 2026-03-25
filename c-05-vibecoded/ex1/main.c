#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SensorStream.h"
#include "TransactionStream.h"
#include "EventStream.h"
#include "StreamProcessor.h"

void test_data_stream(DataStream* stream, const char* type, void** data, size_t count, const char* stat1_name, const char* stat2_name) {
    char* res = process_batch(stream, data, count);
    printf("%s\n", res);
    free(res);

    size_t out_count = 0;
    void** filtered = filter_data(stream, data, count, NULL, &out_count);
    if (filtered) {
        printf("Filtered %zu items\n", out_count);
        free(filtered);
    }

    void* stats = get_stats(stream);
    if (strcmp(type, "Sensor") == 0) {
        SensorStats* s = (SensorStats*)stats;
        printf("Sensor analysis: %d reading processed, avg temp: %.1f°C\n\n", s->operations, s->avg_temp);
        free(s->temp); free(s->humidity); free(s->pressure);
    } else if (strcmp(type, "Transaction") == 0) {
        TransactionStats* s = (TransactionStats*)stats;
        printf("Transaction analysis: %d operations, net flow: %d units\n\n", s->operations, s->net_flow);
    } else if (strcmp(type, "Event") == 0) {
        EventStats* s = (EventStats*)stats;
        printf("Event analysis: %d events, error: %d detected\n\n", s->nbr_event, s->nbr_error);
    }
    free(stats);
}

int main(void) {
    printf("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM (C VERSION) ===\n\n");

    const char* sensor_data[] = {"temp:22.5", "humidity:65", "pressure:1013"};
    const char* trans_data[] = {"buy:100", "sell:150", "buy:75"};
    const char* event_data[] = {"login", "error", "logout"};

    printf("Initializing Sensor Stream...\n");
    DataStream* sensor = create_sensor_stream("SENSOR_001");
    test_data_stream(sensor, "Sensor", (void**)sensor_data, 3, "operations", "avg_temp");

    printf("Initializing Transaction Stream...\n");
    DataStream* trans = create_transaction_stream("TRANS_001");
    test_data_stream(trans, "Transaction", (void**)trans_data, 3, "operations", "net_flow");

    printf("Initializing Event Stream...\n");
    DataStream* event = create_event_stream("EVENT_001");
    test_data_stream(event, "Event", (void**)event_data, 3, "nbr_event", "nbr_error");

    StreamProcessor* sp = create_stream_processor();
    add_stream(sp, sensor);
    add_stream(sp, trans);
    add_stream(sp, event);

    void** batches[] = {(void**)sensor_data, (void**)trans_data, (void**)event_data};
    size_t counts[] = {3, 3, 3};

    process_unified(sp, batches, counts, 3, "High-priorty data only");

    destroy_processor(sp);
    return 0;
}
