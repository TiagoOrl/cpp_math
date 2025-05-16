
SRC_DIR=src
BUILD_DIR=build

run: $(BUILD_DIR)/main.o
	g++ -o run $(BUILD_DIR)/main.o

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	g++ -o $(BUILD_DIR)/main.o -c $(SRC_DIR)/main.cpp -g

cl:
	rm $(BUILD_DIR)/*.o run