NAME = libftprintf.a



SRC = ft_printf.c nachalo.c type_di.c type_ldi.c type_lldi.c type_hdi.c type_xX.c type_lxX.c type_llxX.c type_hxX.c type_o.c type_c.c type_s.c type_hhdi.c type_hhxX.c type_u.c type_p.c

OBJ = ft_printf.o nachalo.o type_di.o type_ldi.o type_lldi.o type_hdi.o type_xX.o type_lxX.o type_llxX.o type_hxX.o type_o.o type_c.o type_s.o type_hhdi.o type_hhxX.o type_u.o type_p.o
HEAD = libftprintf.h

all: $(NAME)

$(NAME):
	gcc -I $(HEAD) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all