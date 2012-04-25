#include <stdio.h>
#include <stdlib.h>

int strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return p-s;
}

char * strcpy (char *to, char *from)
{
	char *a = to;
	while (*to++ = *from++);
	return a;
}

int count_spaces(char *s)
{
	int count = 0;
	while (*s) {
		if (*s == ' ')
			count++;
		s++;
	}
	return count;
}

void replace_space_with_20(char *s)
{
	int len = strlen(s);
	int spaces = count_spaces(s);
	int newlen = len + (2*spaces);
	int i = 0, j = newlen-1;

	s = (char *) realloc(s, sizeof(char) * newlen);

	if (s == NULL) {
		printf("%d %s : unalbe to allocate memory \n", __LINE__, __FUNCTION__);
		return;
	}

	printf("len: %d  -  spaces: %d  -  newlen: %d \n", len, spaces, newlen);

	for (i=len-1; i>=0 ; i--) {
		if (s[i] == ' ') {
			s[j--] = '0';
			s[j--] = '2';
			s[j--] = '%';
		} else {
			s[j--] = s[i];
		}
	}

	s[newlen] = '\0';

	return;
}

int main()
{
	char *a = (char *) malloc (sizeof(int) * 500);
	strcpy(a, "-        if (len == -1 && errno == EAGAIN) { -            /* there is no natural reason for this to happen, -             * so we'll spin hard until we get everything just -             * to be on the safe side. */ -            if (offset > 0) -                continue; -        }");

	printf("Sample string:\n-%s-\n", a);
	replace_space_with_20(a);
	printf("\nFinal string:\n-%s-\n", a);


	return 0;
}

