##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile ?
##

.SECONDEXPANSION:

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $$(@D)/.
		$(CC) $< -c -o $@ $(CFLAGS) $(CPPFLAGS)

$(OBJ_DIR)/.:
		$(MK) $@

$(OBJ_DIR)%/.:
		$(MK) $@

.PRECIOUS:	$(OBJ_DIR) $(OBJ_DIR)%/.
