# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 16:27:33 by pramos-m          #+#    #+#              #
#    Updated: 2023/01/21 17:32:50 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RMV = rm -fr

SOURCES = ft_atoi.c \
			ft_atol.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c	\
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			get_next_line.c \
			get_next_line_utils.c \

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

INCLUDE = libft.h

VARIABLE = .bonus

B_OBJ = $(BONUS:.c=.o)

OBJ = $(SOURCES:.c=.o)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):: ${OBJ} ${INCLUDE}
	@ar -rcs $(NAME) $(OBJ)

$(NAME)::
	@printf ''

all: $(NAME)

bonus: ${VARIABLE}

${VARIABLE} :  $(OBJ) $(B_OBJ) #${OBJ} == ft_atoi.o ft_split.o ft_itoa.o
	@ar -rcs $(NAME) $(B_OBJ) $(B_OBJ)
	@touch $@

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME) $(VARIABLE) 

re: fclean all

.PHONY :  all clean fclean re
