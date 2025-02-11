/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/30 10:55:04 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define HEIGHT 800
# define WIDTH 800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	float	zoom;
	float	shift_x;
	float	shift_y;
	int		iteration;
	double	julia_x;
	double	julia_y;
}		t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define CYAN        0x00FFFF
# define YELLOW      0xFFFF00
# define YELLOW_2      0xFFFFE0

void		init_fractal(t_fractal *fractal, char **argv);
void		event_init(t_fractal *fractal); 
void		fractal_render(t_fractal *fractal);
t_complex	square_complex(t_complex a);
t_complex	sum_complex( t_complex a, t_complex b);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
double		ft_atod(char *str);
int			valid_input(char *str);

#endif