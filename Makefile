##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile ?
##

include		mk/init.mk
include		mk/setup.mk

override SRC+=	io.c 	\
		init.c	\
		main.c	\
		pixel.c	\
		shape.c	\
		screen.c\
		destroy.c

include 	mk/rules.mk
