#pragma once

#include <windows.h>

/**
 * @brief The CRand class provides a static method for reading random data into a buffer.
 */
class CRand {
public:
	/**
	 * @brief Reads random data into the specified buffer.
	 * 
	 * @param data A pointer to the buffer to store the random data.
	 * @param dataLen The length of the buffer in bytes.
	 */
	static void Read(LPVOID data, ULONG dataLen);
};
