NAME = megaphone
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP

SRCDIR = ./
SRCS = $(shell find $(SRCDIR) -name "*.cpp" -type f | xargs)

OBJDIR = ./obj
OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re