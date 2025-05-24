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
	title("ft_lstadd_back\t: ")

	// Test 1-2: Adding to empty list
	t_list * l =  NULL;
	ft_lstadd_back(&l, ft_lstnew((void*)1));
	/* 1 */ check(l->content == (void*)1); // Check content of first node
	/* 2 */ check(l->next == NULL); // Check next pointer is NULL

	// Test 3-5: Adding to list with one element
	ft_lstadd_back(&l, ft_lstnew((void*)2));
	/* 3 */ check(l->content == (void*)1); // Check first node content unchanged
	/* 4 */ check(((t_list *)(l->next))->content == (void*)2); // Check content of second node
	/* 5 */ check(((t_list *)(l->next))->next == NULL); // Check next pointer of second node

	// Test 6-10: Adding list to another list
	t_list * l2 =  NULL;
	ft_lstadd_back(&l2, ft_lstnew((void*)3));
	ft_lstadd_back(&l2, ft_lstnew((void*)4));
	ft_lstadd_back(&l, l2);
	/* 6 */ check(l->content == (void*)1); // Check first node content unchanged
	/* 7 */ check(((t_list *)(l->next))->content == (void*)2); // Check second node content unchanged
	/* 8 */ check(((t_list *)(((t_list *)(l->next))->next))->content == (void*)3); // Check third node content
	/* 9 */ check(((t_list *)((t_list *)(((t_list *)(l->next))->next))->next)->content == (void*)4); // Check fourth node content
	/* 10 */ check(((t_list *)((t_list *)(((t_list *)(l->next))->next))->next)->next == NULL); // Check next pointer of fourth node

	// Test 11-12: Adding node with NULL content
	ft_lstadd_back(&l, ft_lstnew(NULL));
	t_list *last = l;
	while (last->next)
		last = last->next;
	/* 11 */ check(last->content == NULL); // Check last node has NULL content
	/* 12 */ check(last->next == NULL); // Check next pointer is NULL
	
	// Test 13-14: Adding node with string content
	char *str = strdup("Hello");
	ft_lstadd_back(&l, ft_lstnew((void*)str));
	last = l;
	while (last->next)
		last = last->next;
	/* 13 */ check(strcmp((char*)last->content, "Hello") == 0); // Check string content of last node
	/* 14 */ check(last->next == NULL); // Check next pointer is NULL

	// Test 15-16: Adding multiple nodes in sequence
	freeList(l);
	l = NULL;
	
	for (int i = 1; i <= 5; i++) {
		ft_lstadd_back(&l, ft_lstnew((void*)(intptr_t)i));
	}
	
	// Check if all 5 nodes were added in the correct order
	t_list *curr = l;
	for (int i = 1; i <= 5; i++) {
		/* 15 */ check(curr->content == (void*)(intptr_t)i); // Check node content matches expected value
		curr = curr->next;
	}
	/* 16 */ check(curr == NULL); // Check end of list reached
	
	// Cleanup
	free(str);
	freeList(l);
	
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
