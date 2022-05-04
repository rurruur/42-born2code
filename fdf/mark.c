#include "fdf.h"

void	setImgColor(void *mlx_ptr, t_img *img_info, int color)
{
	if (img_info->bpp != 32)
		color = mlx_get_color_value(mlx_ptr, color);
	if (img_info->endian == 1)  // big endian
	{
		img_info->buffer[0] = (color >> 24);
		img_info->buffer[1] = (color >> 16) & 0xFF;
		img_info->buffer[2] = (color >> 8) & 0xFF;
		img_info->buffer[3] = (color) & 0xFF;
	}
	else if (img_info->endian == 0)  // little endian
	{
		img_info->buffer[0] = (color) & 0xFF;
		img_info->buffer[1] = (color >> 8) & 0xFF;
		img_info->buffer[2] = (color >> 16) & 0xFF;
		img_info->buffer[3] = (color >> 24);
	}
}

void	mark_dot(void *mlx_ptr, int x, int y, int color, void* win_ptr)
{
	t_img	img_info;

	img_info.img_ptr = mlx_new_image(mlx_ptr, 1, 1);
	img_info.buffer = mlx_get_data_addr(img_info.img_ptr, &(img_info.bpp), &(img_info.line_bytes), &(img_info.endian));
	setImgColor(mlx_ptr, &img_info, color);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_info.img_ptr, x, y);
}