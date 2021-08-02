/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:14:22 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 20:52:22 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include <math.h>
# include "../minilibx_mms_20200219/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 32
# define BYTES_PER_PIXEL 3
# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
}					t_vector;

typedef struct		s_sphere
{
	t_color			color;
	t_vector		position;
	float			radius;
}					t_sphere;

typedef struct		s_ray
{
	t_vector		start;
	t_vector		direction;
}					t_ray;

typedef struct		s_camera
{
	t_vector		origin;
	t_vector		direction;
	float			screen_dist;
	t_vector		up;
	t_vector		target;
	t_vector		right;
	t_vector		normalized_r;
	t_vector		forward;
	t_vector		normalized_f;
	float			fov;
	float			aspect;
}					t_camera;

typedef struct		s_plane
{
	t_color			color;
	t_vector		plane_point;
	t_vector		normal;
}					t_plane;

typedef struct		s_light
{
	float			brightness;
	t_vector		position;
	t_color			color;
}					t_light;

typedef struct		s_ambient
{
	float			brightness;
	t_color			color;
}					t_ambient;

typedef struct		s_square
{
	float			size;
	t_vector		normal;
	t_vector		center;
	t_color			color;
}					t_square;

typedef struct		s_triangle
{
	t_vector		a;
	t_vector		b;
	t_vector		c;
	t_color			color;
	t_vector		normal;
}					t_triangle;

typedef struct		s_cylinder
{
	t_vector		point;
	t_vector		normal;
	float			diameter;
	float			height;
	t_color			color;
}					t_cylinder;

typedef struct		s_values
{
	int				your_obj;
	t_vector		tvec;
	t_vector		v1;
	float			discr1;
	float			b1;
	float			a1;
	float			t0;
	float			t1;
	t_vector		cross;
	t_vector		cross2;
	int				stride;
	int				w_i_b;
	int				padding_size;
	int				cy_i;
	int				cy_x;
	int				tr_i;
	int				tr_x;
	int				sq_i;
	int				sq_x;
	int				sp_x;
	t_cylinder		*cylinder;
	float			temp_red;
	float			temp_green;
	float			temp_blue;
	t_triangle		*triangle;
	t_square		*square;
	t_ambient		ambient;
	float			red;
	float			blue;
	float			green;
	t_ray			light_ray;
	t_light			*light;
	t_light			current_light;
	t_vector		newstart;
	t_vector		n;
	t_plane			*plane;
	t_camera		*camera;
	t_ray			ray;
	t_sphere		*sphere;
	void			*mlx;
	void			*win;
	void			*image;
	unsigned char	*img;
	char			*addr;
	char			*str;
	char			*s;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				fd;
	int				index;
	int				argc_value;
	int				width;
	int				height;
	int				y;
	int				x;
	float			mark_radius;
	float			t;
	float			t2;
	unsigned char	*file_header;
	unsigned char	*info_header;
	int				obj;
	float			radian;
	float			discr;
	int				i;
	float			p;
	float			a;
	float			b;
	float			c;
	int				level;
	float			coef;
	float			reflect;
	int				c_count;
	int				sp_count;
	int				tr_count;
	int				pl_count;
	int				sq_count;
	int				cy_count;
	int				sp_i;
	int				pl_i;
	int				c_x;
	int				c_i;
	int				pl_x;
	int				mark;
	int				ca;
	int				l_count;
	int				l_x;
	int				au;
	int				r_count;
	int				a_count;
	int				len;
}					t_values;

