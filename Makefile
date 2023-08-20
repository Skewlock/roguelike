CC		= g++
CFLAGS	= 
INCLUDE	= -I ./olcPixelGameEngine -I ./include
GFLAGS	= -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
SRC_DIR	= src
OBJ_DIR	= obj
SRCS	= $(wildcard $(SRC_DIR)/*.cpp)
OBJ		= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
BIN		= game.bin

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS"))

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr "   [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

all:	$(BIN)
	@$(ECHO) All done

$(BIN):	$(OBJ)
	@$(ECHO) Linking $@
	$(CC) main.cpp -o $(BIN) $(CFLAGS) $(INCLUDE) $(GFLAGS) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(ECHO) Compiling $@
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@$(ECHO) Clean done
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	@$(ECHO) FClean done
	rm -f $(BIN)

re: 
	$(MAKE) fclean 
	$(MAKE) $(BIN)

.PHONY: clean fclean re all
.SILENT: