#include "push_swap.h"

void                ft_reverse_rotate(t_p_swap **pile, char *str)
{
    t_p_swap        *last;
    t_p_swap        *second_last;

    last = *pile;
    second_last = *pile;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *pile;
    *pile = last;
    ft_putendl(str);
}

void                ft_rotate(t_p_swap **pile, char *str)
{
    t_p_swap        *first;
    t_p_swap        *last;

    first = *pile;
    last = *pile;
    while (last->next)
        last = last->next;
    *pile = first->next;
    first->next = NULL;
    last->next = first;
    ft_putendl(str);
}

void                ft_push(t_p_swap **pile_1, t_p_swap **pile_2, char *str)
{
    t_p_swap        *temp_1;
    t_p_swap        *temp_2;

    temp_1 = *pile_1;
    *pile_1 = temp_1->next;
    temp_2 = *pile_2;
    *pile_2 = temp_1;
    temp_1->next = temp_2;
    ft_putendl(str);
}

void                ft_swap(t_p_swap **pile, char *str)
{
    t_p_swap        *temp_1;
    t_p_swap        *temp_2;
    t_p_swap        *temp_3;

    temp_1 = *pile;
    temp_2 = temp_1->next;
    temp_3 = temp_2->next;
    *pile = temp_1->next;
    temp_1->next = temp_3;
    temp_2->next = temp_1;
    ft_putendl(str);
}

void                ft_add_elem(t_p_swap **pile, int nb)
{
    t_p_swap        *new_elem;

    if (!(new_elem = malloc(sizeof(t_p_swap))))
        return ;
    new_elem->i = nb;
    new_elem->next = *pile;
    *pile = new_elem;
}

long int            ft_atoli(const char *str)
{
	int             j;
	long int		k;

	j = 1;
	k = 0;
	while (*str == ' ' || *str == '\t'
		|| *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j = -j;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		k = k * 10 + (*str - 48);
		str++;
	}
	return (j * k);
}

int                 ft_return_error(void)
{
    ft_putendl("Error");
    return (0);
}

int                 ft_pile_in_order(t_p_swap **pile_a)
{
    t_p_swap        *temp;
    int             nb;

    temp = *pile_a;
    nb = temp->i;
    while (temp->next)
    {
        temp = temp->next;
        if (nb > temp->i)
            return (0);
        nb = temp->i;
    }
//    printf("pile is in order\n");
    return (1);
}

void                ft_swap_min(t_p_swap **pile_a, t_p_swap **pile_b, int argc, int *size)
{
    int             j;
    int             min;
    int             max;
    t_p_swap        *temp;
    t_p_swap        *temp_1;
    t_p_swap        *temp_2;

    j = 1;
    temp = *pile_a;
    max = temp->i;
    while (temp->next)
    {
        temp = temp->next;
        if (max < temp->i)
            max = temp->i;
    }
    while (ft_pile_in_order(pile_a) != 1)
    {
        temp = *pile_a;
        min = temp->i;
        while (temp->next)
        {
            temp = temp->next;
            if (min > temp->i)
                min = temp->i;
        }
        temp_1 = *pile_a;
        temp_2 = temp_1->next;
        if (temp_1->i == min)
        {    
            ft_push(pile_a, pile_b, "pb");
            *size = *size - 1;
        }
        if (temp_1->i != max && temp_2->i != max)
        {
            if (temp_1->i > temp_2->i)
                ft_swap(pile_a, "sa");
        }
        ft_reverse_rotate(pile_a, "rra");
        j++;
    }
}

void                ft_order(t_p_swap **pile_a, t_p_swap **pile_b, int argc)
{
    int             i;
    int             j;
    int             min;
    int             size;
    int             half;
    t_p_swap        *temp;

    j = 1;
    size = argc - 1;
    half = (argc - 1) / 2;
    while (j < argc - 1)
    {
        temp = *pile_a;
        min = temp->i;
        while (temp->next)
        {
            temp = temp->next;
            if (min > temp->i)
                min = temp->i;
        }
        i = 0;
        temp = *pile_a;
        while (temp->i != min)
        {
            temp = temp->next;
            i++;
        }
        if (i <= half)
        {
            if (i == 0)
                ft_swap(pile_a, "sa");
            while (i > 1)
            {
                ft_rotate(pile_a, "ra");
                i--;
            }
            ft_swap(pile_a, "sa");
            ft_push(pile_a, pile_b, "pb");
        }
        else if (i > half)
        {
            while (i < size)
            {
                ft_reverse_rotate(pile_a, "rra");
                i++;
            }
            ft_push(pile_a, pile_b, "pb");
            size--;
        }
        j++;
    }
}

int                 ft_exec(t_p_swap **pile_a, t_p_swap **pile_b, int argc, char **argv)
{
    int             i;
    int             j;
    int             size;
    t_p_swap        *temp;
    
    i = 0;
    j = 1;
    temp = *pile_b;
    size = argc - 1;
    if (argc == 2)
        return (0);
    if (ft_pile_in_order(pile_a) == 1)
        return (1);
    if (argc == 3)
    {
        if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
            ft_swap(pile_a, "sa");
        else
            return (0);
    }
    else if (argc > 3)
    {
    //    ft_order(pile_a, pile_b, argc);
        ft_swap_min(pile_a, pile_b, argc, &size);
    //    printf("size : %i\n", size);
    //    ft_push(pile_a, pile_b, "pb");
        while (j < argc - size)
        {
            ft_push(pile_b, pile_a, "pa");
            j++;
        }
    //    dprintf(2, "HERE\n");
    //    ft_push(pile_b, pile_a, "pa");
    }
    return (1);
}

int                 push_swap(t_p_swap **pile_a, int argc, char **argv)
{
    int             i;
    int             j;

    if (argc == 1)
        return (0);
    i = argc;
    while (i-- > 1)
    {
        j = 0;
        j += (argv[i][j] == '-') ? 1 : 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 0)
                return(ft_return_error());
            j++;
        }
        if (ft_atoli(argv[i]) < INT_MIN || ft_atoli(argv[i]) > INT_MAX)
            return(ft_return_error());
        j = i;
        while (j-- > 1)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return(ft_return_error());
        }
        ft_add_elem(pile_a, ft_atoi(argv[i]));
    }
    return (1);
}