void				ft_generate_bmp_image(t_values *val);
void				ft_val_values(t_values *val, int i);
void				ft_ray_values(t_values *val);
void				my_mlx_pixel_put(t_values *val, int x, int y, int color);
t_vector			ft_vector_sub(t_vector v1, t_vector v2);
float				ft_vector_dot(t_vector v1, t_vector v2);
int					ft_intersect(t_values *val, int a);
void				ft_build_image(t_values *val, int a);
void				ft_build_empty_image(t_values *val);
unsigned char		*ft_fileheader(t_values *val, int stride);
unsigned char		*ft_infoheader(t_values *val);
void				ft_bmp_error(t_values *val);
void				ft_generate_bmp_image(t_values *val);
void				ft_malloc_error(t_values *val, int a);
int					ft_strcmp(char *str);
int					ft_close(int keycode, t_values *val);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_check_scene(char *str);
void				ft_check_scene_values(t_values *val, char *str);
void				ft_check_lines(char *str, t_values *val);
int					ft_atoi(char *str, t_values *val);
char				*ft_strndup(char *s1, t_values *val);
int					ft_strchr(char *str);
char				*ft_get_line(t_values *val);
char				*ft_get_rest(t_values *val);
int					get_next_line(int fd, char **line, t_values *val);
int					ft_strlen(char *s);
void				*ft_memmove(void *dst, void *src, size_t len);
char				*ft_strjoin(t_values *val, char *s2);
float				ft_atof(char *str, t_values *val);
char				*ft_strndup_2(char *s1, t_values *val);
char				*ft_magic(char *str, t_values *val);
char				*ft_magic_2(char *str, t_values *val);
char				*ft_magic_3(char *str, t_values *val);
char				*ft_magic_4(char *str, t_values *val);
void				ft_identifier(char *str, t_values *val);
int					key_hook(int keycode, t_values *val);
int					key_hook_2(int keycode, t_values *val);
t_vector			ft_vector_cross(t_vector v1, t_vector v2);
t_vector			ft_vector_normalize(t_vector v);
float				ft_vector_length(t_vector v);
t_vector			ft_vector_add(t_vector v1, t_vector v2);
t_vector			ft_vector_scalar(t_vector v1, float s);
t_vector			ft_vector_division(t_vector v1, float d);
char				*ft_magic_5(char *str, t_values *val);
char				*ft_second_block_c(char *str, t_values *val);
char				*ft_first_block_c(char *str, t_values *val);
char				*ft_third_block_c(char *str, t_values *val);
char				*ft_first_block_sp(char *str, t_values *val);
char				*ft_third_block_sp(char *str, t_values *val);
char				*ft_fourth_block_sp(char *str, t_values *val);
char				*ft_magic_6(char *str, t_values *val);
int					ft_plane(t_values *val, int a);
char				*ft_first_block_pl(char *str, t_values *val);
char				*ft_second_block_pl(char *str, t_values *val);
char				*ft_fourth_block_pl(char *str, t_values *val);
int					ft_find_intersect(t_values *val);
void				ft_find_intersect_normal(t_values *val);
void				ft_find_light_value(t_values *val, int a);
void				ft_find_new_setup(t_values *val);
void				ft_color(t_values *val);
char				*ft_fourth_block_l(char *str, t_values *val);
char				*ft_secondvalue_block_l(char *str, t_values *val);
char				*ft_first_block_l(char *str, t_values *val);
char				*ft_magic_7(char *str, t_values *val);
char				*ft_secondvalue_block_a(char *str, t_values *val);
char				*ft_fourth_block_a(char *str, t_values *val);
int					ft_intersect_2(t_values *val, float q, t_vector v, int a);
int					ft_square(t_values *val, int a);
int					ft_square_2(t_values *val, float q, t_vector v, int a);
void				ft_start_checking(int argc, t_values *val, char **argv);
char				*ft_first_block_sq(char *str, t_values *val);
char				*ft_second_block_sq(char *str, t_values *val);
char				*ft_third_block_sq(char *str, t_values *val);
char				*ft_fourth_block_sq(char *str, t_values *val);
int					ft_triangle(t_values *val, int a);
int					ft_triangle_2(t_values *val, float q, t_vector v, int a);
int					ft_cylinder(t_values *val, int a);
int					ft_cylinder_2(t_values *val, int a);
int					ft_cylinder_3(t_values *val, int a);
int					ft_cylinder_shadow(t_values *val, float q,
						t_vector v, int a);
int					ft_cylinder_shadow_2(t_values *val, float q,
						t_vector v1, int a);
int					ft_cylinder_shadow_3(t_values *val, float q,
						t_vector v1, int a);
void				ft_c(char *str, t_values *val);
void				ft_sp(char *str, t_values *val);
void				ft_pl(char *str, t_values *val);
void				ft_l(char *str, t_values *val);
void				ft_a(char *str, t_values *val);
void				ft_sq(char *str, t_values *val);
void				ft_malloc(t_values *val);
void				ft_n_c_cylinder(t_values *val);
void				ft_n_c_plane_square(t_values *val);
void				ft_free(t_values *val);
int					ft_plane_2(t_values *val, float q, t_vector v, int a);
void				ft_tr(char *str, t_values *val);
char				*ft_first_block_tr(char *str, t_values *val);
char				*ft_first_block_tr_2(char *str, t_values *val);
char				*ft_first_block_tr_3(char *str, t_values *val);
char				*ft_fourth_block_tr(char *str, t_values *val);
void				ft_cy(char *str, t_values *val);
char				*ft_first_block_cy(char *str, t_values *val);
char				*ft_second_block_cy(char *str, t_values *val);
char				*ft_third_block_cy(char *str, t_values *val);
char				*ft_third_block_cy_2(char *str, t_values *val);
char				*ft_fourth_block_cy(char *str, t_values *val);
void				key_square_size(int keycode, t_values *val);
void				ft_check_scene_rules(t_values *val);
void				ft_zero(t_values *val);
int					ft_cylinder_3_equation(t_values *val, int a,
					float t, t_vector point);
int					ft_cylinder_shadow_3_equ(t_values *val);
void				key_square_size(int keycode, t_values *val);
void				key_cylinder_height(int keycode, t_values *val);
void				key_sphere_radius(int keycode, t_values *val);
char				*ft_magic_4(char *str, t_values *val);
char				*ft_magic_6(char *str, t_values *val);
void				key_rotate_camera_3(int keycode, t_values *val);
void				key_rotate_camera_2(int keycode, t_values *val);
void				move_square(int keycode, t_values *val, int i);
void				move_sphere(int keycode, t_values *val, int i);
void				move_triangle(int keycode, t_values *val, int i);
void				move_cylinder(int keycode, t_values *val, int i);
void				move_cylinder_2(int keycode, t_values *val, int i);
void				move_plane(int keycode, t_values *val, int i);
void				move_light(int keycode, t_values *val, int i);
void				move_square_3(t_values *val, int i);
void				choose_obj(int keycode, t_values *val);
int					ft_cyplane(t_vector normal, t_vector point, t_vector start);
int					exit_hook(t_values *val);
t_vector			ft_create_vector(float a, float b, float c);
t_vector			ft_return_point(t_values *val, int a, float x);
float				ft_return_denom(t_values *val, t_vector v1, int a);
int					ft_cylinder_2_equation(t_values *val, int a, float t);
int					ft_cylinder_shadow_2_equ(t_values *val);
void				ft_get_t0(t_values *val, float b, float discr);
int				ft_strlen_2(char *s, t_values *val);
void				ft_check_right_values(t_values *val);
void				ft_check_right_values_4(t_values *val, int a);

#endif
