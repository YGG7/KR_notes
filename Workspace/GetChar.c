//
// Created by Aurora on 2020/12/26.
//
#include "sys/syscall.h"

// a simple buffered getchar
// need to un-define getchar in stdio.h before using it
int getchar() {
    static char buf[BUFSIZ];
    static char *curr = buf;
    static int n = 0;

    // buffer is empty
    // file descriptors: 0 standard input; 1 standard output; 2 standard error
    if (n == 0) {
        n = read(0, buf, BUFSIZ * sizeof(char));
        curr = buf;
    }
    // if n still equals to 0
    // it means getchar reaches the end of standard input
    return (--n >= 0) ? (unsigned char) *curr++ : EOF;
}