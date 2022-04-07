PURPLE			=	\033[0;35m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
WHITE			=	\033[1;37m

EXEC		=   EXEC

SRCS		= 	$(wildcard *.c)
INCS		=	$(wildcard *.h)
OBJS		= 	${SRCS:.c=.o}

CC			= 	@gcc
CFLAGS 		=	-Wall -Werror -Wextra

.c.o        :
				@echo "${WHITE}Compiling ${LIGHT_RED}/${PURPLE}$<"
				${CC} ${CFLAGS} -I $< -c $< -o $@

$(EXEC) 	: 	${OBJS} 
					${CC} ${CFLAGS} -o $@ $^
					@echo "${LIGHT_GREEN}'EXEC' created"

all:		${EXEC}

clean:
			@rm -f ${OBJS}
			@echo "${YELLOW}All '.o' cleared"

fclean:
			@rm -f ${OBJS} ${EXEC}
			@echo "${YELLOW}All '.o' && 'EXEC' cleared"

re:			fclean all

.PHONY	= 	all clean fclean re