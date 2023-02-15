#include <stdio.h>

#include "RingBuffer.h"

#define RING_SIZE 5

int main() {
	struct FixedSizeRingBuffer *ring = NewRing(RING_SIZE);

	PushRing(ring, 10);
	PushRing(ring, 20);
	PushRing(ring, 30);
	PushRing(ring, 40);
	PushRing(ring, 50);
	PushRing(ring, 60);
	PushRing(ring, 70);

	printf("%d\n", PopRing(ring));
	printf("%d\n", PopRing(ring));
	printf("%d\n", PopRing(ring));
	printf("%d\n", PopRing(ring));
	printf("%d\n", PopRing(ring));

	printf("%d\n", PopRing(ring));

	DelRing(ring);

	return 0;
}
