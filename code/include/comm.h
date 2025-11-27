#ifndef COMM_H
#define COMM_H

/**
 *  COMMANDS
 *  Every multi-byte data is big-endian
 *
 *  WRITE_SETTINGS
 *  | 1 byte | 1 byte |   4 byte  | 4 byte | 4 byte |  1 byte  |
 *  | 0xC0   | en_vx  | target_vx | min_vx | max_vx | checksum |
 *
 *  WRITE_SETTINGS_SUCCESS_RESPONSE
 *  | 1 byte | 1 byte |
 *  | 0xC0   | 0x01   |
 *
 *  WRITE_SETTINGS_FAIL_RESPONSE
 *  | 1 byte | 1 byte |
 *  | 0xC0   | 0x00   |
 *
 *  READ_SETTINGS
 *  | 1 byte |
 *  | 0xC1   |
 *
 *  READ_SETTINGS_RESPONSE
 *  | 1 byte | 1 byte |   4 byte  | 4 byte | 4 byte |  1 byte  |
 *  | 0xC1   | en_vx  | target_vx | min_vx | max_vx | checksum |
 *
 */

#include "utils.h"

void comm_init();

#endif