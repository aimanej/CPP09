CC= c++

Flags=  -std=c++98

Srcs= BitcoinExchange.cpp main.cpp

Header= BitcoinExchange.hpp

Name= btc

all: $(Name)

$(Name): $(Header) $(Srcs)
	$(CC) $(Flags) $(Srcs) -o $(Name)

clean:
	rm -rf $(Name)

fclean: clean

re: clean all

.PHONY: make re all clean fclean