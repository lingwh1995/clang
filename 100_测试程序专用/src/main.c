#include <stdio.h>
#include <string.h>

/**
 * 从尾到头在一个字符串中查找给定子串的第一个匹配之处
 */ 
char* my_strstr(const char* str, const char* substr)
{
    if(NULL == str || NULL == substr)
    {
        return NULL;
    }
	int m = strlen(str);
	int n = strlen(substr);
	for(int i=0; i < m - n + 1; i++)
	{
		int k = i;
		int j = 0;
		while(str[k] == substr[j] && j < n)
		{
			k++;
			j++;
		}
		if(j == n)
		{
			return (char*)str + i;
		}
	}
	return NULL;
}

void my_strstr_test()
{
	const char* str = "abccabcabbc";
	const char* substr = "abc";
	char* result = my_strstr(str,substr);
	printf("result = %s\n", result);
}

void strncpy_test()
{
   char src[40];
   char dest[12];
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "Hello, world!");
   strncpy(dest, src, 5);
   printf("最终的目标字符串： %s\n", dest);
}

int main()
{
	//my_strstr_test();
	strncpy_test();
	return 0;
}
