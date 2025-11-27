#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdint.h>

#define MAX_LOOP_ITER   ((uint32_t)1e6)

typedef struct
{
    bool enable_vx;
    float target_vx;
    float min_vx;
    float max_vx;
} settings_t;

const settings_t* utils_get_settings();
bool utils_set_settings(const settings_t* settings);

#endif