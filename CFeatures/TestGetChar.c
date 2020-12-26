//
// Created by Aurora on 2020/12/26.
//

#undef getchar

#include "../Workspace/GetChar.c"

void echoInput() {
    int c;
    while ((c=getchar())!=EOF) {
        printf("%c",c);
    }
}
