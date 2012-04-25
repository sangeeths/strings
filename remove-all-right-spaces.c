#include <stdio.h>


/*

	find the end of the string and go to the last char
	from the last char to the first char,
		check whether its a blankspace.. if blankspace
			then set a[index] = '\0' and exit!

*/

int strlen(char *s)
{	
	char *p = s;
	while (*p)
		p++;
	return p-s;
}

void remove_all_right_spaces(char *s)
{
	int i = strlen(s) - 1;
	
	while (s[i] == ' ' || s[i] == '\t')
		s[i--] = '\0';

	return;
}

int main()
{
	char a[] = "           T h i s   i s   a   s a m p l e   s t r i n g   w i t h   s o m e   s p a c e s			  "; 

	printf("sample string: \n-%s- \n", a);
	remove_all_right_spaces(a);
	printf("final string: \n-%s- \n", a);

	return 0;
}
