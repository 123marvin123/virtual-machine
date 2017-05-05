//
// Created by Marvin Haschker on 05.05.17.
//

#include "utils.h"

uint8_t *next_operation_index(uint8_t *ip) {
    uint8_t* i = ip;
    while(*(i) != '\n') { i++; }
    return i + 1;
}

int find_opcode_index(uint8_t ip) {
    for(int i = 0; i < sizeof(operations) / sizeof(OPCODE); i++) {
        OPCODE opcode = operations[i];
        if(opcode.opcode == ip)
            return i;
    }
    return -1;
}
