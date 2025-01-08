SRC			= Contact.cpp main.cpp PhoneBook.cpp

CXX			= c++

CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra -g

RM			= rm -f

OBJS		= $(SRC:.cpp=.o)

NAME		= phonebook

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
