OBJ=mentis.o files.o
CC = gcc -g
//FLAGS = -L/usr/lib -lxosd -lpthread -lXext -lX11 -lXinerama
FLAGS = -L/usr/lib -lxosd 
S_DIR = ./src
B_DIR = ./bin

%.o: $(S_DIR)/%.c $(S_DIR)/%.h
	$(CC) -c $<

$(B_DIR)/mentis: $(OBJ)
	mkdir -p bin
	$(CC) $(OBJ) -o $(B_DIR)/mentis $(FLAGS)

all: $(B_DIR)/mentis

install: all
	cp bin/mentis ~/bin/mentis

clean:
	@echo "Cleaning ..."
	@find . \( -name '*.~*' -o -name  '*.bak' -o -name  '*~' -o -name 'core*' \) -exec rm -f {} \;

distclean:   clean
	@echo "Cleaning all ..."
	@rm -fr *.o $(B_DIR)
