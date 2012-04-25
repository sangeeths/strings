#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

int strlen(char *s)
{
	char *p = s;
	while(*p)
		p++;
	return p-s;
}

char * strcpy(char *to, char *from)
{
	char *s = to;
	while (*to++ = *from++);
	return s;
}

char * strcat(char *s1, char *s2)
{
	char *s = s1;
	int i=0, j=0;

	while (s1[i]) i++;
	while (s2[j]) {
		s1[i] = s2[j];
		i++; j++;
	}
	s1[i] = '\0';

	return s; 
}

int strstr(char *s1, char *s2)
{	
	int i=0, j=0, match;
	int l1 = strlen(s1), l2 = strlen(s2);
	
	for (i=0; i<l1; i++) {
		j = 0;
		match = 1;
		while (s2[j]) {
			if (s1[i+j] != s2[j])
				match = 0;
			j++;
		}
		if (match)	return YES;
	}

	return NO;
}


int rotation_string(char *s1, char *s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);

	//printf("%d %s l1 = %d , l2 = %d \n", __LINE__, __FUNCTION__, l1, l2);

	if (s1 == NULL && s1 == NULL) return YES;
	if (l1 != l2) return NO;
	
	char *n = (char *) malloc(sizeof(char) * l1 * 2 + 1);
	strcpy(n, s1);
	//printf("%d %s n=%s \n", __LINE__, __FUNCTION__, n);
	strcat(n, s1);
	//printf("%d %s n=%s \n", __LINE__, __FUNCTION__, n);

	return strstr(n, s2);
}

int main()
{
	char s1[] = "thisisastringtobetested";
	char s2[] = "ringtobetestedthisisast";

	printf("%s : %s - %s\n", s1, s2, rotation_string(s1, s2)?"Yes":"No");
	
	return 0;
}
