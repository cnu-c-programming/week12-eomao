#include <stdio.h>

int main(int argc, const char* argv[]) {
    
    if (argc < 2)
        return 0;
    
    const char* filename = argv[1];
    char buffer[10] = {0};

    FILE* fp = fopen(filename, "r");

    if (fp == NULL)
        return 0;

    fgets(buffer, sizeof(buffer), fp);

    printf("%s", buffer);

    fclose(fp);

    return 0;
}
