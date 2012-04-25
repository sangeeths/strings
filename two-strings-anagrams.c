#include <stdio.h>

#define YES 1
#define NO 	0

int strlen(char *a)
{
	char *p = a;
	while (*p)
		p++;
	return p-a;
}


void swap(char *a, char *b)
{
	int temp = *a;
	*a = *b; 
	*b = temp;
}

char * sort(char *s)
{
	int i, j, min;
	int len = strlen(s);

	for(i=0; i<len; i++) {
		min = i;
		j = i+1;
		while (j<len) {
			if (s[min] > s[j])
				min = j;
			j++;
		}
		if (min!= i) {
			swap(s+i, s+min);
		}
		//printf("%d : %s \n", i, s);
	}

	return s;
}

int strcmp(char *a, char *b)
{
	while (*a == *b) {
		if (*a == '\0') 
			return 0;
		a++; b++;
	}
	return *a-*b;
}	

int anagrams(char *a, char *b)
{
	if (!*a || !*b)
		return NO;

	if (strlen(a) != strlen(b))
		return NO;
	
	sort(a); sort(b);
	//printf("%s\n", sort(a));
	//printf("%s\n", sort(b));	
	
	if (strcmp(a, b) != 0)
		return NO;
	
	return YES;
}

int main()
{
	/*
	char a[] = "hydroxydeoxycorticosterones";
	char b[] = "hydroxydesoxycorticosterone";
	char c[] = "this";
	*/
	char a[] = "basiparachromatin";
	char b[] = "marsipobranchiata";
	char c[] = "this";
	
	printf("%s and %s are %sanagrams \n", a, b, anagrams(a,b)?"":"not ");
	printf("%s and %s are %sanagrams \n", b, c, anagrams(b,c)?"":"not ");
	
	return 0;
}
