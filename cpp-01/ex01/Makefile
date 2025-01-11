SRC			= main.cpp zombieHorde.cpp Zombie.cpp

CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

RM			= @rm -f

OBJS		= $(SRC:.cpp=.o)

NAME		= zombie_horde

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
