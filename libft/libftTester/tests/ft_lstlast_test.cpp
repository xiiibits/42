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
	title("ft_lstlast\t: ")

	// Test 1: Empty list
	t_list * l =  NULL;
	/* 1 */ check(ft_lstlast(l) == NULL); // Check last element of empty list is NULL
	
	// Test 2-4: List with one element
	ft_lstadd_back(&l, ft_lstnew((void*)1));
	/* 2 */ check(ft_lstlast(l)->content == (void*)1); // Check content of last element
	/* 3 */ check(ft_lstlast(l)->next == NULL); // Check next pointer of last element is NULL
	/* 4 */ check(l == ft_lstlast(l)); // First element should be the last in a single-element list
	
	// Test 5-7: List with two elements
	ft_lstadd_back(&l, ft_lstnew((void*)2));
	/* 5 */ check(ft_lstlast(l)->content == (void*)2); // Check content of last element
	/* 6 */ check(ft_lstlast(l)->next == NULL); // Check next pointer of last element is NULL
	/* 7 */ check(l != ft_lstlast(l)); // First element should not be the last in a multi-element list
	
	// Test 8: List with three elements
	ft_lstadd_back(&l, ft_lstnew((void*)3));
	/* 8 */ check(ft_lstlast(l)->content == (void*)3); // Check content of last element after adding third
	
	// Test 9: List with multiple elements and NULL content in the last node
	freeList(l);
	l = NULL;
	
	// Create a new list
	ft_lstadd_back(&l, ft_lstnew((void*)10));
	ft_lstadd_back(&l, ft_lstnew((void*)20));
	ft_lstadd_back(&l, ft_lstnew((void*)30));
	ft_lstadd_back(&l, ft_lstnew(NULL)); // Last node has NULL content
	/* 9 */ check(ft_lstlast(l)->content == NULL); // Check that last element has NULL content
	
	// Test 10: List with string content in the last node
	freeList(l);
	l = NULL;
	
	ft_lstadd_back(&l, ft_lstnew((void*)100));
	ft_lstadd_back(&l, ft_lstnew((void*)200));
	char *str = strdup("Last node");
	ft_lstadd_back(&l, ft_lstnew((void*)str));
	/* 10 */ check(strcmp((char*)ft_lstlast(l)->content, "Last node") == 0); // Check string content of last element
	
	// Test 11-12: Adding element after getting last element
	t_list *last = ft_lstlast(l);
	ft_lstadd_back(&l, ft_lstnew((void*)999));
	/* 11 */ check(last != ft_lstlast(l)); // Previous last should not be the current last
	/* 12 */ check(ft_lstlast(l)->content == (void*)999); // Check content of new last element
	
	// Cleanup
	free(str);
	freeList(l);
	
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
