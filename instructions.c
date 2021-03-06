//
// Created by Marvin Haschker on 05.05.17.
//

#include "instructions.h"

OPCODE operations[] = {
        {OPCODE_MUL, op_mul},
        {OPCODE_PUSH_INT, op_push_int},
        {OPCODE_PUSH_CHAR, op_push_char},
        {OPCODE_EMIT, op_emit},
        {OPCODE_ADD, op_add}
};

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

uint8_t *op_mul(uint8_t *ip, STACK *s) {
    int size = *(ip + 2) - '0';
    int result = 0;

    for(int i = 0; i < size; i++) {
        OBJECT o = stack_pop(s);
        if(o.type == 'i') {
            int value = o.i8 - '0';
            if(i == 0) {
                result = value;
            } else {
                result *= value;
            }
        }
    }

    OBJECT o;
    o.type = 'i';
    o.i32 = result;
    stack_push(s, o);
    return next_operation_index(ip);
}
