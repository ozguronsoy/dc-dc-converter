#include "comm.h"

uint8_t calc_checksum(const uint8_t* begin, const uint8_t* end)
{
    if (begin >= end)
        return 0;

    uint8_t checksum = 0;
    for (const uint8_t* it = begin; it != end; ++it)
        checksum += *it;
    return checksum;
}

void comm_init()
{
    // TODO
}