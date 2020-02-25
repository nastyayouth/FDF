#!/bin/bash
gcc *.c libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
./a.out 42.fdf
