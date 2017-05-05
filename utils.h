//
// Created by Marvin Haschker on 05.05.17.
//

#ifndef VM_UTILS_H
#define VM_UTILS_H

#include <stdlib.h>
#include "instructions.h"

uint8_t *next_operation_index(uint8_t *ip);
int find_opcode_index(uint8_t ip);

#endif //VM_UTILS_H
