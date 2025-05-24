extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_memchr\t: ")
	
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	
	// Test 1: Size is 0, should return NULL
	/* 1 */ check(ft_memchr(s, 0, 0) == NULL); showLeaks();
	
	// Test 2: Find first byte
	/* 2 */ check(ft_memchr(s, 0, 1) == s); showLeaks();
	
	// Test 3: Find byte in the middle
	/* 3 */ check(ft_memchr(s, 2, 3) == s + 2); showLeaks();
	
	// Test 4: Byte not in range
	/* 4 */ check(ft_memchr(s, 6, 6) == NULL); showLeaks();
	
	// Test 5: Test with value > 255 (should be cast to unsigned char)
	/* 5 */ check(ft_memchr(s, 2 + 256, 3) == s + 2); showLeaks(); //Cast check
	
	// Test 6: Test with string data
	char str[] = "Hello, World!";
	/* 6 */ check(ft_memchr(str, 'W', 13) == str + 7); showLeaks();
	
	// Test 7: Character is present multiple times, should find first occurrence
	char multi[] = "abcdabcd";
	/* 7 */ check(ft_memchr(multi, 'a', 8) == multi); showLeaks();
	
	// Test 8: Find null terminator in a string
	/* 8 */ check(ft_memchr(str, '\0', 14) == str + 13); showLeaks();
	
	// Test 9: Searching for a character in an exact-sized buffer (no null term)
	char buf[5] = {'a', 'b', 'c', 'd', 'e'};
	/* 9 */ check(ft_memchr(buf, 'e', 5) == buf + 4); showLeaks();
	
	// Test 10: Character is at the end of searched region
	/* 10 */ check(ft_memchr(str, '!', 13) == str + 12); showLeaks();
	
	// Test 11: Character is just outside searched region
	/* 11 */ check(ft_memchr(str, '!', 12) == NULL); showLeaks();
	
	// Test 12: Searching for a negative value (should be converted to unsigned char)
	/* 12 */ check(ft_memchr(s, -1, 6) == NULL); showLeaks();
	
	// Test 13: Searching for extended ASCII value
	unsigned char ext[] = {253, 254, 255, 0};
	/* 13 */ check(ft_memchr(ext, 254, 4) == ext + 1); showLeaks();
	/* 14 */ check(ft_memchr(ext, 255, 4) == ext + 2); showLeaks();
	
	write(1, "\n", 1);
	return (0);
}