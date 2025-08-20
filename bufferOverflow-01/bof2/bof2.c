// bof2.c - Buffer Overflow Level 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void win() {
    system("/bin/sh");
}

void vuln() {
    char buf[40];

    puts("Let's see if you're ready for round 2.");
    printf("Input: ");
    fgets(buf, 200, stdin);  // fgets used instead of gets
    printf("You typed: %s\n", buf);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    puts("Bye.");
    return 0;
}
