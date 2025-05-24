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
	title("ft_memcmp\t: ")

	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	
	// Test 1: Identical memory blocks
	/* 1 */ check(!ft_memcmp(s, sCpy, 4)); showLeaks();
	
	// Test 2: Zero-length comparison (should always return 0)
	/* 2 */ check(!ft_memcmp(s, s2, 0)); showLeaks();
	
	// Test 3: First byte differs, s > s2
	/* 3 */ check(ft_memcmp(s, s2, 1) > 0); showLeaks();
	
	// Test 4: First byte differs, s2 < s
	/* 4 */ check(ft_memcmp(s2, s, 1) < 0); showLeaks();
	
	// Test 5: Third byte differs
	/* 5 */ check(ft_memcmp(s2, s3, 4) != 0); showLeaks();
	
	// Test 6: Compare strings with null terminators in different positions
	char str1[] = "test\0abc";
	char str2[] = "test\0def";
	/* 6 */ check(!ft_memcmp(str1, str2, 5)); showLeaks(); // Should be equal (up to null term)
	/* 7 */ check(ft_memcmp(str1, str2, 8) != 0); showLeaks(); // Should be different (after null)
	
	// Test 8: Compare memory blocks with embedded zeros
	unsigned char block1[] = {1, 0, 3, 0, 5};
	unsigned char block2[] = {1, 0, 3, 0, 6};
	/* 8 */ check(!ft_memcmp(block1, block2, 4)); showLeaks(); // Equal up to 4 bytes
	/* 9 */ check(ft_memcmp(block1, block2, 5) < 0); showLeaks(); // 5 < 6 in 5th position
	
	// Test 10: Compare with extended ASCII values
	unsigned char ext1[] = {253, 254, 255};
	unsigned char ext2[] = {253, 254, 250};
	/* 10 */ check(ft_memcmp(ext1, ext2, 3) > 0); showLeaks(); // 255 > 250
	
	// Test 11: Comparing with negative values
	char neg1[] = {-5, -6, -7};
	char neg2[] = {-5, -6, -8};
	/* 11 */ check(ft_memcmp(neg1, neg2, 3) > 0); showLeaks(); // -7 > -8
	
	// Test 12: Comparing identical addresses
	/* 12 */ check(!ft_memcmp(s, s, 4)); showLeaks(); // Same memory location
	
	// Test 13: Compare with a single byte difference at the end
	char end1[] = {1, 2, 3, 4, 5};
	char end2[] = {1, 2, 3, 4, 6};
	/* 13 */ check(ft_memcmp(end1, end2, 5) < 0); showLeaks(); // 5 < 6
	
	// Test 14: Compare with a difference only after size limit
	char beyond1[] = {1, 2, 3, 4, 5};
	char beyond2[] = {1, 2, 3, 4, 6};
	/* 14 */ check(!ft_memcmp(beyond1, beyond2, 4)); showLeaks(); // Equal up to 4 bytes
	
	write(1, "\n", 1);
	return (0);
}