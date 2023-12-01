#include <stdio.h>

int main() {
    int var = 10;

    int* var_address = &var;

    printf("The content of \"var\" = %d\n", var);
    printf("The content \"var_address\" = %p\n", var_address);
    printf("The content of \"*var_address\" = %d", *var_address);

    return 0;
}