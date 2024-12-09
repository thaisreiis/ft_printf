NAME = libftprintf.a
SOURCES = ft_printf.c ft_functions.c

SRCOBJ = obj/
OBJECTS = $(SOURCES:.c=.o)
OBJ = $(addprefix $(SRCOBJ), $(OBJECTS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Regra para compilar .c em .o e criar diretórios se necessário
$(SRCOBJ)%.o: %.c
	@mkdir -p $(SRCOBJ)  # Cria o diretório obj/ se necessário
	${CC} ${CFLAGS} -g -c $< -o $@

# Regra para criar a biblioteca estática
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Regra para compilar tudo
all: $(NAME)

# Limpar objetos
clean:
	${RM} $(SRCOBJ)

# Limpar objetos e a biblioteca
fclean: clean
	${RM} $(NAME)

# Recompilar tudo
re: fclean all
