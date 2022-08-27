#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

int main(void)
{
    char abc[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', //
    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', //
    'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < sizeof(abc); i++){
        printf("%c", abc[i]);
    }
    return 0;
}
