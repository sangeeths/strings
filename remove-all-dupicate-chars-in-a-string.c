#include <stdio.h>

int strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return p-s;
}

char * remove_duplicate_char_in_a_string(char *s)
{	
	char * a = s;
	int len = strlen(s);
	int i, j, k;
	
	if (s == NULL)	return NULL;
	if (len < 2) 	return a;

	int tail = 1;
	for (i=1; i<len; i++) {
		for (j=0; j<tail ; j++) {
			if (s[i] == s[j]) break;
		}
		if (j==tail) {
			s[tail] = s[i];
			tail++;
		}
	}
	
	s[tail] = '\0';

	return a;
}

int main()
{	
	//char a[] = "this is a test string.. remove duplicate characters from this ... .";
	char a[] = "I am a super star";
	
	printf("original string: \n%s\n", a);
	remove_duplicate_char_in_a_string(a);
	printf("output string: \n%s\n", a);

	return 0;
}

