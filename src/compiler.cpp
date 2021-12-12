#include <stdio.h>
#include <iostream>
#include <string.h>

void comp(char program[]) {
    char stack[30000];
    int idx = 0;
    int loop_idx = 0;
    for(int i = 0; i < strlen(program); i++) {
        switch(program[i]) {
            case '>': if(idx < 29999) { idx++; } break;
            case '<': if(idx > 0) { idx--; } break;
            case '+': stack[idx]++; break;
            case '-': if(stack[idx] > 0) { stack[idx]--; } break;
            case '*': stack[idx] += 10; break;
            case '/': if(stack[idx] - 10 > 0) { stack[idx] -= 10; } break;
            case '.': printf("%c", stack[idx]); break;
            case ',': std::cin >> stack[idx]; break;
            case '[': if(stack[idx] > 0) { loop_idx = i; } break;
            case ']': if(stack[idx] > 0) { i = loop_idx; } continue;
        }
    }
}