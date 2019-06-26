/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorwheel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:51:40 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/16 19:38:00 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a color from an int (as an integer degrees), just for style, in the
** folowing ranges of colors:
** -> R = 255
** -> R = 255, G = 0-255, B=0       60 values  0-60
** -> R = 255-0, G = 255, B=0       60 values  60-120
** -> G = 255
** -> R = 0, G = 255, B=0-255       60 values  120-180
** -> R = 0, G = 255-0, B=255       60 values  180-240
** -> B = 255
** -> R = 0-255, G = 0, B = 255     60 values  240-300
** -> R = 255, G = 0, B = 255-0     60 values  300-360
*/

int				ft_colorwheel(int degrees)
{
	int		r;
	int		g;
	int		b;

	degrees = (int)((unsigned int)degrees % 360);
	r = (degrees >= 300 || degrees <= 60) ? 0xFF : 0;
	g = (degrees >= 60 && degrees <= 180) ? 0xFF : 0;
	b = (degrees >= 180 && degrees <= 300) ? 0xFF : 0;
	if (degrees > 0 && degrees < 60)
		g = (degrees) * 0xFF / 60;
	else if (degrees > 180 && degrees < 240)
		g = (240 - degrees) * 0xFF / 60;
	if (degrees > 60 && degrees < 120)
		r = (120 - degrees) * 0xFF / 60;
	else if (degrees > 240 && degrees < 300)
		r = (degrees - 240) * 0xFF / 60;
	if (degrees > 120 && degrees < 180)
		b = (degrees - 120) * 0xFF / 60;
	else if (degrees > 300 && degrees < 360)
		b = (360 - degrees) * 0xFF / 60;
	return (ft_argb(0, r, g, b));
}
