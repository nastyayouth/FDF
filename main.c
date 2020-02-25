/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <eestell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 23:48:23 by eestell           #+#    #+#             */
/*   Updated: 2020/02/25 09:10:17 by eestell          ###   ########.fr       */
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
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	//return (0);
}
