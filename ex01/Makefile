CC= c++

Flags=  -std=c++98

Srcs= RPN.cpp main.cpp

Header= RPN.hpp

Name= RPN

all: $(Name)

$(Name): $(Header) $(Srcs)
	$(CC) $(Flags) $(Srcs) -o $(Name)

clean:
	rm -rf $(Name)

fclean: clean

re: clean all

.PHONY: make re all clean fclean