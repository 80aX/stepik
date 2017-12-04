#include <stdio.h>
#include <string.h>

int stringStat(const char *string, size_t multiplier, int *count) {
    int res = 0;
    int str_length = strlen(string);

    res = str_length * multiplier;
    *count += 1;

    return res;
}

int main() {
    int c = 10;
    stringStat("Test", 4, &c);
    return 0;
}
