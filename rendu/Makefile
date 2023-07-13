# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 15:51:13 by rahmed            #+#    #+#              #
#    Updated: 2021/12/22 21:08:59 by rahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libsolong.a
NAMEB		=	libsolong_bonus.a

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a

MLX_DIR		=	mlx
MLX_LIB		=	${MLX_DIR}/libmlx.a

SRCS		= 	so_long.c \
				parsing.c \
				checkers.c \
				render.c \
				moves.c

SRCSB		=	so_long_bonus.c \
				parsing_bonus.c \
				checkers_bonus.c \
				render_bonus.c \
				moves_bonus.c \
				animate_bonus.c

MSRC		= 	so_long.c
MSRCB		= 	so_long_bonus.c

OBJS		=	${SRCS:.c=.o}
OBJSB		=	${SRCSB:.c=.o}

CC			=	gcc
RM			=	rm -f
AR			=	ar rcs
CFLAGS		=	-Wall -Wextra -Werror
FSFLAGS		=	-fsanitize=address

HEADER		=	-I.
LDFLAGS		=	-L.
MLXFLAGS	=	-L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit

TARGET_SRV	=	so_long
TARGET_SRVB	=	so_long_bonus
#TARGET_CLT	=

TXT_RED		=	\033[1;31m
TXT_GREEN	=	\033[1;32m
TXT_YELLOW	=	\033[1;33m
TXT_BLUE	=	\033[1;34m
TXT_MAGENTA	=	\033[1;35m
TXT_CYAN	=	\033[1;36m
FANCY_RESET	=	\033[0m

%.o			:	%.c
				@echo "${TXT_BLUE}"
				${CC} -c ${CFLAGS} -o $@ $< ${HEADER}
				@echo "${FANCY_RESET}"

${NAME}		:	${OBJS}
				@echo "${TXT_GREEN}"
				make all -C ${LIBFT_DIR}
				make all -C ${MLX_DIR}
				@echo "${TXT_CYAN}"
				cp ${LIBFT_DIR}/${LIBFT_LIB} ${NAME}
				@echo "${TXT_YELLOW}"
				${AR} ${NAME} ${OBJS}
				make exec
				@echo "${FANCY_RESET}"

${NAMEB}	:	${OBJSB}
				@echo "${TXT_GREEN}"
				make all -C ${LIBFT_DIR}
				make all -C ${MLX_DIR}
				@echo "${TXT_CYAN}"
				cp ${LIBFT_DIR}/${LIBFT_LIB} ${NAMEB}
				@echo "${TXT_YELLOW}"
				${AR} ${NAMEB} ${OBJSB}
				make execb
				@echo "${FANCY_RESET}"

all			:	${NAME}
bonus 		:	${NAMEB}

clean		:
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ CLEAN ~~~~~~~~~~"
				@echo "${TXT_RED}"
				${RM} ${OBJS}
				${RM} ${OBJSB}
				@echo "${TXT_GREEN}"
				make clean -C ${LIBFT_DIR}
				make clean -C ${MLX_DIR}
				@echo "$(FANCY_RESET)"

fclean		:
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ FCLEAN ~~~~~~~~~~"
				@echo "${TXT_RED}"
				${RM} ${OBJS}
				${RM} ${OBJSB}
				@echo "${TXT_MAGENTA}"
				${RM} ${NAME}
				${RM} ${NAMEB}
				@echo "${TXT_GREEN}"
				make fclean -C ${LIBFT_DIR}
				make clean -C ${MLX_DIR}
				@echo "$(FANCY_RESET)"

re			:	fclean all

.PHONY		:	all clean fclean re bonus test testb exec execb norm flush
############### PARTIE TEST ###############
test		:
				make all
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~   TEST    ~~~~~~~~~~"
				@echo "${TXT_RED}"
#				./${TARGET_SRV}
#				./${TARGET_SRV} maps/wrongext.beri
#				./${TARGET_SRV} maps/wrongext2.bier
#				./${TARGET_SRV} maps/wrongext3.be
#				./${TARGET_SRV} maps/wrongname.ber
#				./${TARGET_SRV} maps/notclosed.ber
#				./${TARGET_SRV} maps/notrect.ber
#				./${TARGET_SRV} maps/noexit.ber
#				./${TARGET_SRV} maps/noplayer.ber
#				./${TARGET_SRV} maps/2players.ber
#				./${TARGET_SRV} maps/nocollectible.ber
#				./${TARGET_SRV} maps/noexit.ber
				@echo "${TXT_BLUE}"
#				./${TARGET_SRV} maps/little.ber
				./${TARGET_SRV} maps/big.ber
				@echo "${FANCY_RESET}"

testb		:
				make bonus
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~   TEST    ~~~~~~~~~~"
				@echo "${TXT_RED}"
#				./${TARGET_SRVB}
#				./${TARGET_SRVB} maps/wrongext.beri
#				./${TARGET_SRVB} maps/wrongext2.bier
#				./${TARGET_SRVB} maps/wrongext3.be
#				./${TARGET_SRVB} maps/wrongname.ber
#				./${TARGET_SRVB} maps/notclosed.ber
#				./${TARGET_SRVB} maps/notrect.ber
#				./${TARGET_SRVB} maps/noexit.ber
#				./${TARGET_SRVB} maps/noplayer.ber
#				./${TARGET_SRVB} maps/2players.ber
#				./${TARGET_SRVB} maps/nocollectible.ber
#				./${TARGET_SRVB} maps/noexit.ber
				@echo "${TXT_BLUE}"
#				./${TARGET_SRVB} maps/little.ber
#				./${TARGET_SRVB} maps/big.ber
				./${TARGET_SRVB} maps/bonus.ber
				@echo "${FANCY_RESET}"

exec		:	${NAME}
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ COMPILATION ~~~~~~~~~~"
				@echo "${TXT_GREEN}"
				${CC} ${CFLAGS} ${LDFLAGS} ${FSFLAGS} ${MLXFLAGS} ${NAME} ${MLX_LIB} ${MSRC} -o ${TARGET_SRV}
#				${CC} ${CFLAGS} ${LDFLAGS} ${MLXFLAGS} ${NAME} ${MLX_LIB} ${MSRC} -o ${TARGET_SRV}
				@echo "${FANCY_RESET}"

execb		:	${NAMEB}
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ COMPILATION ~~~~~~~~~~"
				@echo "${TXT_GREEN}"
				${CC} ${CFLAGS} ${LDFLAGS} ${FSFLAGS} ${MLXFLAGS} ${NAMEB} ${MLX_LIB} ${MSRCB} -o ${TARGET_SRVB}
#				${CC} ${CFLAGS} ${LDFLAGS} ${MLXFLAGS} ${NAME} ${MLX_LIB} ${MSRC} -o ${TARGET_SRVB}
				@echo "${FANCY_RESET}"

norm		:
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ CHECK NORM ~~~~~~~~~~"
				@echo "${TXT_GREEN}"
				norminette ${LIBFT_DIR}/*.c -R CheckForbiddenSourceHeader
				norminette ${LIBFT_DIR}/*.h -R CheckDefine
				@echo "${TXT_CYAN}"
				norminette *.c -R CheckForbiddenSourceHeader
				norminette *.h -R CheckDefine
				@echo "${FANCY_RESET}"

flush		:	fclean
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ Extra-CLEANING  ~~~~~~~~~~"
				@echo "${TXT_RED}"
				${RM} ${TARGET_SRV}
				${RM} ${TARGET_SRVB}
#				${RM} ${TARGET_CLT}
				${RM} .DS_STORE
				${RM} *.out
				${RM} *.a
				${RM} *.dylib
				${RM} -R *.dSYM
				@echo "${FANCY_RESET}"
###########################################
