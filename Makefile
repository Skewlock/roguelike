# Compiler specs
CC		:= g++
CFLAGS	:= -Wall -Wextra
INCLUDE	:= -I ./include -I ./include/engine -I ./include/game
GFLAGS	:= -lSDL2_image -g `sdl2-config --cflags --libs`

SRC_DIR	:= src
OBJ_DIR	:= obj

DIR_DUP	= mkdir -p $(@D)

# Create sources and obj files and folders
SRCS	:=	\
	engine/controller.cpp \
	engine/engine.cpp \
	engine/engineConfig.cpp \
	engine/eventManager.cpp \
	engine/gameObject.cpp \
	engine/objectsManager.cpp \
	engine/textureManager.cpp \
	engine/timer.cpp \
	game/entity.cpp \
	game/player.cpp \
	game/playerPet.cpp \
	main.cpp
SRCS	:=	$(SRCS:%=$(SRC_DIR)/%)
OBJ		:=	$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
BIN		:= game.bin

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

all: folder $(BIN)
	@$(ECHO) All done

$(BIN): $(OBJ)
	@$(ECHO) Linking $@
	$(CC) -o $(BIN) $(CFLAGS) $(INCLUDE) $(OBJ) $(GFLAGS)

folder:
	if ! [ -d "obj" ]; then \
		mkdir obj; \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
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