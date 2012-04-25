#include <stdio.h>

int strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return p-s;
}

void replace_multiple_space_with_one(char *s)
{
	int i=0, j=0;
	int count = 0;
	int len = strlen(s);

	// special case: if there is only one tab present, then replace 
	// that with a single blankspace
	if (len == 1 && s[0] == '\t') {
		s[0] = ' ';
		return;
	}

	// if length of the incoming string is < 2, then return
	if (len < 2)
		return;

	for (i=0 ; s[i] != '\0' ; i++) {
		if (s[i] == ' ' || s[i] == '\t') {
			count++;
		} 

		if (s[i] != ' ' && s[i] != '\t') {	
			if (count >= 1) {
				count = 0;
				s[j++] = ' ';
			}
			s[j++] = s[i];
		}
	}
	s[j] = '\0';

	return;
}

int main()
{
	//char a[] = "   			This   i s   a   s a		 m p l e   s t 	r i n g   w i t h   s o m e   s p a c e s      "; 
	//char a[] = "	";
	char a[] = "a a a a aaaa      a a a a a a      a das d asd sad  			";

	printf("sample string: \n-%s- \n", a);
	replace_multiple_space_with_one(a);
	printf("final string: \n-%s- \n", a);

	return 0;
}
