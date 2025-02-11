/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:48:29 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/30 10:47:57 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// free the allocated space for the image, the screen and the display.
//(display is the connection beetween the server x and the program)
static void	close_clean(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

//moove camera and allow calcul.
// we need to multiply the shift by the zoom to going to far.
static int	key_press_hook(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		close_clean(fractal);
	else if (keycode == XK_Left)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keycode == XK_Right)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keycode == XK_Up)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keycode == XK_Down)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keycode == 65451)
		fractal->iteration += 10;
	else if (keycode == 65453)
		fractal->iteration -= 10;
	fractal_render(fractal);
	return (0);
}

//Really important to keep x and y, otherwise, the function write
//over the argument that you wrote.
static int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
		fractal->zoom *= 1.5;
	if (button == 4)
		fractal->zoom *= 0.5;
	fractal_render(fractal);
	return (0);
}

static int	close_window(t_fractal *fractal)
{
	close_clean(fractal);
	return (0);
}

void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, KeyPress, KeyPressMask, key_press_hook, fractal);
	mlx_hook(fractal->win_ptr, 17, NoEventMask, close_window, fractal);
	mlx_mouse_hook(fractal->win_ptr, mouse_handler, fractal);
}
