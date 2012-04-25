#include <stdio.h>

#define YES 1
#define NO 0

int strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return p-s;
}

int contains_uinque_chars(char *s)
{
	int len = strlen(s);
	unsigned int flag = 0;
	int i;
	

	for (i=0; i<len ; i++) {
		if (flag & 1<<(s[i]-'a')) {
			printf("%d %c \n", i, s[i]);
			return NO;
		}
		flag = flag | 1 <<(s[i]-'a');
	}

	return YES;
}

int main()
{
	char a[] = "this is a sample string";
	
	printf("string: %s\n", a);
	printf("unique? : %s\n", contains_uinque_chars(a)?"Yes":"No");

	return 0;
}

