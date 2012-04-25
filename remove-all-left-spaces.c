#include <stdio.h>


/*

	find the first non blankspace, say X
	from x -> till end,
		copy the contents to the beginning of the array..
	a[0] = a[x]
	a[1] = a[x+1]
	..
	.
	a[n] = a[x+n] (which is the last element of the string)
	
*/

void remove_all_left_spaces(char *s)
{
	int i=0, j=0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;

	while (s[j] = s[i]) {
		i++; j++;
	}

	return;
}

int main()
{
	char a[] = "        			   T h i s   i s   a   s a m p l e   s t r i n g   w i t h   s o m e   s p a c e s"; 

	printf("sample string: \n-%s- \n", a);
	remove_all_left_spaces(a);
	printf("final string: \n-%s- \n", a);

	return 0;
}
