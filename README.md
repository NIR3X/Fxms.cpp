# FNV-XOR-Mask-Shuffle Symmetric Encryption Algorithm

This is a C++ package that implements the FNV-XOR-Mask-Shuffle symmetric encryption algorithm. This algorithm is a combination of several cryptographic techniques that make it difficult for an attacker to decrypt the data.

## Installation

To use this package, you can clone the repository and compile it using a C++ compiler:

```bash
git clone https://github.com/NIR3X/Fxms.cpp
cd Fxms.cpp
make
```

## Usage

Here is an example of how to use this package:

```cpp
#include "Fxms.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
	// Generate a random key
	auto key = CFxms::GenKey();

	// Data to encrypt
	std::vector<uint8_t> data = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};

	// Encrypt the data
	std::vector<uint8_t> encrypted = {};
	CFxms::Status status = CFxms::Encrypt(key, data, encrypted, CFxms::Mode::OptimizeEncryption);
	if (status != CFxms::Status::Success) {
		std::cout << "Encryption failed" << std::endl;
		return 1;
	}

	// Decrypt the data
	std::vector<uint8_t> decrypted = {};
	status = CFxms::Decrypt(key, encrypted, decrypted, CFxms::Mode::OptimizeEncryption);
	if (status != CFxms::Status::Success) {
		std::cout << "Decryption failed" << std::endl;
		return 1;
	}

	// Print the decrypted data
	std::cout << std::string(decrypted.begin(), decrypted.end()) << std::endl;
	return 0;
}
```

## License

[![GNU AGPLv3 Image](https://www.gnu.org/graphics/agplv3-155x51.png)](https://www.gnu.org/licenses/agpl-3.0.html)

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU Affero General Public License](https://www.gnu.org/licenses/agpl-3.0.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
