#include "./libft/libft.h"

struct              s_list 
{
    int             i;
    struct s_list   *next;
};


int         main(int argc, char **argv)
{
    int     *a;
    int     *b;
    int     i;
    int     j;

    i = 1;
    j = 0;
    if (!(a = (int*)malloc(sizeof(int) * (argc - 1))))
        return (-1);
    if (!(b = (int*)malloc(sizeof(int) * (argc - 1))))
        return (-1);
    printf("argc : %i\n", argc);
    while (argv[i])
    {
        a[j] = ft_atoi(argv[i]);
        printf("a[%i] : %i\n", j, a[j]);
        i++;
        j++;
    }
    return (0);
}