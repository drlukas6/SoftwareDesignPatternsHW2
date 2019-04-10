//
// Created by Lukas Sestic on 2019-04-09.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

int gt_int(int const *lhs, int const *rhs) {
    return *lhs > *rhs ? 1 : 0;
}

int gt_char(char const *lhs, char const *rhs) {
    return *lhs > *rhs ? 1 : 0;
}

int gt_string(char const *lhs, char const *rhs) {
    const char **ia = (const char **)lhs;
    const char **ib = (const char **)rhs;
    return strcmp(*ia, *ib) > 0 ? 1 : 0;
}

const void* mymax(const void *base, size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *)) {

    void *max = base;

    for (int i = 0; i < nmemb; ++i) {
        if (compar(base + i*size, max)) {
            max = base + i*size;
        }
    }

    return max;
}

int main() {
    int intArray[] = {5, 2, 8, 2, 99, 44};
    const int *maxInt = mymax(intArray, 6, sizeof(int), gt_int);
    printf("Max INT is: %d\n", *maxInt);

    char charArray[] = {'J', 'K', 'L', 'Z', 'A'};
    const char *maxChar = mymax(charArray, 5, sizeof(char), gt_char);
    printf("Max CHAR is: %c\n", *maxChar);

    char* stringArray[] = {"Lukas", "Auto", "Njemacka", "Azerbejdzan", "A"};
    const char **maxString = (const char **)mymax(stringArray, 5, sizeof(char *), gt_string);
    printf("Max STRING: %s\n", *maxString);
    return 0;
}