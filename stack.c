//
// Created by Marvin Haschker on 05.05.17.
//

#include "stack.h"

STACK stack_new(int size) {
    STACK s;
    s.top = 0;
    s.size = size;
    s.stack = (OBJECT *) malloc(sizeof(OBJECT) * size);
    return s;
}

int stack_push(STACK *s, OBJECT o) {
    s->stack[s->top++] = o;
    return s->top;
}

OBJECT stack_pop(STACK *s) {
    return s->stack[--(s->top)];
}

OBJECT stack_peek(STACK *s) {
    return s->stack[s->top - 1];
}