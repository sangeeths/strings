#include <stdio.h>

#define IN 1
#define OUT 0

int number_of_words(char *s)
{
	int words = 0;
	int state = OUT;
	
	while (*s) {
		if (*s == ' ' || *s == '\n' || *s == '\t') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			words++;
		}
		s++;
	}

	return words;
}

int main()
{
	char a[] = "this is a \n test 		s t r i 	n g to check the no of words";
	int words = number_of_words(a);

	printf("---%s--- has %d words\n", a, words);
	
	return 0;
}
