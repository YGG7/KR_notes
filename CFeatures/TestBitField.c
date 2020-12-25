//
// Created by Aurora on 2020/12/24.
//

typedef struct flags {
    unsigned int is_keyword:1;
    unsigned int is_extern:1;
    unsigned int is_static:1;
    unsigned int is_register:1;
    unsigned int direction:2;
} flags;

void testBitField() {
    int l_flags = sizeof(flags);
    printf("sizeof(l_flags): %d\n", l_flags);
}
