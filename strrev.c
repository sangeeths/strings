#include <stdio.h>
#include <stdlib.h>

int strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return p - s;
}

char * strcpy(char to[], char from[])
{
	char * t = to;
	(*to++ = *from++);
	return t;
}


// array version
char * strrev1(char a[])
{
	int i, j;
	char temp;
	
	for (i=0, j=strlen(a)-1 ; i<j ; i++, j--) {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;	
	}	

	/*
	int len = strlen(a);
	for (i=0 ; i<len/2 ; i++) {
		temp = a[i];
		a[i] = a[len-i-1];
		a[len-i-1] = temp;
	}
	*/

	return a;
}

char * strrev2(char *p)
{
	/*
	// string reverse using two pointers
	char *s = p;
	char *r = p+strlen(p)-1;
	char temp;

	while(p < r) {
		temp = *p;
		*p = *r;
		*r = temp;
		p++; r--;
	}

	return s;
	*/
	

	// how to string reverse using one pointer

	int len = strlen(p)-1;
	int i;
	char temp;
	
	for (i=0; i<len/2; i++)
	{
		temp = *(p+i);
		*(p+i) = *(p+len-i);
		*(p+len-i) = temp;
	}	
	return p;
}

/*
extra space of O(n) is required
*/
void reverse(char *s, char *n, int nindex)
{
	if (*s == '\0') {
		return; 
	}
	
	reverse (s+1, n, nindex-1);
	*(n+nindex) = *s;

	return;
}

char * strrev3(char * s)
{
	int len = strlen(s);
	char *p = (char *) malloc(sizeof(char) * len + 1);
	*(p+len) = '\0';
	reverse(s, p, len-1);
	//free(p);
	return p;
}


/*
No extra space, done inplace with two variables
to store the start and the end
*/
void reverse1(char *a, int start, int end)
{
	if (start >= end)
		return;

	reverse1(a, start+1, end-1);

	char temp = a[start];
	a[start] = a[end];
	a[end] = temp;
	
	return;
}

char * strrev4(char *s)
{
	reverse1(s, 0, strlen(s)-1);
	return s;
}


int main()
{
	char s[] = "test string";	
	char *p = NULL;
	
	p = (char *) malloc(sizeof(char) * strlen("some string") + 1);
	strcpy(p, "some string");

	printf("strrev1(%s) = ", s);
	printf("%s \n", strrev1(s));
	printf("strrev1(%s) = ", p);
	printf("%s \n", strrev1(p));
	
	free(p);

	// ---------------------------------- //

	char s1[] = "random dandom";	
	p = NULL;
	
	p = (char *) malloc(sizeof(char) * strlen("what is this?") + 1);
	strcpy(p, "what is this?");

	printf("strrev2(%s) = ", s1);
	printf("%s \n", strrev2(s1));
	printf("strrev2(%s) = ", p);
	printf("%s \n", strrev2(p));

	free(p);

	// ----------------------------------- //

	char s2[] = "okie dokie";	
	p = NULL;
	
	p = (char *) malloc(sizeof(char) * strlen("i don't know!!") + 1);
	strcpy(p, "i don't know!!");

	printf("strrev3(%s) = ", s2);
	printf("%s \n", strrev3(s2));

	printf("strrev3(%s) = ", p);
	printf("%s \n", strrev3(p));

	free(p);

	// ----------------------------------- //

	char s3[] = "oh! .. come on!!";	
	p = NULL;
	
	p = (char *) malloc(sizeof(char) * strlen("yet another version of strrev") + 1);
	strcpy(p, "yet another version of strrev");

	printf("strrev4(%s) = ", s3);
	printf("%s \n", strrev4(s3));

	printf("strrev4(%s) = ", p);
	printf("%s \n", strrev4(p));

	free(p);


	return 0;
}
