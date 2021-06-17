#include <stdio.h>
int main()
{
	void copy_string(char*, char*);
	char a[] = "I am a teacher.";
	char b[] = "You are a student.";
	printf("string_1: %s \nstring_2: %s \n", a, b);
	printf("copy string a to string b: \n");
	copy_string(a, b);
	printf("string_1: %s \nstring_2: %s \n", a, b);
	return 0;
}
void copy_string(char* from, char* to)
{
	while (*to++=*from++);
}