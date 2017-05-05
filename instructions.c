//
// Created by Marvin Haschker on 05.05.17.
//

#include "instructions.h"

uint8_t *op_nop(uint8_t *ip, STACK *s) {
    return next_operation_index(ip);
}

uint8_t *op_push_char(uint8_t *ip, STACK *s) {
    OBJECT o;
    o.type = 'c';
    o.u8 = *(ip + 2);
    stack_push(s, o);
    return next_operation_index(ip);
}

uint8_t *op_emit(uint8_t *ip, STACK *s) {
    OBJECT o = stack_pop(s);
    if(o.type == 'i') {
        printf("%i\n", o.i32);
    } else if(o.type == 'c') {
        putchar(o.u8);
    }
    return next_operation_index(ip);
}

uint8_t *op_push_int(uint8_t *ip, STACK *s) {
    OBJECT o;
    o.type = 'i';
    o.i32 = *(ip + 2);
    stack_push(s, o);
    return next_operation_index(ip);
}

uint8_t *op_add(uint8_t *ip, STACK *s) {
    int size = *(ip + 2) - '0';
    int result = 0;

    for(int i = 0; i < size; i++) {
        OBJECT o = stack_pop(s);
        if(o.type == 'i') {
            result += o.i8 - '0';
        }
    }

    OBJECT o;
    o.type = 'i';
    o.i32 = result;
    stack_push(s, o);
    return next_operation_index(ip);
}

uint8_t *next_operation_index(uint8_t *ip) {
    uint8_t* i = ip;
    while(*(i) != '\n') { i++; }
    return i + 1;
}
