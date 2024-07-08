#include <stdio.h>

typedef struct {
    char a;
    int b;
    short c;
} MyNewStruct;
 
int main() {
    MyNewStruct s;
    char *ptr = (char*) &s;

    s.a = 0x7F;    
    s.b = 0x11223344;
    s.c = 0x8001;   

    printf("%02X", (int)*(short*)(ptr + 5));
}
