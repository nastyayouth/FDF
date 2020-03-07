/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <eestell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:02:49 by eestell           #+#    #+#             */
/*   Updated: 2020/03/07 20:45:55 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		ft_validate(char *line)
{
	int		i;
	int		j;
	int		sign;

	sign = 0;

	i = 0;

	while (line[i] != '\0')
	{
		
		j = 1;
		if (line[i] == ',' && (line[i-1]>='0' && line[i-1] <='9') && line[i+1] == '0' && line[i+2] == 'x')
		{
			i+=3;
			while (line[i]!= ' ')
			{
				if ((line[i] <'0' || line[i] > '9'))
					if ((line[i] < 'A' || line[i] > 'Z' || j > 7) && line[i] != '0' && line[i] != ' ' )					
						return (0);
				i++;
				j++;
			}

		}
		else
		{
			if ((line[i] <'0' || line[i] > '9' || line[i]== '-') && line[i] != ' ' && line[i] != '\0' && line[i] != ',')
			{
				if (line[i] == '-')
				{
					sign++;
				}
				else 
					return (0);
				if (sign > 1)
					return (0);
			}
		}
		sign = 0;

		i++;
			
	}
	return (1);
}
int		get_height(char	*file_name)
{
	char *line = NULL; /* added = NULL*/
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char	*file_name)
{
	int		width;
	int		fd;
	char	*line;
	int		i = 0;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wdcounter(line,' '); 
	while (get_next_line(fd, &line))
	free(line);
	close(fd);
	return(width);
}

void fill_matrix(int *z_line, const char *line, int *colored)
{
	char	**nums;
	int		i;
	int		n;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while(nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);

		//colored[i] = (int)ft_strchr(nums[i], ',');
		//colored[i] = 0xff0000;
		if (ft_strchr(nums[i], ','))
			{
				colored[i] = (int)ft_strchr(nums[i], ',');
				//printf("%d  ", colored[i]);
			}
		else
			colored[i] = 0xffff00;	
		//printf ("%d\n",colored[i]);
		/*TEST COLOR!!!!*/
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	read_file(char *file_name, fdf *data)
{
	int		fd;
	char	*line = NULL;
	int		i;
	int		len;
	int		test =  1;

	len = -1;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int**)malloc(sizeof(int*)*(data->height + 1));
	data->color = (int**)malloc(sizeof(int*)*(data->height + 1)); //
	i = 0;
	while (i <= data->height)
	{
		data->z_matrix[i] = (int*)malloc(sizeof(int) * (data->width + 1));
		data->color[i] = (int*)malloc(sizeof(int) * (data->width + 1)); //
		i++;
	}
		
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		printf("%d", test);
		if (test != 1)
			return (0);	
		fill_matrix(data->z_matrix[i], line, data->color[i]);
		/*if (ft_wdcounter(line, ' ') != (data->width))
		{
			printf("%d\n", data->width);
			printf("%d", ft_wdcounter(line, ' '));

		
		}*/
			
		if (!ft_validate(line))
			return (0);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
	data->color[i] = NULL;
	return (1);
}