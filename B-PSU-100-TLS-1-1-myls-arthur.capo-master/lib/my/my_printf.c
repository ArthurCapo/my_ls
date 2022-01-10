/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_putprintf(char *str, int count, va_list ap)
{
    if (str[count + 1] == 's') {
        my_putstr(va_arg(ap, char *));
        return(2); 
    }
    if (str[count + 1] == 'd' || str[count + 1] == 'i') {
        my_put_nbr(va_arg(ap, int));
        return(2);
    }
    if (str[count + 1] == 'c') {
        my_putchar(va_arg(ap, int));
        return(2);
    }
    if (str[count + 1] == '%') {
        my_putchar(va_arg(ap, int));
        return(2);
    }
}

int my_printf(char *str, ...)
{
    va_list ap;
    int count = 0;
    va_start(ap, str);

    while (str[count] != '\0') {
        if (str[count] == '%') {
           count += my_putprintf(str, count, ap);
        } else {
        my_putchar(str[count]);
        count++;
        }
    }
    va_end(ap);
}
