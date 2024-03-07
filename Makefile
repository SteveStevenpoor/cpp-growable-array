BIN_NAME	= myvec

SRCS		= src/main.cpp\
			  src/MyVector.cpp\
			  src/test_MyVector.cpp

HEADERS		= include/MyVector.hpp

OBJ			= $(SRCS:.cpp=.o)

CC			= g++ -fsanitize=address

CFLAGS		= -Iinclude

LDFLAGS		= -fsanitize=address -lgtest -pthread

all: $(BIN_NAME) clean

clean:
	@rm -rf *.o src/*.o

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@