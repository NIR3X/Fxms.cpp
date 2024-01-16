#pragma once

#include <cstdint>
#include <vector>

/**
 * @brief The CFxms class provides encryption and decryption functionality using a specific algorithm.
 */
class CFxms {
public:
	static const uint64_t HashLen, MaskLen, KeyLen;

	/**
	 * @brief The Mode enum specifies the encryption or decryption mode.
	 */
	enum class Mode : int8_t {
		OptimizeEncryption = 0, /**< Optimize encryption mode */
		OptimizeDecryption = 1 /**< Optimize decryption mode */
	};

	/**
	 * @brief The Status enum specifies the status of the encryption or decryption operation.
	 */
	enum class Status : int8_t {
		Success = 0, /**< Operation succeeded */
		InvalidKeyLength = -1, /**< Invalid key length */
		InvalidDataLength = -2, /**< Invalid data length */
		DecryptionFailed = -3 /**< Decryption failed */
	};

	/**
	 * @brief Generates a random encryption key.
	 * @return A vector of bytes representing the generated key.
	 */
	static std::vector<uint8_t> GenKey();

	/**
	 * @brief Encrypts the source data using the specified key and mode.
	 * @param key The encryption key.
	 * @param src The source data to be encrypted.
	 * @param dest The encrypted data.
	 * @param mode The encryption mode.
	 * @return The status of the encryption operation.
	 */
	static Status Encrypt(
		const std::vector<uint8_t>& key,
		const std::vector<uint8_t>& src,
		std::vector<uint8_t>& dest,
		Mode mode = Mode::OptimizeEncryption
	);

	/**
	 * @brief Decrypts the source data using the specified key and mode.
	 * @param key The decryption key.
	 * @param src The source data to be decrypted.
	 * @param dest The decrypted data.
	 * @param mode The decryption mode.
	 * @return The status of the decryption operation.
	 */
	static Status Decrypt(
		const std::vector<uint8_t>& key,
		std::vector<uint8_t> src,
		std::vector<uint8_t>& dest,
		Mode mode = Mode::OptimizeEncryption
	);
};
