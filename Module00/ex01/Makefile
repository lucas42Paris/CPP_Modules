NAME		= PhoneBook

CC			= c++
CFLAGS		= -Werror -Wextra -Wall -std=c++98

SRC_PATH	= ./srcs/
OBJ_PATH	= ./objects/
INC_PATH	= ./includes/

SRC			= 	main.cpp \
				Contact.cpp \
				PhoneBook.cpp

SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ			= $(SRC:.cpp=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INC			= -I $(INC_PATH)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
