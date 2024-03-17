NAME = minitalk

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC_CL = client.c minitalk_utils.c
SRC_SR = server.c minitalk_utils.c

OBJ_CL = $(SRC_CL:.c=.o)
OBJ_SR = $(SRC_SR:.c=.o)
 
all: $(NAME)

$(NAME): client server

client: $(OBJ_CL)
	$(CC) $(CFLAGS) -o client $(OBJ_CL)

server: $(OBJ_SR)
	$(CC) $(CFLAGS) -o server $(OBJ_SR)

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_CL) $(OBJ_SR)

fclean: clean
	$(RM) client server

re: fclean all
