NAME := bingo
CFLAG := -Wall -Werror -Wextra -g
SRC = src/main.c\

GREEN = \x1b[32m
RESET = \033[0m

OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@

obj/%.o : src/%.c
	mkdir -pv obj
	$(CC) $(CFLAG) -o $@ -c $^ -I include

clean :
	@test -e obj && rm -fr obj || echo "$(GREEN)clean: No objects to clean$(RESET)"

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all/ clean/ fclean/ re/