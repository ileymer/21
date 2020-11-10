# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 13:31:02 by dgeonosi          #+#    #+#              #
#    Updated: 2020/10/31 20:28:05 by dgeonosi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker
NAME_B = bonus

FRAEMWORKS = -framework OpenGL -framework AppKit

SOURCES_LIST = src/general.c \
				src/parse.c

SOURCES_LIST_P = src/alg.c \
					src/alg2.c \
					src/alg3.c \
					src/check.c \
					src/fun.c \
					src/fun2.c \
					src/mas.c \
					src/push_swap.c

SOURCES_LIST_C = src/checker.c \
					src/func.c \
					src/funcc.c \
					src/func2.c

SOURCES_LIST_B = src_bonus/bonus.c \
					src_bonus/distrib.c \
					src_bonus/funv.c \
					src_bonus/funv2.c \
					src_bonus/run.c \
					src_bonus/visual.c

					

SURPL_O = src/general.o \
				src/parse.o

SURPL_O_P = src/alg.o \
					src/alg2.o \
					src/alg3.o \
					src/check.o \
					src/fun.o \
					src/fun2.o \
					src/mas.o \
					src/push_swap.o

SURPL_O_C = src/checker.o \
					src/func.o \
					src/func2.o

SURPL_O_B = src_bonus/bonus.o \
					src_bonus/distrib.o \
					src_bonus/funv.o \
					src_bonus/funv2.o \
					src_bonus/run.o \
					src_bonus/visual.o

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = libft/libft.a
INCLUDES_V = libft/libft.a minilibx_macos/libmlx.a

OBJS = $(SOURCES_LIST:.c=.o)
OBJS_P = $(SOURCES_LIST_P:.c=.o)
OBJS_C = $(SOURCES_LIST_C:.c=.o)
OBJS_B = $(SOURCES_LIST_B:.c=.o)

all : $(NAME_P) $(NAME_C) $(NAME_B)

$(NAME_P): $(OBJS) $(OBJS_P)
	$(CC) -o $(NAME_P)  $(SOURCES_LIST) $(SOURCES_LIST_P) $(FLAGS)
$(NAME_C): $(OBJS) $(OBJS_C)
	$(CC) -o $(NAME_C)  $(SOURCES_LIST) $(SOURCES_LIST_C) $(FLAGS) $(INCLUDES)
$(NAME_B): $(OBJS_B)
	$(CC) -o $(NAME_B)  $(SOURCES_LIST_B) $(FLAGS) $(INCLUDES_V) $(FRAEMWORKS)

clean:
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)
	rm -rf $(SURPL_O_P) 
	rm -rf $(OBJS_P)
	rm -rf $(SURPL_O_C) 
	rm -rf $(OBJS_C)
	rm -rf $(SURPL_O_B) 
	rm -rf $(OBJS_B)
	rm -rf src/*.o
	rm -rf src_bonus/*.o

fclean: clean
	rm -f $(NAME_P)
	rm -f $(NAME_C)
	rm -f $(NAME_B)

re: fclean all