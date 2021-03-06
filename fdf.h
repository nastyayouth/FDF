#ifndef FDF_H
# define FDF_H
#include "libft/libft.h"
#include <math.h>
#include "minilibx_macos/mlx.h"
#include <stdio.h> /*dot foget to dell printf*/
#include <fcntl.h>
# define PRM matrix[0][0]
//#include "get_next_line.h"

typedef		struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		**color;
	char	f_color;
	int		shift_x;
	int		shift_y;
	float	angle;
	float	transform;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

int			read_file(char *file_name, fdf *data);
void		bresenbam(float x, float y, float x1, float y1, fdf *data);
void    	draw(fdf *data);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dest, char const *src);
void		menu(fdf *param);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
long 		ft_strtol(const char *nptr, char **endptr, register int base);
int			ft_toupper(int c);




#endif
