OBJ=			$(SRC:%.c=$(OBJ_DIR)/%.o)

all:			$(NAME)

$(NAME):		$(OBJ)
		$(LD) $^ -o $@

.SECONDEXPANSION:

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $$(@D)
		$(CC) $< -c -o $@ $(CFLAGS) $(CPPFLAGS)

$(OBJ_DIR):
		$(MK) $@

$(OBJ_DIR)%/.:
		$(MK) $@

.PRECIOUS:		$(OBJ_DIR) $(OBJ_DIR)%/.

clean:
		$(RM) $(OBJ_DIR)

fclean:			clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
