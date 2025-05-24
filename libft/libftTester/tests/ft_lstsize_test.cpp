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

void freeList(t_list *head) {if (head) freeList((t_list *)head->next); free(head);}

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_lstsize\t: ")

	// Test 1: Empty list
	t_list * l =  NULL;
	/* 1 */ check(ft_lstsize(l) == 0); // Check size of empty list

	// Test 2: List with one element
	ft_lstadd_front(&l, ft_lstnew((void*)1));
	/* 2 */ check(ft_lstsize(l) == 1); // Check size after adding one element

	// Test 3: List with two elements
	ft_lstadd_front(&l, ft_lstnew((void*)2));
	/* 3 */ check(ft_lstsize(l) == 2); // Check size after adding second element

	// Test 4: List with three elements
	ft_lstadd_front(&l, ft_lstnew((void*)3));
	/* 4 */ check(ft_lstsize(l) == 3); // Check size after adding third element

	// Test 5: List with four elements
	ft_lstadd_front(&l, ft_lstnew((void*)4));
	/* 5 */ check(ft_lstsize(l) == 4); // Check size after adding fourth element

	// Test 6: List with five elements
	ft_lstadd_front(&l, ft_lstnew((void*)5));
	/* 6 */ check(ft_lstsize(l) == 5); // Check size after adding fifth element

	// Clean up first list
	freeList(l);
	l = NULL;

	// Test 7: Create a new list with ten elements
	t_list *l2 = NULL;
	for (int i = 0; i < 10; i++) {
		ft_lstadd_front(&l2, ft_lstnew((void*)(intptr_t)(i+1)));
	}
	/* 7 */ check(ft_lstsize(l2) == 10); // Check size of list with 10 elements

	// Test 8: Testing a linked list with the same content values
	t_list *l_same = NULL;
	for (int i = 0; i < 5; i++) {
		ft_lstadd_front(&l_same, ft_lstnew((void*)42)); // All nodes have the same content value
	}
	/* 8 */ check(ft_lstsize(l_same) == 5); // Should correctly count nodes with same content value

	// Test 9: Testing a list with NULL content nodes
	t_list *l3 = NULL;
	for (int i = 0; i < 5; i++) {
		ft_lstadd_front(&l3, ft_lstnew(NULL));
	}
	/* 9 */ check(ft_lstsize(l3) == 5); // List size should count nodes with NULL content

	// Test 10: Adding more elements to an existing list
	for (int i = 0; i < 5; i++) {
		ft_lstadd_front(&l3, ft_lstnew((void*)(intptr_t)(i+1)));
	}
	/* 10 */ check(ft_lstsize(l3) == 10); // Check size after adding more elements

	// Cleanup
	freeList(l2);
	freeList(l_same);
	freeList(l3);
	
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
