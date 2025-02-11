/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:07 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/30 09:56:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//Run the fractal generator. 
// usage : Usage :mandelbrot or julia <reel> <i> 
//julia exemple : 0 0.8; 0.37 0.1; -0.4  -0.59
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)
			&& valid_input(argv[2]) && valid_input(argv[3])))
	{
		init_fractal(&fractal, argv);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else 
	{
		ft_printf("Usage :\nmandelbrot\njulia <reel> <i>\n");
	}
	return (0);
}
