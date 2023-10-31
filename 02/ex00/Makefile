NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
LDFLAGS = -I$(INCDIR)

INCDIR = ./inc
INCS = $(shell find $(INCDIR) -name "*.hpp" -type f | xargs)

SRCDIR = ./src
SRCS = $(shell find $(SRCDIR) -name "*.cpp" -type f | xargs)

OBJDIR = ./obj
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re