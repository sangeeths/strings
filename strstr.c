#include <stdio.h>

char * strstr(char *a, char *b)
{
    int i=0, j=0, match=0;


    while (a[i]) {

        j = 0;
        match = 1;
        while (b[j]) {
            if (a[i+j] != b[j]) {
                match = 0;
                break;
            }
            j++;
        }

        if (match)
            return a+i;

        i++;
    }

    return NULL;
}

int main()
{
    char a[100] = "this is a test string.. come on.. how many programs?";
    char *b = "many";
    char *p = strstr(a, b);
    
    printf("string: \n %s \n\n", a);
    printf("search string: \n %s \n", b);
    
    printf("final string : %s \n", p);
    
    return 0;
}
