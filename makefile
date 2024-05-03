CC = gcc
LIB_PATH = ./lib/
BIN_PATH = ./bin
SRC_PATH = ./src


main: $(BIN_PATH)/message.o main.c
	$(CC) $^ -I $(LIB_PATH) -o $@

$(BIN_PATH)/message.o: $(SRC_PATH)/message.c
	$(CC) $< -I $(LIB_PATH) -c -o $@

clean:
	$(RM) main $(BIN_PATH)/*.o 