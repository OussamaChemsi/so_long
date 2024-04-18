#include <mlx.h>

int handler(int key,t_data *data)
{
    if (key == 9)
    {
        mlx_display_distroy();
        mlx_distroy_window(data->mlx, data->win);
    }
    if (key ==  19)
        move_up()
    if  ()
}
int main()
{
    void *mlx;
    void *win;
    void *player;
    void *wall;

    mlx = mlx_init();

    win = mlx_new_window(mlx, 500 , 500, "so_long");

    player = xpm_file_to_image(mlx ,"textures/asdasd.xpm", witdh, hight);
    mlx_hook(mlx,win, 1L<<0, 2, handler, data);

    mlx_loop(mlx);

}
//11111111111111
//10p00000000001
//1101111111111
//1111111111111