CC= c++

Flags=  -std=c++98

Srcs= PmergeMe.cpp main.cpp

Header= PmergeMe.hpp

Name= merge

all: $(Name)

$(Name): $(Header) $(Srcs)
	$(CC) $(Flags) $(Srcs) -o $(Name)

clean:
	rm -rf $(Name)

fclean: clean

re: clean all

.PHONY: make re all clean fclean