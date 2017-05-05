//
// Created by Marvin Haschker on 05.05.17.
//

#ifndef VM_STACK_H
#define VM_STACK_H

#include "object.h"

typedef struct STACK_t {
    int     top;
    int     size;
    OBJECT *stack;
} STACK;

STACK stack_new(int size);
int stack_push(STACK *s, OBJECT o);
OBJECT stack_pop(STACK *s);
OBJECT stack_peek(STACK *s);

#endif //VM_STACK_H
