/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:35:57 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/30 10:38:07 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//search the position of the pixel and attribute an color to it.
void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img ->img_pixels_ptr + offset) = color;
}

//init data for julia or mandelbrot
void	init_c(t_complex z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp("mandelbrot", fractal->name, 10))
	{
		c->x = z.x;
		c->y = z.y;
	}
	else
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
}

//first of all, we have to "resize" the screen to have correspondant value.
//we want that every pixel correspond to a value beetween -2 and 2 at start>.
//z is the value of the pixel on the scale, c is something that we add.
// we calculate the formulq z^2 + c
// the color of each pixel depend of the number of iteration needed to
//get out a circle of 2 units if get out imediatly BLACK get out after 
// great amount of iteration => CYAN if it never get out, YELLOW
void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, -2, +2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	init_c(z, &c, fractal);
	while (i < fractal->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = map(i, BLACK, CYAN, fractal->iteration);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, YELLOW_2);
}

//define each pixels of the window before pushing it.
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.img_ptr, 0, 0);
}
