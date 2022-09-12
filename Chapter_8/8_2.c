#include <stdio.h>
#include <stdlib.h>

/* I'm not sure have I done everything that task asked me to do. It's not clear task for me */

int main(void)
{
    int ch;
    int counter;
    
    while ((ch = getchar()) != EOF) {
        printf("  %c", ch);
        if (ch == 32) {
            printf(" \\n");
        }
        else if (ch == 10) {
            printf("  \\t");
        }
        else {
            printf(" %d", ch);
        }
		
        counter++;
		
        if (counter > 9){
            printf("\n");
            counter = 0;
        }
    }
    
    return 0;
}
