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
	title("ft_bzero\t: ")
	
	char tab[100];
	
	// Test 1: Zero-length bzero shouldn't change anything
	memset(tab, 'A', 100);
	ft_bzero(tab, 0);
	/* 1 */ check(tab[0] == 'A'); showLeaks();
	
	// Test 2: Zeroing first 42 bytes
	ft_bzero(tab, 42);
	int i = 0;
	for (; i < 100 && tab[i] == 0; ++i)
		;
	/* 2 */ check(i == 42 && tab[42] == 'A'); showLeaks();
	
	// Test 3: Zeroing when first byte is already zero
	memset(tab, 'A', 100); 
	tab[0] = 0;
	ft_bzero(tab, 42);
	i = 0;
	for (; i < 100 && tab[i] == 0; ++i)
		;
	/* 3 */ check(i == 42); showLeaks();
	
	// Test 4: Zeroing single byte
	memset(tab, 'B', 100);
	ft_bzero(tab, 1);
	/* 4 */ check(tab[0] == 0 && tab[1] == 'B'); showLeaks();
	
	// Test 5: Zeroing entire array
	memset(tab, 'C', 100);
	ft_bzero(tab, 100);
	bool all_zeroed = true;
	for (i = 0; i < 100; i++) {
		if (tab[i] != 0) {
			all_zeroed = false;
			break;
		}
	}
	/* 5 */ check(all_zeroed); showLeaks();
	
	// Test 6: Zeroing middle of array
	memset(tab, 'D', 100);
	ft_bzero(tab + 25, 50);
	/* 6 */ check(tab[24] == 'D' && tab[25] == 0 && tab[74] == 0 && tab[75] == 'D'); showLeaks();
	
	// Test 7: Zeroing with various initial patterns
	for (i = 0; i < 100; i++)
		tab[i] = i;
	ft_bzero(tab, 50);
	all_zeroed = true;
	for (i = 0; i < 50; i++) {
		if (tab[i] != 0) {
			all_zeroed = false;
			break;
		}
	}
	/* 7 */ check(all_zeroed && tab[50] == 50); showLeaks();
	
	// Test 8: Zeroing array that's already zeroed
	memset(tab, 0, 100);
	ft_bzero(tab, 50);
	all_zeroed = true;
	for (i = 0; i < 100; i++) {
		if (tab[i] != 0) {
			all_zeroed = false;
			break;
		}
	}
	/* 8 */ check(all_zeroed); showLeaks();
	
	// Test 9: Zeroing after another value at boundary
	memset(tab, 0, 100);
	tab[29] = 'X';
	ft_bzero(tab + 30, 40);
	/* 9 */ check(tab[29] == 'X' && tab[30] == 0 && tab[69] == 0); showLeaks();
	
	// Test 10: Zeroing with non-character values
	memset(tab, 255, 100);  // Fill with all bits set
	ft_bzero(tab, 25);
	all_zeroed = true;
	for (i = 0; i < 25; i++) {
		if ((unsigned char)tab[i] != 0) {
			all_zeroed = false;
			break;
		}
	}
	/* 10 */ check(all_zeroed && (unsigned char)tab[25] == 255); showLeaks();
	
	write(1, "\n", 1);
	return (0);
}