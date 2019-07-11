/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:20:42 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/11 10:53:22 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
                       
void	ft_print_combn(int n)
{
	int		num[10];
	int		max[10];
	int		count;
	count = n;
	while(count > 0)
	{
		num[n - count] = n - count;
		max[n - count] = 10 - count;
		count--;
	}
	int 	count_ini;
	count_ini = 0;
	while(count_ini < n)
    {
        ft_putchar(num[count_ini] + 48);
        count_ini++;
    }
    ft_putchar(',');
    ft_putchar(' ');

	int		finish;
	finish = 1;
	while(finish)
	{
		int		is_done;
		is_done = 1;
		int		count_three;
		count_three = n;
		while(is_done)
		{
			if(num[count_three - 1] < max[count_three - 1])
			{
				num[count_three - 1]++;
				if(count_three < n)
				{
					int		count_four;
					count_four = count_three + 1;
					while(count_four <= n)
					{
						if(num[count_four - 2] + 1 < max[count_four - 1])
						{
							num[count_four - 1] = num[count_four - 2] + 1;
						}
						count_four++;
					}
				}
				is_done = 0;
				int		count_five;
				count_five = 0;
				while(count_five < n)
				{
					ft_putchar(num[count_five] + 48);
					count_five++;
				}
			}
			count_three--;
		}

		int		count_two;
		count_two = 0;
		while(count_two < n)
		{
			if(num[count_two] != max[count_two])
			{
				finish = 1;
				ft_putchar(',');
				ft_putchar(' ');
				break;
			}
			else
			{
				finish = 0;
			}
			count_two++;
		}
	}
}
