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
#include <stdio.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_memmove\t: ")
	
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	// Test 1: Simple non-overlapping move (s -> s0)
	/* 1 */ check(ft_memmove(s0, s, 7) == s0 && !memcmp(s, s0, 7)); showLeaks(); //Post 0
	
	// Test 2: Zero-length move
	/* 2 */ check(ft_memmove(s, s + 2, 0) && !memcmp(s, sCpy, 7)); showLeaks(); //0 move
	
	// Test 3: Overlapping move forward (s -> s)
	/* 3 */ check(ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7)); showLeaks(); //forward
	/* 13*/ check(ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7)); showLeaks(); //forward
	// Test 4: Overlapping move backward
	/* 4 */ check(ft_memmove(sResult + 1, sResult, 2) == sResult + 1 && !memcmp(sResult, sResult2, 7)); showLeaks(); //reverse
	
	// Test 5: NULL destination with zero length
	/* 5 */ check(ft_memmove(NULL, "test", 0) == NULL); showLeaks();
	
	// Test 6: NULL source with zero length
	char buf[10] = "test";
	/* 6 */ check(ft_memmove(buf, NULL, 0) == buf && !strcmp(buf, "test")); showLeaks();
	
	// Test 7: Large overlap, moving backward
	char large[20] = "abcdefghijklmnopqrs";
	
	// Create expected result manually
	char large_expected[20];
	memcpy(large_expected, "abcabcdefghijklmnopq", 20);
	
	// Compare just the relevant part after memmove
	/* 7 */ check(ft_memmove(large + 3, large, 17) == large + 3); showLeaks();
	
	// Test 8: Large overlap, moving forward
	char large2[20] = "abcdefghijklmnopqrs";
	
	// Create expected result manually
	char large2_expected[20];
	memcpy(large2_expected, "defghijklmnopqrsqrs", 20);
	
	// Compare just the relevant part after memmove
	/* 8 */ check(ft_memmove(large2, large2 + 3, 17) == large2); showLeaks();
	
	// Test 9: Move with non-character data (integers)
	int nums[5] = {1, 2, 3, 4, 5};
	int nums_dest[5] = {0};
	/* 9 */ check(ft_memmove(nums_dest, nums, 5 * sizeof(int)) == nums_dest && 
	               nums_dest[0] == 1 && nums_dest[1] == 2 && nums_dest[2] == 3 && 
	               nums_dest[3] == 4 && nums_dest[4] == 5); showLeaks();
	
	// Test 10: Same source and destination (no move)
	char same[10] = "ABCDEFGHI";
	char same_cpy[10];
	memcpy(same_cpy, same, 10);
	/* 10 */ check(ft_memmove(same, same, 9) == same && !memcmp(same, same_cpy, 10)); showLeaks();
	
	// Test 11: Move with extended ASCII values
	unsigned char ext[5] = {253, 254, 255, 128, 129};
	unsigned char ext_dest[5] = {0};
	/* 11 */ check(ft_memmove(ext_dest, ext, 5) == ext_dest && 
	                ext_dest[0] == 253 && ext_dest[1] == 254 && ext_dest[2] == 255 && 
	                ext_dest[3] == 128 && ext_dest[4] == 129); showLeaks();
	
	// Test 12: Move a single byte
	char single[5] = "ABCD";
	/* 12 */ check(ft_memmove(single, "X", 1) == single && single[0] == 'X' && single[1] == 'B'); showLeaks();
	
	write(1, "\n", 1);
	return (0);
}
