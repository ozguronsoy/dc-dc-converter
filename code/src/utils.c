#include "utils.h"

volatile settings_t g_settings =
{
    .enable_vx = false,
    .target_vx = 0.0f,
    .min_vx = 0.0f,
    .max_vx = 0.0f
};

const settings_t* utils_get_settings()
{
    return &g_settings;
}

bool utils_set_settings(const settings_t* settings)
{
    if (settings->target_vx > settings->max_vx || settings->target_vx < settings->min_vx)
        return false;
    g_settings = *settings;
    return true;
}