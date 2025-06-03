/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:35:29 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 14:15:48 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# include "Get_Next_Line/get_next_line.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef WIDTH
#  define WIDTH 1024
# endif

# ifndef HEIGHT
#  define HEIGHT 768
# endif

typedef struct s_ray
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;

	int				map_x;
	int				map_y;

	double			side_dist_x;
	double			side_dist_y;

	double			delta_dist_x;
	double			delta_dist_y;

	int				step_x;
	int				step_y;

	int				hit;
	int				side;

	double			perp_wall_dist;

	int				line_height;
	int				draw_start;
	int				draw_end;
	int				real_draw_start;
}					t_ray;

typedef struct s_pos
{
	float			x;
	float			y;
	float			fov;
	float			angle;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
}					t_pos;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				texture;
	bool			mouse_locked;
	double			last_mouse_x;
	int				scale_minimap;
	mlx_image_t		*img;
	mlx_image_t		*minimap_img;
	mlx_image_t		*player_img;
	mlx_texture_t	*textures[4];
	t_pos			pos;
	t_ray			ray;
}					t_game;

typedef struct s_info
{
	t_pos			pos;
	t_game			*game;
	int				map_height;
	int				map_width;
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	int				depth;
	int				floor_color;
	int				ceiling_color;
}					t_info;

// PARSING
void				parsing(int argc, char **argv, t_info *info);
void				parsing_arguments(int argc);
void				parsing_extension(char *argv);
void				parsing_file(char *argv);
int					cut_info(char *str, char **info);
int					take_info(char *copymap, char *str, char **info);
int					take_infos(char *copymap, t_info *info);
int					check_map(int fd, t_info *info);
int					stock_map(int fd, t_info *info, int *coutline);
void				copy_map(int fd, t_info *info, int coutline, int skipline);
void				verif_map(t_info *info);
void				flood_fill(char **str, t_info *info);
void				copy_map2(char ***str, t_info *info, int countline);
void				parsing_map(char *argv, t_info *info);
int					set_rgb_color(t_info *info, char c);

// UTILS
void				ft_putstr(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_strlen_with_newline(char *str);
int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
void				clean_exit(int fd, char *str);
void				exit_with_error(int fd, t_info *info, char *error_msg,
						char *str);
void				free_info_with_error_msg(t_info *info, char *msg);

	// INIT_FREE

void				init_info(t_info *info);
void				init_tab_infos(char ***infos, t_info *info, char **texture);
void				free_tab(char **tab);
void				free_info(t_info *info);
void				init_orientation(t_info *info);

// GAME
void				launch_game(t_info *info);
int					init_mlx_context(t_info *info);
void				ft_raycasting(void *param);
void				key_hook(mlx_key_data_t keydata, void *param);
void				ft_move(t_info *info);
void				get_movement_vector(t_info *info, int key, float *dx,
						float *dy);
void				ft_cursor_move(t_info *info);
void				ft_camera(t_info *info);
void				init_ray(t_ray *ray, t_info *info, int x);
void				calc_step_and_side_dist(t_ray *ray, t_info *info);
void				perform_dda(t_ray *ray, t_info *info);
void				calc_perp_wall_dist(t_ray *ray, t_info *info);
void				calc_line_height(t_ray *ray);
void				put_pixel(t_info *info, int x, int y, int color);
void				draw_wall_column(t_info *info, t_ray *ray, int x);
void				draw_texture_column(t_info *info, t_ray *ray, int x);
mlx_texture_t		*select_wall_texture(t_info *info, t_ray *ray);
void				free_textures(t_info *info);
int					init_textures(t_game *game, t_info *info);
int					get_map_height(char **map);
int					get_map_width(char **map, int map_height);
int					calculate_minimap_scale(int window_width, int window_height,
						int map_width, int map_height);
void				draw_rect_filled(mlx_image_t *img, int pos[2], int scale,
						uint32_t color);
void				draw_minimap(t_info *info, mlx_image_t *img, int scale);

#endif