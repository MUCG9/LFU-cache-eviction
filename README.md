# LFU Cache Implementation in C 

Этот репозиторий содержит реализацию алгоритма кэширования LFU (Least Frequently Used) на языке программирования C в стандарте C90. 

Проект выполнен в студентами 1-го курса ФРКТ в рамках проекта на курсе по программированию в Московском физико-техническом институте.

## Описание проекта

Алгоритм LFU используется для управления кэшем, когда требуется минимизировать количество обращений к редко используемым данным. В данной реализации кэш поддерживает основные операции:

- **Создание кэша** с заданной емкостью.
- **Добавление** элементов в кэш.
- **Получение** элементов из кэша.
- **Удаление** наименее часто используемых элементов при переполнении кэша.
- **Обновление** частоты использования элементов при их запросе.

## Структура проекта

Проект состоит из одного файла на языке C, который включает:

- Определение структур данных для кэша и его узлов.
- Вспомогательные функции для создания и удаления узлов.
- Основные функции для работы с кэшем: вставка, удаление, обновление частоты использования и получение значения по ключу.
- Тестовая функция для демонстрации работы кэша.
- Главная функция программы, выполняющая тесты.

## Файлы

Проект состоит из 5 основных файлов:

- [main.cpp](https://github.com/MUCG9/LFU-cache-eviction/blob/main/LFU/main.cpp) - заголовочный файл 
- [lfu_cache.cpp](https://github.com/MUCG9/LFU-cache-eviction/blob/main/LFU/lfu_cache.cpp) - файл, содержащий функции работы с кэшом
- [struct.cpp](https://github.com/MUCG9/LFU-cache-eviction/blob/main/LFU/struct.cpp) - файл со структурами
- [create.cpp](https://github.com/MUCG9/LFU-cache-eviction/blob/main/LFU/create.cpp) - файл с функциями создания кэша

## Требования

Для компиляции и запуска проекта требуется компилятор, поддерживающий стандарт C90, например `gcc`.

## Сборка и запуск

1. **Склонируйте репозиторий**:
    ```sh
    git clone ...
    cd ...
    ```

2. **Соберите проект**:
    ```sh
    gcc -o ...
    ```

3. **Запустите программу**:
    ```sh
    ./lfu_cache
    ```
    
## Пример вывода

...
