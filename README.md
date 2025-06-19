# 42
# command to remove .git files: rm -rf .git
// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	len1, len2;
// 	void *null_ptr = NULL;
// 	void *valid_ptr = (void *)0x1234abcd;

// 	// %c - characters
// 	len1 = ft_printf("ft: char: [%c]\n", 'A');
// 	len2 = printf("og: char: [%c]\n", 'A');
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	// %s - strings
// 	len1 = ft_printf("ft: str: [%s]\n", "hello");
// 	len2 = printf("og: str: [%s]\n", "hello");
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	len1 = ft_printf("ft: null str: [%s]\n", (char *)NULL);
// 	len2 = printf("og: null str: [%s]\n", (char *)NULL);
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	// %p - pointers
// 	len1 = ft_printf("ft: null ptr: [%p]\n", null_ptr);
// 	len2 = printf("og: null ptr: [%p]\n", null_ptr);
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	len1 = ft_printf("ft: valid ptr: [%p]\n", valid_ptr);
// 	len2 = printf("og: valid ptr: [%p]\n", valid_ptr);
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	// %d and %i - signed integers
// 	len1 = ft_printf("ft: int min: [%d], max: [%i]\n", INT_MIN, INT_MAX);
// 	len2 = printf("og: int min: [%d], max: [%i]\n", INT_MIN, INT_MAX);
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	len1 = ft_printf("ft: int zero: [%d]\n", 0);
// 	len2 = printf("og: int zero: [%d]\n", 0);
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	// %u - unsigned integers
// 	len1 = ft_printf("ft: uint max: [%u], zero: [%u]\n", UINT_MAX, 0);
// 	len2 = printf("og: uint max: [%u], zero: [%u]\n", UINT_MAX, 0);
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	// %x and %X - hexadecimal
// 	len1 = ft_printf("ft: hex: [%x], HEX: [%X]\n", 3735928559U, 3735928559U);
// 	len2 = printf("og: hex: [%x], HEX: [%X]\n", 3735928559U, 3735928559U);
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	len1 = ft_printf("ft: hex zero: [%x]\n", 0);
// 	len2 = printf("og: hex zero: [%x]\n", 0);
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);

// 	// %% - percent sign
// 	len1 = ft_printf("ft: percent sign: [%%]\n");
// 	len2 = printf("og: percent sign: [%%]\n");
// 	printf("Lengths: ft=%d, og=%d\n\n", len1, len2);
// 	ft_printf("Char: %c\n", 'A');
// 	printf("Char: %c\n", 'A');
// 	write(1, "\n", 1);

// 	ft_printf("Null char: %cEND\n", '\0');
// 	printf("Null char: %cEND\n", '\0');
// 	write(1, "\n", 1);

// 	ft_printf("Char: %c\n", 0);
// 	printf("Char: %c\n", 0);
// 	write(1, "\n", 1);

// 	ft_printf("String: %s\n", "Hello, world!");
// 	printf("String: %s\n", "Hello, world!");
// 	write(1, "\n", 1);

// 	ft_printf("Empty string: %s\n", "");
// 	printf("Empty string: %s\n", "");
// 	write(1, "\n", 1);

// 	ft_printf("Null string: %s\n", NULL);
// 	printf("Null string: %s\n", NULL);
// 	write(1, "\n", 1);

// 	int x = 42;
// 	ft_printf("Pointer: %p\n", &x);
// 	printf("Pointer: %p\n", &x);
// 	write(1, "\n", 1);

// 	ft_printf("Null pointer: %p\n", NULL);
// 	printf("Null pointer: %p\n", NULL);
// 	write(1, "\n", 1);

// 	ft_printf("Zero: %d\n", 0);
// 	printf("Zero: %d\n", 0);
// 	write(1, "\n", 1);

// 	ft_printf("Positive: %d\n", 12345);
// 	printf("Positive: %d\n", 12345);
// 	write(1, "\n", 1);

// 	ft_printf("Negative: %d\n", -12345);
// 	printf("Negative: %d\n", -12345);
// 	write(1, "\n", 1);

// 	ft_printf("INT_MAX: %d\n", INT_MAX);
// 	printf("INT_MAX: %d\n", INT_MAX);
// 	write(1, "\n", 1);

// 	ft_printf("INT_MIN: %d\n", INT_MIN);
// 	printf("INT_MIN: %d\n", INT_MIN);
// 	write(1, "\n", 1);

// 	ft_printf("Unsigned zero: %u\n", 0);
// 	printf("Unsigned zero: %u\n", 0);
// 	write(1, "\n", 1);

// 	ft_printf("Unsigned max: %u\n", UINT_MAX);
// 	printf("Unsigned max: %u\n", UINT_MAX);
// 	write(1, "\n", 1);

// 	ft_printf("Negative casted: %u\n", -1);
// 	printf("Negative casted: %u\n", -1);
// 	write(1, "\n", 1);

// 	ft_printf("Zero: %x\n", 0);
// 	printf("Zero: %x\n", 0);
// 	write(1, "\n", 1);

// 	ft_printf("Max unsigned: %x\n", UINT_MAX);
// 	printf("Max unsigned: %x\n", UINT_MAX);
// 	write(1, "\n", 1);

// 	ft_printf("Middle value: %x\n", 305441741);
// 	printf("Middle value: %x\n", 305441741);
// 	write(1, "\n", 1);

// 	ft_printf("Zero: %X\n", 0);
// 	printf("Zero: %X\n", 0);
// 	write(1, "\n", 1);

// 	ft_printf("Max unsigned: %X\n", UINT_MAX);
// 	printf("Max unsigned: %X\n", UINT_MAX);
// 	write(1, "\n", 1);

// 	ft_printf("Mixed: %X\n", 305441741);
// 	printf("Mixed: %X\n", 305441741);
// 	write(1, "\n", 1);

// 	ft_printf("Percent: %%\n");
// 	printf("Percent: %%\n");
// 	write(1, "\n", 1);

// 	ft_printf("Multiple: %% %% %%\n");
// 	printf("Multiple: %% %% %%\n");
// 	write(1, "\n", 1);

// 	ft_printf("Mix: %d %u %x %X %p %c %s %%\n",
// 	-42, 42, 255, 255, &x, 'Z', "Test");
// 	printf("Mix: %d %u %x %X %p %c %s %%\n",
// 	-42, 42, 255, 255, &x, 'Z', "Test");
// 	write(1, "\n", 1);

// 	ft_printf("Null str & ptr: %s %p\n", NULL, NULL);
// 	printf("Null str & ptr: %s %p\n", NULL, NULL);
// 	write(1, "\n", 1);

// 	ft_printf("Crazy: %d %d %d %u %x %X %c %s %%\n",
// 	INT_MIN, INT_MAX, 0, UINT_MAX, 3735928559, 3735928559, '!', "", "");
// 	printf("Crazy: %d %d %d %u %x %X %c %s %%\n",
// 	INT_MIN, INT_MAX, 0, UINT_MAX, 3735928559, 3735928559, '!', "", "");
// 	write(1, "\n", 1);

// 	int a = ft_printf("1234567890\n");
// 	int b = printf("1234567890\n");
// 	printf("ft_printf returned %d, printf returned %d\n", a, b);

// 	x = 42;

// 	printf("=== TEST: %s ===\n", "Null string");
// 	int ret1 = printf("printf: [%s]\n", NULL);
// 	int ret2 = ft_printf("ft_printf: [%s]\n", NULL);
// 	printf("return values: printf=%d ft_printf=%d\n", ret1, ret2);

// 	return 0;
// }