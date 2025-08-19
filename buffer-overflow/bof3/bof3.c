// bof3.c - Buffer Overflow Level 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void win(int x) {
    if (x == 0xdeadbeef) {
        printf("Congrats! You triggered win() with the right argument.\n");
        system("/bin/sh");
    } else {
        printf("win() called, but wrong argument: 0x%x\n", x);
    }
}

void vuln() {
    char buf[32];

    puts("Level 3: Let's see if you can pass the right value.");
    printf("Input: ");
    fgets(buf, 128, stdin);
    printf("You said: %s\n", buf);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    puts("Exiting normally...");
    return 0;
}
