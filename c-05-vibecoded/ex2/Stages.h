#ifndef STAGES_H
#define STAGES_H

#include "ProcessingStage.h"

ProcessingStage* create_input_stage(void);
ProcessingStage* create_transform_stage(void);
ProcessingStage* create_output_stage(void);

#endif
