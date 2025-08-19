// bof4.c - Buffer Overflow Level 4 (32-bit, Stack Canary)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win() {
    printf("Congrats, you bypassed the canary!\n");
    system("/bin/sh");
}

void vuln() {
    char buf[64];
    puts("Level 4: Canary is enabled. Can you bypass it?");
    printf("Input: ");
    fgets(buf, 256, stdin);
    printf("You said: %s\n", buf);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    puts("Exiting...");
    return 0;
}
