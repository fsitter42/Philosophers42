NAME =		philo

SOURCE =	f_ghost_routine.c  \
			f_input.c  \
			f_input_utilities.c  \
			f_philo_actions.c  \
			f_philo_actions2.c  \
			f_philo_create.c  \
			f_philo_routine.c  \
			f_table.c  \
			f_threads_create.c  \
			f_time.c  \
			philo.c

HEADER =	philo.h

CFLAGS =	-Wall -Wextra -Werror -pthread

VALGRIND =	-g

FSANITIZE =	-fsanitize=thread

BOTH =		$(VALGRIND) $(FSANITIZE)

OBJECTS =	$(SOURCE:.c=.o)

CC =		cc

RM =		rm -rf

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:	
	${RM} ${OBJECTS}

fclean:	clean
	${RM} ${NAME}


re:		fclean all

memory: CFLAGS += $(VALGRIND)
memory: re

thread: CFLAGS += $(BOTH)
thread: re

.PHONY: clean fclean re all memory thread