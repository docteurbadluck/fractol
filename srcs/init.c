/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/30 09:57:51 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//init value and convert if necessary the input in double
static void	init_value(t_fractal *fractal, char **argv)
{
	fractal->zoom = 1.0;
	fractal->shift_y = 0;
	fractal->shift_x = 0;
	fractal->iteration = 42;
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = ft_atod(argv[2]);
		fractal->julia_y = ft_atod(argv[3]);
	}
	else 
	{
		fractal->julia_x = 0;
		fractal->julia_y = 0;
	}
}

//init mlx, the window and the image
//init also all the usefull value of the fractal
void	init_fractal(t_fractal *fractal, char **argv)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		exit(EXIT_FAILURE);
	fractal->name = argv[1];
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->win_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		exit(EXIT_FAILURE);
	}
	fractal->img.img_pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_len, &fractal->img.endian);
	init_value(fractal, argv);
	event_init(fractal);
}
