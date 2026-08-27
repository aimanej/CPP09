CC= c++

Flags= -Wall -Wextra -Werror -std=c++98

Srcs= PmergeMe.cpp main.cpp

Header= PmergeMe.hpp

Name= PmergeMe

all: $(Name)

$(Name): $(Header) $(Srcs)
	$(CC) -O2 $(Flags) $(Srcs) -o $(Name)

clean:
	rm -rf $(Name)

fclean: clean

re: clean all

.PHONY: make re all clean fclean