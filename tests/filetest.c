#include <stdio.h>

int main() {
    FILE* f = fopen("test.txt", "r");
    if (!f) {
        printf("File not found.\n");
        return 1;
    }

    char buf[100];
    size_t n = fread(buf, 1, sizeof(buf), f);
    fclose(f);

    printf("Read %zu bytes: %.*s\n", n, (int)n, buf);
    return 0;
}
