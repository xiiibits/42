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
	title("ft_memcpy\t: ")
	
	char dest[100];
	
	// Test 1: Zero-length copy shouldn't change anything
	memset(dest, 'A', 100);
	ft_memcpy(dest, "coucou", 0);
	/* 1 */ check(dest[0] == 'A'); showLeaks();
	
	// Test 2: NULL source with zero length should work and return dest
	char *rtn = (char *)ft_memcpy(dest, NULL, 0);
	/* 2 */ check(rtn == dest && dest[0] == 'A'); showLeaks();
	
	// Test 3: Copy zeros
	char src[] = {0, 0};
	ft_memcpy(dest, src, 2);
	int i = 0;
	for (; i < 100 && dest[i] == 0; ++i)
		;
	/* 3 */ check(i == 2 && dest[2] == 'A'); showLeaks();
	
	// Test 4: Copy string and verify all bytes copied correctly
	memset(dest, 'A', 100);
	ft_memcpy(dest, "Hello, World!", 13);
	/* 4 */ check(memcmp(dest, "Hello, World!", 13) == 0 && dest[13] == 'A'); showLeaks();
	
	// Test 5: Copy with values > 127 (extended ASCII)
	unsigned char src2[5] = {253, 254, 255, 0, 1};
	memset(dest, 'A', 100);
	ft_memcpy(dest, src2, 5);
	/* 5 */ check((unsigned char)dest[0] == 253 && 
	              (unsigned char)dest[1] == 254 && 
	              (unsigned char)dest[2] == 255 && 
	              (unsigned char)dest[3] == 0 && 
	              (unsigned char)dest[4] == 1 && 
	              (unsigned char)dest[5] == 'A'); showLeaks();
	
	// Test 6: Copy in the middle of the buffer
	memset(dest, 'A', 100);
	ft_memcpy(dest + 10, "middle", 6);
	/* 6 */ check(dest[9] == 'A' && 
	              memcmp(dest + 10, "middle", 6) == 0 && 
	              dest[16] == 'A'); showLeaks();
	
	// Test 7: Test return value with normal copy
	memset(dest, 'A', 100);
	rtn = (char *)ft_memcpy(dest, "return", 6);
	/* 7 */ check(rtn == dest && memcmp(dest, "return", 6) == 0); showLeaks();
	
	// Test 8: Test with non-string data
	int numbers[5] = {1, 2, 3, 4, 5};
	int dest_numbers[10] = {0};
	int *num_rtn = (int *)ft_memcpy(dest_numbers, numbers, 5 * sizeof(int));
	/* 8 */ check(num_rtn == dest_numbers && 
	              dest_numbers[0] == 1 && 
	              dest_numbers[1] == 2 && 
	              dest_numbers[2] == 3 && 
	              dest_numbers[3] == 4 && 
	              dest_numbers[4] == 5 && 
	              dest_numbers[5] == 0); showLeaks();
	
	// Test 9: Copy exact buffer size
	memset(dest, 'A', 100);
	char full_src[100];
	memset(full_src, 'B', 100);
	ft_memcpy(dest, full_src, 100);
	bool all_copied = true;
	for (i = 0; i < 100; i++) {
		if (dest[i] != 'B') {
			all_copied = false;
			break;
		}
	}
	/* 9 */ check(all_copied); showLeaks();
	
	// Test 10: Copy single byte
	memset(dest, 'A', 100);
	ft_memcpy(dest, "X", 1);
	/* 10 */ check(dest[0] == 'X' && dest[1] == 'A'); showLeaks();
	
	write(1, "\n", 1);
	return (0);
}
