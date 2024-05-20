set FLAGS =-Wall -Wextra -pedantic -std=c++11 -g --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
g++ create.cpp -c %FLAGS%
g++ lfu_cache.cpp -c %FLAGS%
g++ main.cpp -c %FLAGS%
g++ main.o lfu_cache.o create.o %FLAGS% -o lfu_main.exe  