#include <stdio.h>

void squeez(char *s, int c)
{
	int i=0, j=0;
	
	while(s[i]) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
		i++;
	}
	s[j] = '\0';

	return;
}

int main()
{
	char s[] = "this is a test string.. hahaha... ";
	int c = 'a';
	
	printf("sample string: \n%s\n", s);
/*
	squeez(s, c);
	printf("final string (without %c): \n%s\n", c, s);

	c = '.';
	squeez(s, c);
	printf("final string (without %c): \n%s\n", c, s);

	c = 's';
	squeez(s, c);
	printf("final string (without %c): \n%s\n", c, s);
*/
	c = ' ';
	squeez(s, c);
	printf("final string (without %c): \n%s\n", c, s);

	return 0;
}
