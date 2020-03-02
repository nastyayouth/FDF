/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <eestell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 23:48:23 by eestell           #+#    #+#             */
/*   Updated: 2020/03/02 15:13:43 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, fdf *data)
{
	printf("%d\n", key);
	if (key == 126)
		data->shift_y -=10;
	if (key == 125)
		data->shift_y +=10;
	if (key == 123)
		data->shift_x -=10;
	if (key == 124)
		data->shift_x +=10;
	if (key == 27)
		data->zoom -=10;
	if (key == 24)
		data->zoom +=10;
	if (key == 256)
		data->angle -=0.1;
	if (key == 269)
		data->angle +=0.1;
	if (key == 4)
		data->transform +=0.5;
	if (key == 37)
		data->transform-=0.5;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);	
	return (0);
}

int main (int argc, char **argv)
{
	fdf		*data;

	if (argc != 2)
		return (0);
	
	data = (fdf*)malloc(sizeof(fdf));

	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->shift_y = 200;
	data->shift_x = 200;
	data->angle=0.8;
	printf("%d", data->shift_y);
	printf("%d", data->shift_x);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);	
	mlx_loop(data->mlx_ptr);
	
	
	return (0);
}
