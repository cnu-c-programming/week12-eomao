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

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        int number;
        char extra;

        if (sscanf(buffer, "%d %c", &number, &extra) == 1) {
            sum += number;
        } else {
            fprintf(stderr, "invalid input: %s", buffer);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
