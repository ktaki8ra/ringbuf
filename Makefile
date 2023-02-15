ringbuf: main.c RingBuffer.o
	gcc main.c RingBuffer.o -o RingBuffer.out
RingBuffer.o:
	gcc -c RingBuffer.c
clean:
	rm -f *.o
