#include "fdf.h"

void	menu(fdf *data)
{
	char *menu;

	menu = "MOVE:		left, right, up, down";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0xd7cae4, menu);
	menu = "ZOOM:		 + / -";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 40, 0xd7cae4, menu);
	menu = "ROTATION: 	ctr_left, ctrl_right";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 60, 0xd7cae4, menu);
	menu = "Z_SCALE: 	L, H";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 80, 0xd7cae4, menu);
	//menu = "f: full screen mode";
	//mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 80, 0xd7cae4, menu);
}