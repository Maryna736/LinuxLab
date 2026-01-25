CXX ?= g++                       # Компилятор C++. Если переменная уже установлена — не переопределять.
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2   # Флаги компилятора: стандарт C++, предупреждения, оптимизация.
INCLUDE := include               # Папка, где лежат .h файлы.
SRC := src                       # Папка, где лежат .cpp файлы.
BUILD := build                   # Папка, куда будут собираться все .o, .a и исполняемые файлы.

LIB := $(BUILD)/libtemperament.a  # Путь к статической библиотеке, которую мы собираем.
BIN := $(BUILD)/temperament_app   # Путь к исполняемому файлу (программе).

.PHONY: all clean                # Говорит make, что "all" и "clean" — не файлы, а цели.

all: $(BIN)                      # Цель по умолчанию: собрать исполняемый файл.

$(BUILD):                        # Если папки build нет — создать её.
	@mkdir -p $(BUILD)

$(BUILD)/temperament.o: $(SRC)/temperament.cpp $(INCLUDE)/temperament.h | $(BUILD) 
# Правило сборки temperament.o: компилируем temperament.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $(SRC)/temperament.cpp -o $@

$(LIB): $(BUILD)/temperament.o   
# Создаём статическую библиотеку из объекта temperament.o
	ar rcs $@ $^

$(BIN): $(SRC)/main.cpp $(LIB)
# Собираем приложение, линковав main.cpp с нашей библиотекой
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $(SRC)/main.cpp $(LIB) -o $@

clean:
# Удаляем всю папку build со всеми объектами и бинарниками
	rm -rf $(BUILD)