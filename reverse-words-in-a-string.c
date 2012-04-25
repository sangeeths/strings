#include <stdio.h>

/*

firstly, reverse the entire string
then traverse the reversed string from the begining to the end
	if there is a space then
		swap (from word begining to word end)
		reset the offset of word begin and end
*/


void swap(char *a, char *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return p-s;
}

char * strrev(char *begin, char *end)
{
	char * s = begin;
	
	while (begin <= end) {
		swap (begin, end);
		begin++; end--;
	}		

	return s;
}

void reverse_words_in_a_string(char *s)
{
	int len = strlen(s);
	char * begin, * end;

	strrev(s, s+len-1);

	begin = s;	
	while(*s) {
		if (*s == ' ') {
			end = s-1;
			strrev(begin, end);
			begin = s+1;
		}
		s++;
	}	
	
	strrev(begin, s-1);
	return;		
}


int main()
{
	char a[] = "this is a sample string that   will be reversed";
	
	printf("Sample String: \n%s\n\n", a);
	reverse_words_in_a_string(a);
	printf("Final String: \n%s\n", a);

	return 0;
}


