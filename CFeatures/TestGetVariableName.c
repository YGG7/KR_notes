//
// Created by Aurora on 2020/12/19.
//
#define name(var) #var
void testGetVarName() {
    int thereIsATestName = 0;
    printf("%s", name(thereIsATestName));
}
