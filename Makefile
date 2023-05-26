# E89 Pedagogical & Technical Lab
# project:     2022_rev
# created on:  2022-11-22 - 11:19 +0100
# 1st author:  dylan.le - dylan.le
# description: Makefile

NAME	=	libve.a

NAME_TEST = 	test.out

SRCS	=	$(shell find src/ -name "*.c")

SRCS_TEST =

OBJS		=	$(SRCS:.c=.o)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all:	 $(NAME_TEST)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(NAME_TEST): $(OBJS) $(OBJS_TEST)
	$(CC) -o $(NAME_TEST) $(OBJS) $(OBJS_TEST) -lcriterion

# normale: $(OBJS)
# 	$(CC) $(CFLAGS) main.c $(OBJS) $(LDFLAGS) -o getline

t:
	make
	./test.out

d:
	rm src/*.o src/*.c~ test/*.o test/*.c~ include/*.h~ *~

save:	fclean
	git add *
	git commit -m "Sauvegarde"
	git push --force

clean:
	@$(RM) $(OBJS) $(OBJS_TEST) */*~ *~

fclean: clean
	@$(RM) $(NAME_TEST) 204 $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re

# Theses rules do not directly map to a specific fi
