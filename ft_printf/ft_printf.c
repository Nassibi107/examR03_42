/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:22:57 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/15 15:56:48 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <sys/_types/_va_list.h>
#include <unistd.h>

void  ft_iputstr(char c, int *b)
{
   (*b) += write(1,&c,1);
}

void ft_putchar(char *s, int *b)
{
   int i = 0;
   if (!s)
      (*b) += write(1, "(null)", 7);
   else
      while(s[i])
         ft_iputstr(s[i], b);
}
void  ft_putnbr(int n, int *b)
{
   long nb;

   nb = n;
   if (nb < 0)
   {
      ft_iputstr('-', b);
      nb *= 10;
   }
   if (nb < 10)
   {
      ft_iputstr(nb + '0' , b);
   }
   else{
      ft_putnbr(nb / 10, b);
      ft_putnbr(nb % 10, b);
   }
}
void  ft_puthex(unsigned int nb, int *b)
{
   char *hx;
   hx = "0123456789abcdef";
   if (nb < 10)
   {
      ft_iputstr(hx[nb % 16]  + '0' , b);
      return;
   }
   else{
      ft_puthex(nb / 16, b);
      ft_puthex(nb % 16, b);
   }
}

int ft_printf(va_list va, char f)
{
   int b = 0;
   if (f == 's')
      ft_iputstr((va_arg(va , char )), &b);
   return (b);
}
