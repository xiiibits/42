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
	title("ft_lstnew\t: ")

	// Test 1-2: Basic integer test
	t_list * l1 = ft_lstnew((void*)42);
	/* 1 */ check(l1->content == (void*)42); // Check content
	/* 2 */ check(l1->next == 0); // Check next pointer is NULL
	
	// Test 3: Memory allocation check
	/* 3 */ mcheck(l1, sizeof(t_list)); 
	
	// Test 4-5: String content
	char *str = strdup("Hello, world!");
	t_list *l2 = ft_lstnew((void*)str);
	/* 4 */ check(strcmp((char*)l2->content, "Hello, world!") == 0); // Check string content
	/* 5 */ check(l2->next == NULL); // Check next pointer is NULL
	
	// Test 6-7: NULL content
	t_list *l3 = ft_lstnew(NULL);
	/* 6 */ check(l3->content == NULL); // Check NULL content
	/* 7 */ check(l3->next == NULL); // Check next pointer is NULL
	
	// Test 8-9: Float content using a pointer
	float *f = (float*)malloc(sizeof(float));
	*f = 3.14f;
	t_list *l4 = ft_lstnew((void*)f);
	/* 8 */ check(*(float*)l4->content == 3.14f); // Check float content
	/* 9 */ check(l4->next == NULL); // Check next pointer is NULL
	
	// Test 10-11: Structure content
	typedef struct s_example {
		int x;
		char y;
	} t_example;
	t_example *ex = (t_example*)malloc(sizeof(t_example));
	ex->x = 10;
	ex->y = 'A';
	t_list *l5 = ft_lstnew((void*)ex);
	/* 10 */ check(((t_example*)l5->content)->x == 10); // Check structure content field x
	/* 11 */ check(((t_example*)l5->content)->y == 'A'); // Check structure content field y
	/* 12 */ check(l5->next == NULL); // Check next pointer is NULL
	
	// Cleanup
	free(l1);
	free(str);
	free(l2);
	free(l3);
	free(f);
	free(l4);
	free(ex);
	free(l5);
	
	showLeaks();
	write(1, "\n", 1);
	return (0);
}