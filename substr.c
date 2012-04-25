#include <stdio.h>
#include <stdlib.h>

int strlen(char *s)
{
    char *r = s;
    while(*s)
        s++;
    return s-r;
}

char * substr(char * a, size_t begin, size_t len)
{
    char *str = NULL;
    int l = strlen(a);
    int i=0;

    if (a == NULL || *a == '\0' || begin > l || begin+len > l)
        return NULL;

    str = (char *) malloc (sizeof(char) * len+1);    

    for (i=0 ; i<len; i++, begin++)
        str[i] = a[begin];
    
    str[i] = '\0';

    return str;
}

int main()
{
    char a[100] = "I'm a morden girl, give me some cookies.. thank you for doing so!! .. I love you soo much.. :)";
    int start = 0, length = 55; 
    char *str = NULL;

    printf("\n%s\n\n", a);
    
    str = substr(a, start, length);
    printf("%d to %d - %s \n", start, length, str);  
    
    free(str);

    return 0;
}
