CPP			= g++
TARGET 		= OOPaint
SRC_DIRS 	= .

SRCS		= $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS		= $(addsuffix .o,$(basename $(SRCS)))

CPPFLAGS	= -std=c++11 -Wall -Wextra -pedantic
LDLIBS		= -ldl -lrt -lSDL2

$(TARGET): $(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $@ $(LDLIBS)

.PHONY: clean run
clean:
	$(RM) $(TARGET) $(OBJS)

run:
	./$(TARGET)
