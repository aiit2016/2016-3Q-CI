all:	vulnerable-code
clean:
	rm -f vulnerable-code *.bin *~
vulnerable-code : vulnerable-code.c
	gcc -m32 -o $@ $<
	sh setup.sh

