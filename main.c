#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "stack.h"
#include "utils.h"

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

    code = load_file(argv[1]);
    data = stack_new(1024);
    ip = code;

    while (*ip != 'h') {
        int idx = find_opcode_index(*ip);
        if(idx != -1) {
            OPCODE opcode = operations[idx];
            ip = opcode.instr(ip, &data);       // Execute instruction
        } else ip += 1;
    }

    return EXIT_SUCCESS;
}
