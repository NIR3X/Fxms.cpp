#pragma once

#include <cstdint>

/**
 * @class CFnv
 * @brief This class provides a hash function implementation using FNV algorithm.
 */
class CFnv {
public:
	/**
	 * @brief Calculates the 64-bit FNV-1a hash value for the given data.
	 * @param src Pointer to the source data.
	 * @param srcSize Size of the source data in bytes.
	 * @return The calculated hash value.
	 */
	static uint64_t Hash1a64(const void* src, size_t srcSize);
};
