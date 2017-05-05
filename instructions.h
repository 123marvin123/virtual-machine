//
// Created by Marvin Haschker on 05.05.17.
//

#ifndef VM_INSTRUCTIONS_H
#define VM_INSTRUCTIONS_H

#include <stdlib.h>
#include "stack.h"
#include <stdio.h>

typedef uint8_t* (*instruction)(uint8_t *, STACK *);

uint8_t *op_nop(uint8_t *ip, STACK *s);
uint8_t *op_push_char(uint8_t *ip, STACK *s);
uint8_t *op_emit(uint8_t *ip, STACK *s);
uint8_t *op_push_int(uint8_t *ip, STACK *s);
uint8_t *op_add(uint8_t *ip, STACK *s);

uint8_t *next_operation_index(uint8_t *ip);

#endif //VM_INSTRUCTIONS_H
