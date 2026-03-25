#ifndef TRANSACTION_STREAM_H
#define TRANSACTION_STREAM_H

#include "DataStream.h"

typedef struct {
    int operations;
    int buy;
    int sell;
    int net_flow;
} TransactionStats;

DataStream* create_transaction_stream(const char* stream_id);

#endif
