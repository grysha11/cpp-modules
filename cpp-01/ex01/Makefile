SRC			= main.cpp zombieHorde.cpp Zombie.cpp

CPP			= @c++

CPP_FLAGS	= -Wall -Werror -Wextra -std=c++98

RM			= @rm -f

OBJS		= $(SRC:.cpp=.o)

NAME		= zombie_horde

%.o:		%.cpp
				$(CPP) $(CPP_FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CPP) $(CPP_FLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
