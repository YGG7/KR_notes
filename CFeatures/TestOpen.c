//
// Created by Aurora on 2020/12/26.
//
#include <sys/file.h>

void testOpen() {
    int fd_c1 = open("./resource/c1.txt", O_RDONLY, 0);
    int fd_c2 = open("./resource/c2.txt", O_RDONLY, 0);
    int fd_f1 = open("./resource/f1.txt", O_RDONLY, 0);
    int fd_f2 = open("./resource/f2.txt", O_RDONLY, 0);
    printf("%d %d %d %d\n", fd_c1, fd_c2, fd_f1, fd_f2);
    close(fd_c1);
    close(fd_c2);
    close(fd_f1);
    close(fd_f2);
}