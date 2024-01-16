#pragma once

#include <cstdint>

/**
 * @brief The CRc4 class represents the RC4 encryption algorithm.
 */
class CRc4 {
public:
	/**
	 * @brief The CContext class represents the context of the RC4 encryption algorithm.
	 */
	class CContext {
	public:
		uint8_t state[256]; ///< The state array used in the RC4 algorithm.
		uint8_t x; ///< The x variable used in the RC4 algorithm.
		uint8_t y; ///< The y variable used in the RC4 algorithm.
	};

	/**
	 * @brief Initializes the RC4 encryption algorithm with the given key.
	 * 
	 * @param a4i Pointer to the CContext object.
	 * @param key Pointer to the key.
	 * @param keyLen Length of the key.
	 */
	static void Init(CContext* a4i, const void* key, uint32_t keyLen);

	/**
	 * @brief Encrypts or decrypts the given string using the RC4 encryption algorithm.
	 * 
	 * @param a4i Pointer to the CContext object.
	 * @param inoutString Pointer to the string to be encrypted or decrypted.
	 * @param length Length of the string.
	 */
	static void Crypt(CContext* a4i, void* inoutString, uint32_t length);
};
