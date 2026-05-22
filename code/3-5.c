#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    char buffer[64];

    while (fscanf(fp, "%63s", buffer) == 1) {
        char* endptr;
        int num = (int)strtol(buffer, &endptr, 10);

        if (*endptr == '\0') {
            sum += num;
        } else {
            fprintf(stderr, "invalid input %s\n", buffer);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
