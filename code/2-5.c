#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp_src = fopen(argv[1], "r");
    FILE* fp_dst = fopen(argv[2], "w");

    if (fp_src == NULL)
        return 0;

    if (fp_dst == NULL) {
        fclose(fp_src);
        return 0;
    }

    int ch;

    while ((ch = fgetc(fp_src)) != EOF) {
        fputc(ch, fp_dst);
    }

    fclose(fp_src);
    fclose(fp_dst);

    return 0;
}
