all: $(NAME)
	make -C asm
	make -C vm

clean:
	make clean -C asm
	make clean -C vm

fclean: clean
	make fclean -C asm
	make fclean -C vm

re: fclean all