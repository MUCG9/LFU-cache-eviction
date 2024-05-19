DED_FLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

OBJECTS=main.o test.o lfu_cache.o create.o

CC=g++

all: kvadros

kvadros: $(OBJECTS)
	$(CC) $(OBJECTS) -o kvadros

main.o: main.cpp
	$(CC) main.cpp -c $(DED_FLAGS)

test.o: test.cpp
	$(CC) test.cpp -c $(DED_FLAGS)

lfu_cache.o: lfu_cache.cpp
	$(CC) lfu_cache.cpp -c $(DED_FLAGS)

create.o: create.cpp
	$(CC) create.cpp -c $(DED_FLAGS)

clean:
	rm -rf *.o kvadros
	rm -rf *.save kvadros