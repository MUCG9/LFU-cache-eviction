# Имя исполняемого файла
EXEC = main
# Компилятор
CXX = gcc

# Флаги компилятора
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

# Файлы исходного кода
SRCS = main.cpp create.cpp lfu_cache.cpp test.cpp

# Заголовочные файлы
HEADERS = create.h lfu_cache.h test.h

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Флаги для Valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

# Правило по умолчанию, компиляция исполняемого файла
all: $(EXEC)

# Правило для компиляции исполняемого файла
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Правило для компиляции объектных файлов
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для запуска тестов
test: $(EXEC)
	./$(EXEC)

# Правило для запуска тестов с Valgrind
valgrind: $(EXEC)
	valgrind $(VALGRIND_FLAGS) ./$(EXEC)

# Очистка скомпилированных файлов
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all test valgrind clean