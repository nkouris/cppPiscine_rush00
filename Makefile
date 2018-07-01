CC = clang++

NAME = ft_retro

CFLAGS = -Wall -Werror -Wextra

INCLUDES = includes

SRCSDIR = srcs/
SRCS = AEntity.cpp AEnemy.cpp AMoving.cpp \
		Board.cpp Bullet.cpp BulletKnight.cpp \
		EnemyCop.cpp EnemyFace.cpp EnemyTypeB.cpp \
		Game.cpp Player.cpp Poop.cpp Scene.cpp \
		main.cpp

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -I$(INCLUDES) $< -o $@

$(NAME): $(OBJS)
	@echo "\x1b[1mBuilding $(NAME)...\x1b[0m"
	$(CC) -o $(NAME) $(OBJS) -lncurses
	@echo "\x1b[1mBuild finished!!\x1b[0m"

clean:
	@echo "\x1b[1mCleaning...\x1b[0m"
	/bin/rm -rf $(OBJDIR)
	@echo

fclean: clean
	@echo "\x1b[1mFcleaning...\x1b[0m"
	/bin/rm -f $(NAME)
	@echo

re: fclean all

.PHONY: all clean fclean re
