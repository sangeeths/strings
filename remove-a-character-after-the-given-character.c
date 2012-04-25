#include <stdio.h>
#include <ctype.h>

void remove_non_alpha(char *s)
{ 
    int i=0, j=0;

    while(s[i]) {
        if (isalpha(s[i])) {
            s[j++] = s[i];
        }
        i++;
    }

    s[j] = '\0';

    return;
}

void remove_after(char *s, char c)
{
    int i=0, j=0;

    while(s[i]) {
        if (s[i] == c) {
            s[j++] = s[i++];
            if (s[i] == '\0') break;
        } else { 
            s[j++] = s[i];
        }
        i++;
    }

    s[j] = '\0';

    return;
}

int main()
{
    char a[] = "asdasda=1lsdn=sdf=3dfsdf=-sadf= adfgh=1fbfg=fgfg";
    char b[] = "asdasda=1lsdn=sdf=3dfsdf=-sadf= adfgh=1fbfg=fgfg";

    printf("sample string: %s \n", a);
    remove_after(a, '=');
    printf("final string : %s \n", a);

    printf("sample string: %s \n", b);
    remove_non_alpha(b);
    printf("final string : %s \n", b);

    return 0;
}
