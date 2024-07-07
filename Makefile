NAME=executable

FILES:=
TEST_FILES:= asserts.cpp main.cpp unit/Fixed.cpp
TEST_FILES:=$(addprefix tests/, $(TEST_FILES))
INCLUDES=-I includes/
COMPILER=c++

all: $(NAME)

$(NAME): $(FILES) src/main.cpp
	@$(COMPILER) --std=c++98 $(INCLUDES) $(FILES) src/main.cpp -o $(NAME)

unit: $(TEST_FILES)
	@$(COMPILER) $(INCLUDES) -I tests/ $(FILES) $(TEST_FILES) -o unit
	@./unit
	@rm -rf unit

e2e: $(NAME)
	@./tests/e2e/Program.sh $(realpath $(NAME))
