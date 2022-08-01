#include <stdio.h>
#include <locale.h>

int br ()
{
    char br[10] = "Brasil \t";
    char ru[10] = "Russia \t";
    printf ("%s", br);
    printf ("%s", ru);
}

int ic()
{
    char in[10] = "India \t";
    char ch[10] = "China \t";
    printf ("%s", in);
    printf ("%s", ch);
    
}

int main()
{
    br();
    ic();
    printf ("\n");
    ic();
    printf ("\n");
    br();
}