extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include <unistd.h>
#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);  
	title("ft_memset\t: ")

	char tab[100];
	memset(tab, 0, 100);
	
	// Test 1: Zero-length memset shouldn't change anything
	ft_memset(tab, 'A', 0);
	/* 1 */ check(tab[0] == 0); showLeaks();
	
	// Test 2: Set first 42 bytes to 'A'
	ft_memset(tab, 'A', 42);
	int i = 0;
	for (; i < 100 && tab[i] == 'A'; ++i)
		;
	/* 2 */ check(i == 42 && tab[42] == 0); showLeaks();
	
	// Test 3: Set to a different value
	memset(tab, 0, 100);
	ft_memset(tab, 'B', 10);
	/* 3 */ check(tab[0] == 'B' && tab[9] == 'B' && tab[10] == 0); showLeaks();
	
	// Test 4: Set with a byte value > 127
	memset(tab, 0, 100);
	ft_memset(tab, 130, 5);
	/* 4 */ check((unsigned char)tab[0] == 130 && (unsigned char)tab[4] == 130 && tab[5] == 0); showLeaks();
	
	// Test 5: Set with a negative byte value
	memset(tab, 0, 100);
	ft_memset(tab, -1, 5);
	/* 5 */ check((unsigned char)tab[0] == 255 && (unsigned char)tab[4] == 255 && tab[5] == 0); showLeaks();
	
	// Test 6: Single byte
	memset(tab, 0, 100);
	ft_memset(tab, 'X', 1);
	/* 6 */ check(tab[0] == 'X' && tab[1] == 0); showLeaks();
	
	// Test 7: Set entire buffer
	memset(tab, 0, 100);
	ft_memset(tab, '!', 100);
	bool all_set = true;
	for (i = 0; i < 100; i++) {
		if (tab[i] != '!') {
			all_set = false;
			break;
		}
	}
	/* 7 */ check(all_set); showLeaks();
	
	// Test 8: Set with null character
	memset(tab, 'Z', 100);
	ft_memset(tab, '\0', 50);
	all_set = true;
	for (i = 0; i < 50; i++) {
		if (tab[i] != '\0') {
			all_set = false;
			break;
		}
	}
	/* 8 */ check(all_set && tab[50] == 'Z'); showLeaks();
	
	// Test 9: Set with numerical value
	memset(tab, 0, 100);
	ft_memset(tab, 48, 10); // ASCII 48 is '0'
	/* 9 */ check(tab[0] == '0' && tab[9] == '0' && tab[10] == 0); showLeaks();
	
	// Test 10: Return value is correct
	memset(tab, 0, 100);
	void *ret = ft_memset(tab, 'R', 20);
	/* 10 */ check(ret == tab && tab[0] == 'R' && tab[19] == 'R'); showLeaks();
	
	write(1, "\n", 1);
	return (0);
}