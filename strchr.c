#include <stdio.h>

char * strchr(char *s, int c)
{
	while (*s) {
		if (*s == c)
			return s;
		s++;
	}

	return NULL;
}

int main()
{
	char a[] = "This is a test string";
	int c = 'a';

	printf("string: %s \nchar: %c \noutput: %s \n", a, c, strchr(a, c));
	
	return 0;
}
