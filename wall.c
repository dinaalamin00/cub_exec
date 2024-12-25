#include "cub3d.h"
/* 
- load textures
- in the interset point return the type of intersection if its vertical or horizontal
- checking the type of intersection flag to determine the textures to be used, vertical::east/west, horizontal::north/south
- to decide which one of the two textures after knowing the intersection type;
    for vertial intersection check intersect.x, for horizontal check intersect.y
-
*/
void    load_text(t_cub *cub, t_texture *text, char *filename)
{
    text->img = mlx_xpm_file_to_image(cub->mlx, filename, &text->width, &text->height);
    if (!text->img)
    {
        printf("error in text %s\n", filename);
        exit (1);
    }
    text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel, &text->line_length, &text->endian);
}

void    init_text(t_cub *cub)
{
    load_text(cub, &cub->n_text, cub->map.north_txt);
    load_text(cub, &cub->s_text, cub->map.south_txt);
    load_text(cub, &cub->e_text, cub->map.east_txt);
    load_text(cub, &cub->w_text, cub->map.west_txt);
}