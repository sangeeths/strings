#include <stdio.h>

char * strcat1(char dest[], char src[])
{
    int i=0, j=0;

    while(dest[i] != '\0')
        i++;

    while(src[j] != '\0') {
        dest[i] = src[j];
        i++; j++;
    }
        
    dest[i] = '\0';
    return dest;
}


char * strcat2(char * dest, const char * src)
{
    char * d = dest;

    while (*dest)
        dest++;
    
    while (*dest++ = *src++);
    
    return d;
}

int main()
{
    char s1[50] = "this is a test string ";
    char s2[10] = "something";

    printf("s1: (%s) - s2: (%s) \n", s1, s2);
    printf("strcat: (%s) \n", strcat1(s1, s2));

    // ---------------------------------------- //
    
    char a1[50] = "there is some or the ";
    char a2[20] = "other things.. :P";

    printf("s1: (%s) - s2: (%s) \n", a1, a2);
    printf("strcat: (%s) \n", strcat2(a1, a2));

    return 0;
}
