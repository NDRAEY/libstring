SOURCE = src/string.c libvector/src/vector.c
OBJS = $(SOURCE:%.c=%.o)
LIB = libstring.a
EXAMPLE = test_string

CFLAGS ?= -Wall -Wextra -ggdb3 -O0 -Ilibvector/include

all: $(LIB) $(EXAMPLE)

$(EXAMPLE): example.c $(LIB)
	$(CC) $(CFLAGS) $< $(LIB) -o $@

$(LIB): $(OBJS)
	ar rs $(LIB) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	-rm $(OBJS)
	-rm $(LIB)
	-rm $(EXAMPLE)
