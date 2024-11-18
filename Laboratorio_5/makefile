CC = gcc
CFLAGS = -Wall
EXEC = main
SRCS = main.c double_list.c

all: $(EXEC)
$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS)

clean:
	rm -f $(EXEC)