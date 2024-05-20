set FLAGS =-Wall -Wextra -pedantic -std=c++11 -g --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
g++ main.cpp -c %FLAGS%
g++ main.o %FLAGS% -o lru_main.exe