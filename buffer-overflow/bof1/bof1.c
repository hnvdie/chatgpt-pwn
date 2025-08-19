// bof1.c - Basic Buffer Overflow Level 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void win() {
    printf("You called win()! But this isn't the flag ;)\n");
    exit(0);
}

void vuln() {
    char buf[32];

    printf("Input: ");
    gets(buf);  // vulnerable function
    printf("You entered: %s\n", buf);
}

int main() {
    vuln();
    printf("Done.\n");
    return 0;
}
