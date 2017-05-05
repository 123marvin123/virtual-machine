//
// Created by Marvin Haschker on 05.05.17.
//

#ifndef VM_INSTRUCTIONS_H
#define VM_INSTRUCTIONS_H

#include <stdlib.h>
#include "stack.h"
#include <stdio.h>
#include "utils.h"

typedef uint8_t* (*instruction)(uint8_t *, STACK *);

uint8_t *op_nop(uint8_t *ip, STACK *s);
uint8_t *op_push_char(uint8_t *ip, STACK *s);
uint8_t *op_emit(uint8_t *ip, STACK *s);
uint8_t *op_push_int(uint8_t *ip, STACK *s);
uint8_t *op_add(uint8_t *ip, STACK *s);
uint8_t *op_mul(uint8_t *ip, STACK *s);

enum {
    OPCODE_ADD = 'a',
    OPCODE_MUL = 'm',
    OPCODE_PUSH_INT = 'p',
    OPCODE_PUSH_CHAR = 'c',
    OPCODE_HALT = 'h',
    OPCODE_EMIT = 'e'
};

typedef struct OPCODE_t {
    uint8_t opcode;
    instruction instr;
} OPCODE;

OPCODE operations[5];

#endif //VM_INSTRUCTIONS_H
