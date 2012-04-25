#include <stdio.h>


/*

	for each char in the string
		if the char is not blankspace then
			write that non-blankspace char to the destination array
		else (if the char is blankspace) then
			skip it!

*/

void remove_all_spaces(char *s)
{
	int i=0, j=0;

	/*
	for (i=0; s[i] != '\0' ; i++) {
		if (s[i] == ' ')
			continue;
		else
			s[j++] = s[i];
	}
	*/

	while(s[i]) {
		if (s[i] != ' ' && s[i] != '\t') {
			s[j++] = s[i];
		}
		i++;
	}

	s[j] = '\0';

	return;
}

int main()
{
	char a[] = "T h i s   i s   a   s a		 m p l e   s t 	r i n g   w i t h   s o m e   s p a c e s      "; 

	printf("sample string: \n-%s- \n", a);
	remove_all_spaces(a);
	printf("final string: \n-%s- \n", a);

	return 0;
}
