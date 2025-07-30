
TARGET = 3DViewer
QMAKE = qmake6
PREFIX ?= /home/kim/Documents/CPP4_3DViewer_v2.0.ID_353537-Team_TL_kimbrabr.d5d5866d_7685_4b30-3/src
INSTALL_DIR = $(PREFIX)/bin
OS = $(shell uname)
SOURCES = $(wildcard main.cpp model/*.cc view/*.cc controller/*.cc)
HEADERS = $(wildcard model/*.h view/*.h controller/*.h)
TEST_SOURCES = $(wildcard model/*.cc controller/*.cc testing/testing.cc)
TEST_FLAGS = -lgtest -lgtest_main -pthread
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17 -pedantic -g
DOC_FILE = doc/dvi.html


.PHONY: all install uninstall clean dvi dist tests

all: install

install:
	mkdir -p build
	cd build && $(QMAKE) ../3DViewer.pro -o Makefile && make
	# Установка в указанный каталог
	mkdir -p $(INSTALL_DIR)
	cp build/$(TARGET) $(INSTALL_DIR)/

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)
	# Удаляем пустой каталог, если он пуст
	-rmdir $(INSTALL_DIR)

clean:
	rm -rf build *.o *.a *.gcda *.gcno *.info report dist.tar .qmake.stash
	rm -rf model/*.o model/*.gch view/*.o view/*.gch controller/*.o controller/*.gch testing/*.o testing/*.gch
	rm -rf moc_predefs.h moc_*.cpp

dvi:
ifeq ($(OS), Darwin)
	open $(DOC_FILE)
else
	xdg-open $(DOC_FILE)
endif

dist: install
	# Создаем архив с бинарником и исходниками
	mkdir -p dist/$(TARGET)
	cp -r build/$(TARGET) $(SOURCES) $(HEADERS) 3DViewer.pro mainwindow.ui dist/$(TARGET)/
	tar -cvzf dist.tar.gz dist/
	rm -rf dist

tests:
	$(CC) $(CFLAGS) $(TEST_SOURCES) $(TEST_FLAGS) -o test
	./test


add_coverage_flag:
	$(eval CFLAGS += --coverage)

gcov_report: add_coverage_flag tests
	lcov -t "test" -o test.info -c -d . --no-external
	lcov -r test.info "/usr/include/*" "/usr/lib/*" -o test.info
	genhtml -o report test.info
ifeq ($(OS), Darwin)
	open report/index.html
else
	xdg-open report/index.html
endif

check: tests
ifeq ($(OS), Darwin)
	leaks --atExit -- ./test
else
	valgrind --leak-check=full ./test
endif

style:
	@echo "Checking styles..."
	clang-format -n -style=Google *.cc *.h *.cpp

format_style:
	@echo "Formatting styles..."
	clang-format -i -style=Google *.cc *.h