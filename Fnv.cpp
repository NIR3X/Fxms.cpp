#include "Fnv.h"

uint64_t CFnv::Hash1a64(const void* src, size_t srcSize) {
	uint64_t hash = 0xcbf29ce484222325ULL /* offsetBasis */;
	const void* srcEnd = (const uint8_t*)src + srcSize;
	for (; src != srcEnd; src = (const uint8_t*)src + 1) {
		hash ^= *(const uint8_t*)src;
		hash *= 0x00000100000001b3ULL /* prime */;
	}
	return hash;
}
