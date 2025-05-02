NAME    =       Base

CPP             =       c++ -Wall -Wextra -Werror -std=c++98

SRC             =       main.cpp		\
			Base.cpp	\

OBJ     = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CPP) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

all             :
	$(CPP) $(SRC) -o $(NAME)

clean   :
	rm -f $(OBJ)

fclean  :       clean
	rm -f $(NAME)

re              :       fclean all

