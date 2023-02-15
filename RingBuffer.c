#include "RingBuffer.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

FixedSizeRingBuffer *NewRing(uint32_t size) {
	if(size <= 0) {
		printf("[ERROR] Size of Ring Buffer > 0\n");
		exit(1);
	}
	FixedSizeRingBuffer *ring;
	ring = (FixedSizeRingBuffer *)malloc(sizeof(FixedSizeRingBuffer));
	ring->max_elements_count = size;
	ring->wp = 0;
	ring->rp = 0;
	ring->buffer = (uint32_t *)malloc(sizeof(uint32_t) * ring->max_elements_count);
	for(uint32_t i=0; i<ring->max_elements_count; i++) {
		ring->buffer[i] = 0;
	}
	return ring;
}
void PushRing(FixedSizeRingBuffer *ring, uint32_t value) {
	if(ring->wp == 0) {
		ring->buffer[0] = value;
		ring->wp += 1;
	} else if (0 < ring->wp && ring->wp < ring->max_elements_count){
		for(uint32_t i=ring->wp; i>0; i--) {
			ring->buffer[i] = ring->buffer[i-1];
		}
		ring->buffer[0] = value;
		ring->wp += 1;
		ring->rp += 1;
	} else {
		ring->buffer[ring->max_elements_count - 1] = 0;
		for(uint32_t i=ring->max_elements_count-1; i>0; i--) {
			ring->buffer[i] = ring->buffer[i-1];
		}
		ring->buffer[0] = value;
	}
}

uint32_t PopRing(FixedSizeRingBuffer *ring) {
	if(ring->wp == 0 && ring->rp == 0) {
		printf("[Force Quit] Couldn't Pop because Ring Buffer is EMPTY...\n");
		exit(1);
	}
	uint32_t value = ring->buffer[ring->rp];
	ring->wp -= 1;
	if(ring->wp == 0) {
		ring->rp = 0;
	} else {
		ring->rp -= 1;
	}
	return value;
}

void DelRing(FixedSizeRingBuffer *ring) {
	free(ring->buffer);
	free(ring);
}
