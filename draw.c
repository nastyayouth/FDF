/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <eestell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:52:13 by eestell           #+#    #+#             */
/*   Updated: 2020/03/07 21:52:08 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#define MAX1(a,b)(a>b ? a: b)
#define MOD(a) ((a < 0) ? -a : a)
float   mod(float  i)
{
    return(i < 0) ? -i : i;
}

void    isometric(float *x, float *y, int z, fdf *data)
{
    *x = (*x - *y) * cos (data->angle);
    *y = (*x + *y) * sin (data->angle) - z;
}  

void        bresenbam(float x, float y, float x1, float y1, fdf *data)
{
    float   x_step;
    float   y_step;
    int     max;
    int     z;
    int     z1;
    int     x_n;
    int     y_n;

    y_n = y;
    x_n = x;
       
    z = (data->z_matrix[(int)y][(int)x]);
    z1 = (data->z_matrix[(int)y1][(int)x1]);

    
    z*=data->transform;
    z1*=data->transform;
        
    x*= data->zoom;
    y*= data->zoom;
    x1*= data->zoom;
    y1*= data->zoom;

    
    isometric(&x, &y, z, data);
    isometric(&x1, &y1, z1, data);
   
    x +=data->shift_x;
    y +=data->shift_y;
    x1 +=data->shift_x;
    y1 +=data->shift_y;
    x_step = x1 - x;
    y_step = y1 - y;

       
    max = MAX1((MOD(x_step) ), (MOD(y_step) ));
    x_step =  (x_step / max);
    y_step = (y_step / max); 
   
   

    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color[(int)y_n][(int)x_n]);
        x += x_step;
        y += y_step;
    }
}

void    draw(fdf *data)
{
    int     x;
    int     y;

    menu(data);
    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                bresenbam(x, y, x + 1, y, data);
            if (y < data->height - 1)
                bresenbam(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}