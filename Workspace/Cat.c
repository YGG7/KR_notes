//
// Created by Aurora on 2020/12/25.
//
#include <stdio.h>

void fileCopy(FILE *infp, FILE *outfp) {
    int c =0;
    // EOF equals to -1, \0 equals to 0
    while ((c=fgetc(infp))!=EOF) {
        fputc(c, outfp);
    }
}

int cat(int argc, char *argv[]) {
    FILE *fp;
    char *prog_name = argv[0];

    if (argc==1) {
        fileCopy(stdin, stdout);
    }
    else {
        int arg_index = 1;
        while (arg_index < argc) {
            if ((fp = fopen(argv[arg_index], "r"))!=NULL) {
                fileCopy(fp, stdout);
                fclose(fp);
                arg_index++;
            }
            else {
                fprintf(stderr, "%s: cannot open %s\n",prog_name, argv[arg_index]);
                return 0;
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog_name);
        return 0;
    }
    return 1;
}

