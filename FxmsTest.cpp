/**
 * @file FxmsTest.cpp
 * @brief This file contains a test program for the CFxms class.
 */

#include "Fxms.h"
#include <cstdio>
#include <string>
#include <vector>

/**
 * @brief Function to get status message based on status code.
 * @param status The status code.
 * @return The corresponding status message.
 */
std::string getStatusMessage(CFxms::Status status) {
	switch (status) {
	case CFxms::Status::Success:
		return "Success";
	case CFxms::Status::InvalidKeyLength:
		return "Invalid key length";
	case CFxms::Status::InvalidDataLength:
		return "Invalid data length";
	case CFxms::Status::DecryptionFailed:
		return "Decryption failed";
	default:
		return "Unknown status";
	}
}

/**
 * @brief The main function that tests the CFxms class.
 * @return 0 if the test passes, 1 otherwise.
 */
int main() {
	// Generate a random key
	auto key = CFxms::GenKey();

	// Data to encrypt
	std::vector<uint8_t> data = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};

	// Encrypt the data
	std::vector<uint8_t> encrypted = {};
	CFxms::Status status = CFxms::Encrypt(key, data, encrypted, CFxms::Mode::OptimizeEncryption);
	if (status != CFxms::Status::Success) {
		printf("Encryption failed: %s\n", getStatusMessage(status).c_str());
		return 1;
	}

	// Decrypt the data
	std::vector<uint8_t> decrypted = {};
	status = CFxms::Decrypt(key, encrypted, decrypted, CFxms::Mode::OptimizeEncryption);
	if (status != CFxms::Status::Success) {
		printf("Decryption failed: %s\n", getStatusMessage(status).c_str());
		return 1;
	}

	// Check if the decrypted data matches the original data
	if (decrypted != data) {
		printf("Mismatch: decrypted data does not match the original data\n");
		return 1;
	}

	// Indicate that the test passed successfully
	puts("PASS");
	return 0;
}
