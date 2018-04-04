all:
	@gcc -o main *.c -Iinclude -Wall -g

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name 'main' | xargs rm -rf {}
                
run:
	@./main
                
debug:
	@make
	@valgrind --leak-check=full --show-leak-kinds=all ./main

zip:
	zip -r dualQueue1VEC *.c *.h Makefile
