#include <stdio.h>
#include <stdlib.h>

// NOTE-1: copies the content from 'from' variable to
// 'to' variable
//
// NOTE-2: it is assumed that the 'to' variable is 
// always big enough to hold the contents from the 
// 'from' variable
//
// NOTE-3: strcpy returns the pointer (char *) to the 
// destination string (to)


// array version
char * strcpy1(char to[], char from[])
{
	int i=0;
	while(from[i]) {
		to[i] = from[i];
		i++;
	}	
	to[i] = '\0';
	return to;
}

// pointer version
char * strcpy2(char *to, char *from)
{
	/*
	int i=0;
	while (*from) {
		*(to+i) = *from;
		from++;
		i++;
	}
	return to;
	*/
	char *t = to;
	while (*to++ = *from++);
	return t;
}

int strlen(char *p)
{
	char *q = p;
	while (*p)
		p++;	
	return p - q;
}

int main()
{
	#define size 25
	char from[size] = "test string";
	char to[size] = ""; 

	char *fromp = "another string";
	char *top = NULL;
		
	top = (char *) malloc(sizeof(char) * strlen(fromp) + 1);

	printf("strcpy1(%s, %s) = ", to, from); 
	printf("%s\n", strcpy1(to, from));
	printf("strcpy1(%s, %s) = ", top, fromp); 
	printf("%s\n", strcpy1(top, fromp));

	free (top);
	
	// ------------------------------- //

	char from1[size] = "hello, test test";
	char to1[size] = "";

	fromp = "diff string";
	top = NULL;
		
	top = (char *) malloc(sizeof(char) * strlen(fromp) + 1);
	
	printf("strcpy2(%s, %s) = ", to1, from1); 
	printf("%s\n", strcpy2(to1, from1));
	printf("strcpy2(%s, %s) = ", top, fromp); 
	printf("%s\n", strcpy2(top, fromp));

	/*
	printf("strcpy2(%s, %s) = %s \n", to, from, strcpy2(to, from));
	printf("strcpy2(%s, %s) = %s \n", top, fromp, strcpy2(top, fromp));
	*/

	return 0;
}
