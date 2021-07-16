#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "./libft/libft.h"

typedef struct      s_p_swap
{
    int             i;
    struct s_p_swap *next;
}                   t_p_swap;

int                 push_swap(t_p_swap **pile_a, int argc, char **argv);
int                 ft_exec(t_p_swap **pile_a, t_p_swap **pile_b, int argc, char **argv);

#endif