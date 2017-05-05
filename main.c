#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "stack.h"
#include "instructions.h"

typedef uint8_t* (*instruction)(uint8_t *, STACK *);

void usage() {
    printf("usage: vm <file>\n");
    exit(EXIT_FAILURE);
}

uint8_t *load_file(char *filename) {
    FILE *f;

    uint8_t *code = NULL;
    struct stat st;
    if((f = fopen(filename, "r"))) {
        fstat(fileno(f), &st);
        code = (uint8_t *) malloc((size_t) st.st_size);
        fread((void *) code, 1, (size_t) st.st_size, f);
    } else {
        printf("ERROR: cannot open file %s\n", filename);
        usage();
    }
    return code;
}

int main(int argc, char** argv) {
    if(argc != 2) {
        usage();
    }
    uint8_t *code;
    uint8_t *ip;
    STACK data;
    instruction ops[256];

    for(int i = 0;i < 12; i++) {
        ops[i] = op_nop;
    }

    ops['c'] = op_push_char;
    ops['e'] = op_emit;
    ops['p'] = op_push_int;
    ops['a'] = op_add;

    code = load_file(argv[1]);
    data = stack_new(1024);
    ip = code;

    while (*ip != 'h') {
        ip = ops[*ip](ip, &data);
    }

    return EXIT_SUCCESS;
}
