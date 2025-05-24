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
	title("ft_lstadd_front\t: ")

	// Test 1-2: Adding to empty list
	t_list * l =  NULL;
	ft_lstadd_front(&l, ft_lstnew((void*)1));
	/* 1 */ check(l->content == (void*)1); // Check content of first node
	/* 2 */ check(l->next == NULL); // Check next pointer is NULL

	// Test 3-5: Adding to list with one element
	ft_lstadd_front(&l, ft_lstnew((void*)2));
	/* 3 */ check(l->content == (void*)2); // Check content of new first node
	/* 4 */ check(((t_list *)l->next)->content == (void*)1); // Check content of second node
	/* 5 */ check(((t_list *)l->next)->next == NULL); // Check next pointer of second node is NULL

	// Test 6-8: Adding to list with two elements
	ft_lstadd_front(&l, ft_lstnew((void*)3));
	/* 6 */ check(l->content == (void*)3); // Check content of new first node
	/* 7 */ check(((t_list *)l->next)->content == (void*)2); // Check content of second node
	/* 8 */ check(((t_list *)((t_list *)l->next)->next)->content == (void*)1); // Check content of third node
	/* 9 */ check(((t_list *)((t_list *)l->next)->next)->next == NULL); // Check next pointer of third node is NULL

	// Test 10-12: Adding string content
	char *str = strdup("Hello");
	ft_lstadd_front(&l, ft_lstnew((void*)str));
	/* 10 */ check(strcmp((char*)l->content, "Hello") == 0); // Check string content of new first node
	/* 11 */ check(((t_list *)l->next)->content == (void*)3); // Check content of second node is unchanged
	/* 12 */ check(((t_list *)((t_list *)l->next)->next)->content == (void*)2); // Check content of third node is unchanged

	// Test 13-15: Adding NULL content
	ft_lstadd_front(&l, ft_lstnew(NULL));
	/* 13 */ check(l->content == NULL); // Check NULL content of new first node
	/* 14 */ check(strcmp((char*)((t_list *)l->next)->content, "Hello") == 0); // Check content of second node is unchanged
	/* 15 */ check(((t_list *)((t_list *)l->next)->next)->content == (void*)3); // Check content of third node is unchanged

	// Free all memory
	free(str); // Free the duplicated string
	freeList(l);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
