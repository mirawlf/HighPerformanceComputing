#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <time.h>
# include <omp.h>
# include <mpi.h>

typedef struct			s_elem
{
	int					num;
	struct s_elem		*next;
	struct s_elem		*prev;
}						t_elem;

typedef struct			s_stack
{
	struct s_elem		*head;
	struct s_elem		*tail;
	size_t				size;
}						t_stack;

typedef struct			s_push_swap
{
	struct s_stack		*a;
	struct s_stack		*b;
	unsigned char		is_sorted;
	int					next_min;
	int					current_mid;
	int					once_sorted;
	int					sort_nub;
}						t_push_swap;

/*
**	Returns 1 if all args are int and there are no duplicates in input;
**	Returns 0 if there are duplicates or any non-int symbols
*/

unsigned char			ft_input_validation(int ac, char **av);

/*
**	Creates new element with desired (num),
**	sets it's next and prev pointers to itself;
**	Returns pointer to newly created elem or NULL if error occured
*/

t_elem					*ft_newelem(int num);

/*
**	Creates new stack with 0 size,
**	sets it's head and prev pointers to NULL;
**	Returns ponter to newly created stack or NULL if error occured
*/

t_stack					*ft_newstack(void);

/*
**	Frees elem;
**	sets num and pointers of elem to 0 (NULL for pointers)
*/

void					ft_cleanelem(t_elem **elem);

/*
**	Frees all elements of the stack;
**	frees stack itself;
**	sets size and pounters to 0 (NULL for pointers)
*/

void					ft_cleanstack(t_stack **stack);

/*
**	Adds element (elem) to the end to the (stack);
**	if there is no stack - creates it;
**	Reassigns head and tail pointers of (stack);
**	Reassigns next and prev pounters of (elem)
*/

void					ft_addstack(t_elem *elem, t_stack **stack);

/*
**	swap a - swap the first 2 elements at the top of stack a;
**	does nothing if there is only one or no elements
*/

void					ft_sa(t_push_swap *ps);

/*
**	swap b - swap the first 2 elements at the top of stack b;
**	does nothing if there is only one or no elements
*/

void					ft_sb(t_push_swap *ps);

/*
**	sa and sb at the same time
*/

void					ft_ss(t_push_swap *ps);

/*
**	push a - take the first element at the top of b and put it at the top of a;
**	does nothing if b is empty
*/

void					ft_pa(t_push_swap *ps);

/*
**	push b - take the first element at the top of a and put it at the top of b;
**	does nothing if a is empty
*/

void					ft_pb(t_push_swap *ps);

/*
**	rotate a - shift up all elements of stack a by 1;
**	the first element becomes the last one
*/

void					ft_ra(t_push_swap *ps);

/*
**	rotate b - shift up all elements of stack b by 1;
**	the first element becomes the last one
*/

void					ft_rb(t_push_swap *ps);

/*
**	ra and rb at the same time
*/

void					ft_rr(t_push_swap *ps);

/*
**	reverse rotate a - shift down all elements of stack a by 1;
**	the last element becomes the first one
*/

void					ft_rra(t_push_swap *ps);

/*
**	reverse rotate b - shift down all elements of stack b by 1;
**	the last element becomes the first one
*/

void					ft_rrb(t_push_swap *ps);

/*
**	rra and rrb at the same time
*/

void					ft_rrr(t_push_swap *ps);

/*
**	is_sorted shows whether stack_a is sorted at the same time as stack_b
**	is empty
*/

unsigned char			ft_is_sorted(t_push_swap *ps);

/*
**	in case of an error output corresponding message
*/
void					ft_error(void);

/*
**	preparations for Merge sorting algorythm
*/

void					prep_sort(t_push_swap *ps);

/*
**	returns 1 in case of sorted stack, in other cases returns 0
*/

int						mid_sorting(t_stack *stack);

/*
**	shows whether nums >= current min num and <= current medium num
**	are in stack which we are working with
*/

int						min_mid_a(t_push_swap *ps, int min, int curr_mid);

/*
**	sorts stack if its size == 3
*/

void					min_num_of_operations(t_stack *stack,
		t_push_swap *ps, char ch);

/*
**	qsort algorithm for stack a
*/

void					quick_sort_a(t_push_swap *ps);

/*
**	qsort algorithm for stack a
*/

void					quick_sort_b(t_push_swap *ps);

/*
**	calculates how many steps you should do to reach max element in stack
**	then function rotate_b makes head of the stack max and returns whether
**	stack b is empty or not
*/

int						max_on_the_top_b(t_push_swap *ps);

/*
**	rotates stack b in the fastest way
*/

void					rotate_b(int st, int fh, t_push_swap *ps, int max);

/*
**	finds max element in stack
*/

int						max_elem(t_stack *stack);

/*
**	finds min element in stack
*/

int						min_elem(t_stack *stack);

/*
**	reads commands which of each command of algorithm
*/

void					reading_commands(t_push_swap *ps);

/*
**	finds next min elem in stack a
*/

int						min_elem_sort(t_push_swap *ps, int min);

/*
**	sorting in case of 2 or 3 elements in stack
*/

void					small_stack(t_stack *stack, t_push_swap *ps, char ch);

/*
**	replace elements from stack a to stack b
*/

void					from_a_to_b(t_push_swap *ps, int min, int mid);

/*
**	replace elements from stack b to stack a
*/

void					from_b_to_a(t_push_swap *ps);

/*
**	sorts stack a in case of its size == 3
*/

void					three_rotation_for_a(t_stack *stack, t_push_swap *ps);

/*
**	sorts stack b in case of its size == 3
*/

void					three_rotation_for_b(t_stack *stack, t_push_swap *ps);

void					start_of_sorting(t_push_swap *ps);

void					ft_clean_av(int ac, char **av);

void					ft_clean_input(int n, char **input);

char					**parse_input(char **av, int i, char **input);

void					ft_make_command(t_push_swap *ps, char *line);

#endif
