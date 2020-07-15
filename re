NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRC = ft_strncpy.c ft_strcpy.c ft_atoi.c ft_strcmp.c ft_strdup.c ft_strlen.c \
	  ft_strncmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strstr.c \
	  ft_strnstr.c ft_strchr.c ft_strrchr.c ft_putchar.c ft_putchar_fd.c \
	  ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_bzero.c ft_memset.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_memdel.c ft_strdel.c \
	  ft_strclr.c ft_strsub.c ft_striter.c ft_striteri.c ft_strmap.c \
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strtrim.c \
	  ft_itoa.c ft_strsplit.c

OBJ = ft_strncpy.o ft_strcpy.o ft_atoi.o ft_strcmp.o ft_strdup.o ft_strlen.o \
	  ft_strncmp.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strstr.o \
	  ft_strnstr.o ft_strchr.o ft_strrchr.o ft_putchar.o ft_putchar_fd.o \
	  ft_putstr.o ft_putstr_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
	  ft_putnbr_fd.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
	  ft_isprint.o ft_toupper.o ft_tolower.o ft_bzero.o ft_memset.o \
	  ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o \
	  ft_memalloc.o ft_memdel.o ft_strnew.o ft_memdel.o ft_strdel.o \
	  ft_strclr.o ft_strsub.o ft_striter.o ft_striteri.o ft_strmap.o \
	  ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strjoin.o ft_strtrim.o \
	  ft_itoa.o ft_strsplit.o
HEAD = libft.h

all: $(NAME)

$(NAME):
	gcc $(FLAG) -I $(HEAD) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all




#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_adds
{
	int		**z;
	int		**z_copy;
	int		**color;
	int		n;
	int		m;
	int		k;
	int		zoom;
	double	angle;
	int		movey;
	int		move;
	int		color1;
	int		color2;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_adds;

t_adds			*read_map(char *file);
void			print_error(int err);
void			free_split(char **part);
void			d(t_adds *mass, int m[2], int x1, int y1);
int				fxi(int xy[5], t_adds *mass, int i, int j);
int				fyi(int xy[5], t_adds *mass, int i, int j);
double			coss(int x, int y, t_adds *mass);
double			sinn(int x, int y, t_adds *mass, int l);
int				deal_key(int key, t_adds *param);
int				color1(int k);
int				color2(int k);
void			hight(t_adds *m, int k);
int				ft_atoi_16(char *str);
int				ft_isnumber(char *str, int base);
void			print_menu(t_adds *param);
int				gore(t_adds *mass);

#endif

