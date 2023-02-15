#include <stdint.h>

typedef struct FixedSizeRingBuffer {
	uint32_t max_elements_count;
	uint32_t wp;
	uint32_t rp;
	uint32_t *buffer;
} FixedSizeRingBuffer;

FixedSizeRingBuffer *NewRing(uint32_t size);

void PushRing(FixedSizeRingBuffer *ring, uint32_t value);

uint32_t PopRing(FixedSizeRingBuffer *ring);

void DelRing(FixedSizeRingBuffer *ring);
