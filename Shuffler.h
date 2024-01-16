#pragma once

#include <vector>

/**
 * @brief The CShuffler class provides functions for shuffling and unshuffling data using a key.
 */
class CShuffler {
public:
	/**
	 * @brief Shuffle the data using the provided key.
	 * @param key The key used for shuffling.
	 * @param data Pointer to the data to be shuffled.
	 * @param dataLen The length of the data in bytes.
	 * @return True if the shuffling is successful, false otherwise.
	 */
	static bool Shuffle(const std::vector<uint8_t>& key, uint8_t* data, uint64_t dataLen);

	/**
	 * @brief Unshuffle the data using the provided key.
	 * @param key The key used for unshuffling.
	 * @param data Pointer to the data to be unshuffled.
	 * @param dataLen The length of the data in bytes.
	 * @return True if the unshuffling is successful, false otherwise.
	 */
	static bool Unshuffle(const std::vector<uint8_t>& key, uint8_t* data, uint64_t dataLen);
};
