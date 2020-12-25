//
// Created by Aurora on 2020/12/25.
//

void testGetsPuts() {
    char *line = malloc(200 * sizeof(char));
    FILE *c1 = fopen("./resource/c1.txt", "r");
    fgets(line, 200, c1);
    fputs(line, stdout);
    fgets(line, 200, c1);
    fputs(line, stdout);
    fputs("another line", stdout);
    printf("end");
}
