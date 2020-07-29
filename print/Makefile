NAME = libftprintf.a



SRC = ft_printf.c nachalo.c type_di.c type_ldi.c type_lldi.c type_hdi.c type_x.c type_lx.c type_llx.c type_hx.c type_o.c type_c.c type_s.c type_hhdi.c type_hhx.c type_u.c type_p.c type_lo.c type_llo.c type_ho.c type_hho.c type_lu.c type_llu.c type_hu.c type_hhu.c  type_f.c bonus.c distrib.c distrib_types.c check_flags.c type_f2.c

OBJ = ft_printf.o nachalo.o type_di.o type_ldi.o type_lldi.o type_hdi.o type_x.o type_lx.o type_llx.o type_hx.o type_o.o type_c.o type_s.o type_hhdi.o type_hhx.o type_u.o type_p.o type_lo.o type_llo.o type_ho.o type_hho.o type_lu.o type_llu.o type_hu.o type_hhu.o  type_f.o bonus.o distrib.o distrib_types.o check_flags.o type_f2.o
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