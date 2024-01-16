#include "Rc4.h"
#include "Shuffler.h"

bool CShuffler::Shuffle(const std::vector<uint8_t>& key, uint8_t* data, uint64_t dataLen) {
	uint64_t keyLen = key.size();
	if (keyLen < 1 || keyLen > 256) {
		return false;
	}
	CRc4::CContext a4i;
	CRc4::Init(&a4i, key.data(), keyLen);
	for (uint64_t i = 0; i < dataLen; ++i) {
		uint64_t j = 0;
		CRc4::Crypt(&a4i, &j, sizeof(j));
		j %= dataLen;
		if (i != j) {
			uint8_t temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	return true;
}

bool CShuffler::Unshuffle(const std::vector<uint8_t>& key, uint8_t* data, uint64_t dataLen) {
	uint64_t keyLen = key.size();
	if (keyLen < 1 || keyLen > 256) {
		return false;
	}
	CRc4::CContext a4i;
	CRc4::Init(&a4i, key.data(), keyLen);
	std::vector<uint64_t> jArr(dataLen);
	for (uint64_t i = 0; i < dataLen; ++i) {
		uint64_t j = 0;
		CRc4::Crypt(&a4i, &j, sizeof(j));
		j %= dataLen;
		jArr[i] = j;
	}
	for (uint64_t i = dataLen - 1; i != (uint64_t)-1; --i) {
		uint64_t j = jArr[i];
		if (i != j) {
			uint8_t temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	return true;
}
