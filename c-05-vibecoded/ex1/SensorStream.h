#ifndef SENSOR_STREAM_H
#define SENSOR_STREAM_H

#include "DataStream.h"

typedef struct {
    int operations;
    char* temp;
    char* humidity;
    char* pressure;
    double avg_temp;
} SensorStats;

DataStream* create_sensor_stream(const char* stream_id);

#endif
