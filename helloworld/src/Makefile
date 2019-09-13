OBJS := helloworld.o
BIN := helloworld

# build helloworld executable when user executes "make"
$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# remove object files and executable when user executes "make clean"
clean:
	rm *.o *.a $(BIN)


