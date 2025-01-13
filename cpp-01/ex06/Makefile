SRC			= Harl.cpp main.cpp

CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -g

RM			= @rm -f

OBJS		= $(SRC:.cpp=.o)

NAME		= harlFilter

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
