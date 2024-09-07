# ft_printf
make

./src
cc *.c -I../include -I../libft -L../libft -lft -o ft_printf

leaks
valgrind --leak-check=full ./ft_printf
