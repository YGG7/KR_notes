//
// Created by Aurora on 2020/12/17.
//
#include "TestExternVarDef.c"

extern int varInt1;
extern double varArr[];

void testExternVar() {
    printf("varInt1: %d\n", varInt1);
    int size = sizeof(varArr)/sizeof(double);
    for (int i = 0; i<size; i++) {
        printf("varArr[%d]=%f\n", i, varArr[i]);
    }
}

