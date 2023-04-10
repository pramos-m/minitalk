# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 17:44:34 by pramos-m          #+#    #+#              #
#    Updated: 2023/02/03 15:25:01 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------RULES-----------------#

NAME = minitalk
BONUS = minitalk_bonus
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

#----------------COMANDS-----------------#

CFLAGS	= -Wall -Werror -Wextra -g
XFLAGS  = -fsanitize=address -g3
AR		= ar -rcs
RM		= rm -rf
MD		= mkdir -p
CP		= cp -f

#----------------PATH-----------------#

SRC_DIR = src/
UTILS = utils/
INC_DIR = ./inc/
LIB_DIR = ./lib/
B_DIR	= bonus/

LIBFT_DIR = $(LIB_DIR)libft/

PRINT_DIR = $(LIB_DIR)printf/

LIBRARY = $(LIB_DIR)/*/*.a

OBJ_DIR = ./.obj/

#----------------MINI TALK-----------------#

INCLUDE = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINT_DIR) -Ibonus/inc/

SRC_CLIENT				+= ${SRC_DIR}client.c
SRC_SERVER 				+= ${SRC_DIR}server.c
UTL_FLS = ${UTILS}minitalk_utils.c

SRC_CLIENT				+= ${UTL_FLS}
SRC_SERVER				+= ${UTL_FLS}


OBJS_SERVER 			= $(addprefix $(OBJ_DIR), $(SRC_SERVER:.c=.o))
OBJS_CLIENT				= $(addprefix $(OBJ_DIR), $(SRC_CLIENT:.c=.o))

DEPS += $(OBJS_SERVER:%.o=%.d)
DEPS += $(OBJS_CLIENT:%.o=%.d)

#------------------BONUS-------------------#

SRC_CLIENT_BONUS				+= ${B_DIR}${SRC_DIR}client_bonus.c
SRC_SERVER_BONUS 				+= ${B_DIR}${SRC_DIR}server_bonus.c
UTL_FLS = ${B_DIR}${UTILS}minitalk_utils_bonus.c

SRC_CLIENT_BONUS				+= ${UTL_FLS}
SRC_SERVER_BONUS				+= ${UTL_FLS}


OBJS_SERVER_BONUS 			= $(addprefix $(OBJ_DIR), $(SRC_SERVER_BONUS:.c=.o))
OBJS_CLIENT_BONUS				= $(addprefix $(OBJ_DIR), $(SRC_CLIENT_BONUS:.c=.o))

DEPS_BONUS += $(OBJS_SERVER_BONUS:%.o=%.d)
DEPS_BONUS += $(OBJS_CLIENT_BONUS:%.o=%.d)

#------------------RULES-------------------#
$(OBJ_DIR)%.o: %.c $(LIBRARY)
	@$(MD) $(dir $@)
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

all:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(NAME)

$(NAME)::
	@$(MAKE) $(CLIENT_NAME)
	@$(MAKE) $(SERVER_NAME)
	@echo "Mini talk has been compiled!"

$(NAME)::
	@printf ''

$(CLIENT_NAME):: $(OBJS_CLIENT)
		$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_CLIENT) ${LIBRARY} -o $(CLIENT_NAME)


$(SERVER_NAME):: $(OBJS_SERVER)
		${CC} ${CFLAGS} $(INCLUDE) ${OBJS_SERVER} ${LIBRARY} -o $(SERVER_NAME)

$(CLIENT_NAME)::
	@echo "nothing to be done for client"
	
$(SERVER_NAME)::
	@echo "nothing to be done for server"


bonus:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(CLIENT_NAME_BONUS)
	@$(MAKE) $(SERVER_NAME_BONUS)
	@echo "Mini talk bonus has been compiled!"

$(CLIENT_NAME_BONUS):: $(OBJS_CLIENT_BONUS)
		$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_CLIENT_BONUS) ${LIBRARY} -o $(CLIENT_NAME_BONUS)


$(SERVER_NAME_BONUS):: $(OBJS_SERVER_BONUS)
		${CC} ${CFLAGS} $(INCLUDE) ${OBJS_SERVER_BONUS} ${LIBRARY} -o $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS)::
	@echo "nothing to be done for client bonus"
	
$(SERVER_NAME_BONUS)::
	@echo "nothing to be done for server bonus"

$(BONUS)::
		@printf ''

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "clean done"

fclean:
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(OBJ_DIR)
	@$(RM) $(CLIENT_NAME)
	@$(RM) $(CLIENT_NAME_BONUS)
	@$(RM) $(SERVER_NAME)
	@$(RM) $(SERVER_NAME_BONUS)
	@echo "fclean done"

re:
	@$(MAKE) fclean
	@$(MAKE) all

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY:	all clean fclean re bonus
