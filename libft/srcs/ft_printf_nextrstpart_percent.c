/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_onerstpart_percent                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:43:35 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:55:07 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** Parse the va_list index, flags, field width and precision:
*/

static int	iap_flags_w_p(int *cr_int, char **fmt, t_printf_rstpart *part)
{
	*cr_int = 0;
	ft_printf_popint(cr_int, fmt);
	if (ft_printf_popchar(fmt, '$'))
	{
		part->fmt->iap = ft_abs(*cr_int);
		*cr_int = 0;
	}
	while (ft_printf_addoptionflag(&part->fmt->options, fmt))
		(void)0;
	if (ft_printf_w_or_p(cr_int, &part->fmt->fieldw,
				&part->fmt->fieldw_iap, fmt))
		return (-1);
	if (ft_printf_popchar(fmt, '.'))
	{
		*cr_int = 0;
		while (**fmt == '0')
			*fmt += 1;
		if (ft_printf_w_or_p(cr_int, &part->fmt->precision,
					&part->fmt->precision_iap, fmt))
			return (-1);
	}
	else
		part->fmt->precision = -1;
	return (0);
}

static void	just_lenmod(char **fmt, t_printf_rstpart *part, char **mod)
{
	if (ft_strchr(FT_PRINTF_UPPERISLONG_CHARS, **fmt))
		part->fmt->conversion |= FT_PRINTF_LENMOD_LONG;
	if (ft_strchr(FT_PRINTF_NUMERIC_CHARS, **fmt))
		ft_printf_addconvmod_dinoux(&part->fmt->conversion, mod);
	else if (ft_strchr(FT_PRINTF_FLOATS_CHARS, **fmt))
		ft_printf_addconvmod_aefg(&part->fmt->conversion, mod);
	else if (ft_strchr(FT_PRINTF_WIDEABLESTR_CHARS, **fmt))
		ft_printf_addconvmod_cs(&part->fmt->conversion, mod);
	if (ft_strchr(FT_PRINTF_ADDRESS_CHARS, part->fmt->conversion & 0xFF))
		part->fmt->conversion |= FT_PRINTF_LENMOD_ADDRESS;
}

/*
** Parse lenght modifiers and conversion type:
*/

static int	lenmod_conv(char **fmt, t_printf_rstpart *part)
{
	char		*mod;

	mod = *fmt;
	while (ft_strchr(FT_PRINTF_LENMOD_CHARS, **fmt) && **fmt != '\0')
		*fmt += 1;
	part->fmt->conversion |= (unsigned int)(**fmt);
	just_lenmod(fmt, part, &mod);
	if (**fmt == 0)
		return (0);
	if (ft_isupper(part->fmt->conversion & 0xFF))
	{
		part->fmt->options |= FT_PRINTF_OPTION_UPPER;
		part->fmt->conversion = ft_tolower(part->fmt->conversion & 0xFF)
			| (part->fmt->conversion & 0xFFFFFF00);
	}
	(*fmt) += 1;
	return (0);
}

/*
** ft_printf_nextrstpart_percent():
**
** This function assume format[-1] was a '%' and parse the format flag.
** 'next_fmt' is set to be the end of format
*/

int			ft_printf_nextrstpart_percent(
					char **next_fmt, char *fmt, t_printf_rstpart *part)
{
	int			cr_int;

	if (ft_printf_popchar(&fmt, '%'))
	{
		*next_fmt = fmt;
		ft_memdel((void**)&part->fmt);
		return ((part->str = ft_strdup("%")) ? 0 : -1);
	}
	if (!(part->fmt = ft_memalloc(sizeof(t_printf_format))))
		return (-1);
	part->fmt->fieldw_iap = FT_PRINTF_IAP_UNUSED;
	part->fmt->precision_iap = FT_PRINTF_IAP_UNUSED;
	if (iap_flags_w_p(&cr_int, &fmt, part) < 0)
		return (-1);
	if (lenmod_conv(&fmt, part) < 0)
		return (-1);
	*next_fmt = fmt;
	return (0);
}
