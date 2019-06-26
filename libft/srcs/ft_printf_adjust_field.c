/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adjust_field.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:34:29 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:08:23 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_types.h"

/*
** Handle undetermined cases (according to moulitest) and not behaving the same
** with the terminal printf, but explicitely saidto handle the 0 flag this
** way in the manual.
*/

char		get_field_c(t_printf_rstpart *p)
{
	if (p->fmt->fieldw < 0)
		return (' ');
	if (!(p->fmt->options & FT_PRINTF_OPTION_ZERO_PADDING))
		return (' ');
	if (ft_strchr(FT_PRINTF_NUMERIC_CHARS, (char)(p->fmt->conversion)))
		return (' ');
	if (ft_strchr(FT_PRINTF_FLOATS_CHARS, (char)(p->fmt->conversion)))
		return (' ');
	return ('0');
}

/*
** ft_printf_adjust_field()
**
** Resize *str and padd with zeros or spaces according to field_options,
** to fit in a string at least of size 'fieldw'.
** Return count of chars added to the string.
*/

int			ft_printf_adjust_field(t_printf_rstpart *p)
{
	int		prev_len;
	char	*new_str;
	char	field_c;

	if (p->fmt->fieldw > 0 && p->fmt->options & FT_PRINTF_OPTION_LEFT_ALIGN)
		p->fmt->fieldw *= -1;
	if (p->fmt->fieldw_iap == FT_PRINTF_IAP_UNUSED)
		return (0);
	prev_len = ft_strlen(p->str);
	if ((p->fmt->fieldw >= 0 && p->fmt->fieldw <= prev_len))
		return (0);
	if ((p->fmt->fieldw < 0 && -p->fmt->fieldw <= prev_len))
		return (0);
	if (p->fmt->options & FT_PRINTF_OPTION_LEFT_ALIGN & p->fmt->fieldw > 0)
		p->fmt->fieldw *= -1;
	field_c = get_field_c(p);
	if (!(new_str = ft_strminfieldc(p->str, p->fmt->fieldw, field_c)))
		return (-1);
	free(p->str);
	p->str = new_str;
	return (0);
}
