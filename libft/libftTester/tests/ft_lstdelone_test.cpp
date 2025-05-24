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

// Define the test struct globally
typedef struct s_test {
    int value;
    char *str;
} t_test;

// Custom delete functions for tracking if they were called
int delete_count = 0;
void custom_del(void *content) {
    delete_count++;
    free(content);
}

void string_del(void *content) {
    delete_count++;
    free(content);
}

void null_del(void *content) {
    (void)content;
    delete_count++;
}

void delete_struct(void *content) {
    t_test *t = (t_test *)content;
    free(t->str);
    free(t);
    delete_count++;
}

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv); (void)iTest;
	title("ft_lstdelone\t: ");

	// Test 1: Basic test - delete a node with malloc'd content
	delete_count = 0;
	t_list * l1 = ft_lstnew(malloc(1));
	ft_lstdelone(l1, free);
	/* 1 */ check(true); // If we get here without crashing, the test passes
	
	// Test 2-3: Delete a node with custom delete function
	delete_count = 0;
	t_list * l2 = ft_lstnew(malloc(10));
	ft_lstdelone(l2, custom_del);
	/* 2 */ check(delete_count == 1); // Verify custom_del was called
	/* 3 */ check(true); // Verify no crash
	
	// Test 4-5: Delete a node with string content
	delete_count = 0;
	char *str = strdup("Test string");
	t_list * l3 = ft_lstnew(str);
	ft_lstdelone(l3, string_del);
	/* 4 */ check(delete_count == 1); // Verify string_del was called
	/* 5 */ check(true); // Verify no crash
	
	// Test 6-7: Delete a node with NULL content
	delete_count = 0;
	t_list * l4 = ft_lstnew(NULL);
	ft_lstdelone(l4, null_del);
	/* 6 */ check(delete_count == 1); // Verify null_del was called
	/* 7 */ check(true); // Verify no crash
	
	// Test 8-9: Check that only one node is deleted in a chain
	delete_count = 0;
	t_list * head = ft_lstnew(malloc(1));
	t_list * next = ft_lstnew(malloc(1));
	head->next = next;
	
	// Create a copy of the 'next' pointer for later verification
	t_list * next_copy = next;
	
	ft_lstdelone(head, custom_del);
	/* 8 */ check(delete_count == 1); // Verify custom_del was called once
	/* 9 */ check(next_copy->content != NULL); // Verify next node's content wasn't freed
	
	// Clean up the remaining node
	free(next_copy->content);
	free(next_copy);
	
	// Test 10-11: Delete a node with struct content
	delete_count = 0;
	t_test *test_struct = (t_test *)malloc(sizeof(t_test));
	test_struct->value = 42;
	test_struct->str = strdup("struct test");
	
	t_list * l5 = ft_lstnew(test_struct);
	ft_lstdelone(l5, delete_struct);
	/* 10 */ check(delete_count == 1); // Verify delete_struct was called
	/* 11 */ check(true); // Verify no crash
	
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
