CC		= g++
CFLAGS	= -Wall -Wextra
INCLUDE	= -I ./include
GFLAGS	= -lSDL2_image -g `sdl2-config --cflags --libs`
SRC_DIR	= src
OBJ_DIR	= obj
SRCS	= $(wildcard $(SRC_DIR)/*.cpp)
OBJ		= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
BIN		= game.bin

# ===============================================
# 				progression indicator
# ===============================================
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr "   [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

all: $(BIN)
	@$(ECHO) All done

$(BIN):	folder $(OBJ)
	@$(ECHO) Linking $@
	$(CC) -o $(BIN) $(CFLAGS) $(INCLUDE) $(OBJ) $(GFLAGS)

folder:
	if ! [ -d "obj" ]; then \
		mkdir obj; \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp osdetection
	@$(ECHO) Compiling $@
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

osdetection:
	@echo $(OSFLAG)

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