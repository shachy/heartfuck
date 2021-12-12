#include "compiler.cpp"
#include <stdlib.h>
#include <string.h>
#include <fstream>

int main(int argc, char **argv) {
    std::ifstream f;
    char program[30000];
    if(argc < 2) {
        printf("Usage: program.bf");
        exit(1);
    }
    f.open(argv[1]);
    if(!f) {
        printf("An error happened while trying to read the file specified");
        exit(1);
    }
    if(f.is_open()) {
        for(int i = 0; i < 30000; i++) {
            f >> program[i];
        }
    }
    comp(program);
    return 0;
}