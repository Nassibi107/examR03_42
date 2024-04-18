/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:22:57 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/18 12:12:31 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include <unistd.h>
#include <stdio.h>

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
         ft_iputstr(s[i++], b);
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

int ft_printflag(va_list va, char f)
{
   int b = 0;
   if (f == 's')
      ft_putchar(va_arg(va , char * ), &b);
   else if (f == 'd')
      ft_putnbr(va_arg(va , int), &b);
   else if (f == 'x')
      ft_puthex(va_arg(va ,unsigned int), &b);
   else
      ft_iputstr(f, &b);
   return (b);
}
int ft_printf(const char *format,...)
{
   int i =0;
   int  b = 0;
   va_list va;
   va_start(va, format);
   if (write(1,"",1) == -1)
      return(-1);
   while (format[i])
   {
      if (format[i] == '%')
      {
         if (!format[i + 1])
            break;
         b += ft_printflag(va, format[++i]);
      }
      else
         b += write(1,&format[i],1);
      i++;
   }
   va_end(va);
   return (b);
}

// int main ()
// {
//    int a = 0;
//    int b = 0;
//    b= ft_printf("%s nassibi%d\n", "yassine",23);
//    a = printf("%s nassibi%d\n", "yassine", 23);
//    ft_printf("sys_[%d]\t ft_[%d]", a, b);

// }
