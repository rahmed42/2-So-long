# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 15:51:13 by rahmed            #+#    #+#              #
#    Updated: 2021/12/11 00:03:36 by rahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strchr_nl.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_printf.c \
			ft_putchar_nbchr.c \
			ft_putnbr_hex_nbchr.c \
			ft_putnbr_nbchr.c \
			ft_putstr_nbchr.c \
			ft_get_next_line.c \
			ft_strchr_nl.c \
			ft_free_ptr.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	-I.
CC		=	gcc
RM		=	rm -f
AR		=	ar rcs
CFLAGS	=	-Wall -Wextra -Werror

TXT_RED		=	\033[1;31m
TXT_GREEN	=	\033[1;32m
TXT_YELLOW	=	\033[1;33m
TXT_BLUE	=	\033[1;34m
TXT_MAGENTA	=	\033[1;35m
TXT_CYAN	=	\033[1;36m
FANCY_RESET	=	\033[0m

%.o:		%.c
			${CC} -c ${CFLAGS} -o $@ $< ${HEADER}

${NAME}:	${OBJS}
			@echo "${TXT_YELLOW}"
			${AR} ${NAME} ${OBJS}
			@echo "${FANCY_RESET}"

all:		${NAME}

clean:
			@echo "${TXT_RED}"
			${RM} ${OBJS}
			@echo "$(FANCY_RESET)"

fclean:		clean
			@echo "${TXT_MAGENTA}"
			${RM} ${NAME}
			@echo "$(FANCY_RESET)"

re:			fclean all

.PHONY:		all clean fclean re

#TEST

