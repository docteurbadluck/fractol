CC = cc

LIBX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
LIBFT = -Llibft -lft

CFLAGS = -Wall -Wextra -Werror

SRC = srcs/main.c srcs/init.c srcs/img_generator.c srcs/math.c srcs/event.c srcs/str_util.c
HEADERS = includes/fractol.h
BUILD_DIR = build

# Liste des fichiers objets avec le répertoire build
OBJ_FILES = $(SRC:srcs/%.c=$(BUILD_DIR)/%.o)

NAME = $(BUILD_DIR)/fractol

# Règle par défaut pour créer l'exécutable
all: lib create-dir $(NAME) 
	

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBX) $(LIBFT) -o $(NAME)

# Règle pour compiler un fichier .c en .o dans build/
$(BUILD_DIR)/%.o: srcs/%.c $(HEADERS)
	$(CC) -c $< -o $@

# Nettoyage des fichiers objets dans build/
lib:
	@make -C libft > /dev/null 2>&1
	@make -C minilibx-linux > /dev/null 2>&1
	
create-dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJ_FILES)

# Nettoyage complet (objets + exécutable dans build/)
fclean: clean
	rm -f $(NAME)

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
