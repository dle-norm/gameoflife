# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/15 15:40:05 by dle-norm          #+#    #+#              #
#    Updated: 2015/09/15 15:40:16 by dle-norm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Life

SRC = src/*.c

SRO = sro/*.o

all: $(NAME)

$(NAME) :
	Make -j -C libft/
	git submodule init
	git submodule update
	cmake -j -B./glfw -H./glfw
	make -j -C ./glfw
	gcc -c $(SRC) -I srh/ -I libft/ -I ./ -I glfw/include/GLFW/
	mv *.o sro/
	gcc -o $(NAME) $(SRO) -L libft/ -lft -L./glfw/src -lglfw3  -framework glut -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

clean :
	Make -j -C libft/ clean
	make -j -C ./glfw clean
	rm -f $(SRO)

fclean : clean
	Make -j -C libft/ fclean
	rm -f $(NAME)

re : fclean all
