#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct      s_p_swap
{
    int             i;
    struct s_p_swap *next;
}                   t_p_swap;

int                 push_swap(t_p_swap **pile_a, int argc, char **argv);
void                ft_exec(t_p_swap **pile_a, t_p_swap **pile_b);

#endif