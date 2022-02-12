HDIR = headers
CDIR = src
ODIR = objs
CPPFLAGS = -std=c++11 -g
DEPS = $(wildcard $(HDIR)/*.h)
OBJ_FILES = main.o cargo.o human.o# put all dependencies for driver here
OBJS = $(patsubst %.o, $(ODIR)/%.o, $(OBJ_FILES))
vpath %.h headers
vpath %.cpp src
vpath %.o objs
DIRS = $(HDIR) $(CDIR) $(ODIR)
$(shell mkdir -p $(DIRS))

$(ODIR)/%.o: %.cpp $(DEPS)
    g++ $(CPPFLAGS) -c $< -o $@

driver: $(OBJS)
    g++ $(CPPFLAGS) -o $@ $^

clean:
    rm $(ODIR)/*.o driver

.PHONY: clean all