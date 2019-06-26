/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_defines.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:15:53 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 18:20:46 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DEFINES_H
# define FT_PRINTF_DEFINES_H

/*
** FT_PRINTF_OPTION_*
**
** Options used in the 'options' field of the 's_printf_format' structure.
*/

# define FT_PRINTF_OPTION_NONE 0x0
# define FT_PRINTF_OPTION_ALT 0x1
# define FT_PRINTF_OPTION_ZERO_PADDING 0x2
# define FT_PRINTF_OPTION_LEFT_ALIGN 0x4
# define FT_PRINTF_OPTION_SPACE 0x8
# define FT_PRINTF_OPTION_SIGN 0x10
# define FT_PRINTF_OPTION_THOUSANDS 0x20
# define FT_PRINTF_OPTION_UPPER 0x40
# define FT_PRINTF_OPTION_MIDDLE 0x80

# define FT_PRINTF_OPTION_SIGNSPACE 0x18

/*
** FT_PRINTF_LENMOD_*
**
** Values ored in the 'conversion' field of the 's_printf_format' structure.
** They give informations about the lenght of the variadic argument.
*/

# define FT_PRINTF_LENMOD_ADDRESS 0x40000000
# define FT_PRINTF_LENMOD_UNSIGNED 0x10000000

# define FT_PRINTF_LENMOD_DEFAULT FT_PRINTF_LENMOD_INT
# define FT_PRINTF_LENMOD_CHAR 0x1000
# define FT_PRINTF_LENMOD_SHORT 0x2000
# define FT_PRINTF_LENMOD_INT 0x4000
# define FT_PRINTF_LENMOD_LONG 0x8000
# define FT_PRINTF_LENMOD_LONGLONG 0x10000
# define FT_PRINTF_LENMOD_INTMAX 0x20000
# define FT_PRINTF_LENMOD_PTRDIFF 0x40000
# define FT_PRINTF_LENMOD_SIZE 0x80000

/*
** FT_PRINTF_IAP_*
**
** Special 'iap' values used in 'iap', 'fieldw_iap' and 'precision_iap' fields
** of the 's_printf_format' structure.
** FT_IAP_AUTO: va_list index not explicitely given, will be automatic.
** FT_IAP_UNDEFINED: value is already known (hard written in the format).
** FT_IAP_UNUSED: the field is unused.
*/

# define FT_PRINTF_IAP_AUTO 0
# define FT_PRINTF_IAP_UNDEFINED -1
# define FT_PRINTF_IAP_UNUSED -2

/*
** FT_PRINTF_CONV_CHARS
** FT_PRINTF_LENMOD_CHARS
**
** Defines wich characters are considered 'length modifiers' or 'conversion'
** when parsing formats.
*/

# define FT_PRINTF_CONV_CHARS "bBoudixXsScCpPnfFyYr"
# define FT_PRINTF_LENMOD_CHARS "lhLjtz"

/*
** FT_PRINTF_*_CHARS
**
** Conversion chars categories.
** Used to select the algorithm to apply to every conversion
*/

# define FT_PRINTF_NUMERIC_CHARS "bBdinouxXDOUp"
# define FT_PRINTF_FLOATS_CHARS "aAeEfFgG"
# define FT_PRINTF_WIDEABLESTR_CHARS "cCsS"
# define FT_PRINTF_UPPERISLONG_CHARS "DOU"

# define FT_PRINTF_OTHERS_CHARS "csyr"
# define FT_PRINTF_SIGNEDS_CHARS "diaefg"
# define FT_PRINTF_UNSIGNEDS_CHARS "bouxp"

# define FT_PRINTF_ADDRESS_CHARS "psSr"

#endif
