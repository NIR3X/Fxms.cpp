#include "Fnv.h"
#include "Fxms.h"
#include "Rand.h"
#include "Shuffler.h"

const uint64_t CFxms::HashLen = sizeof(uint64_t), CFxms::MaskLen = 16, CFxms::KeyLen = 256;

static __forceinline uint64_t getHash(const std::vector<uint8_t>& data) {
	return CFnv::Hash1a64(data.data(), data.size());
}

std::vector<uint8_t> CFxms::GenKey() {
	std::vector<uint8_t> key(KeyLen);
	CRand::Read(&key[0], KeyLen);
	return key;
}

CFxms::Status CFxms::Encrypt(const std::vector<uint8_t>& key, const std::vector<uint8_t>& src, std::vector<uint8_t>& dest, Mode mode) {
	uint64_t keyLen = key.size();
	if (keyLen < 1 || keyLen > 256) {
		return Status::InvalidKeyLength;
	}
	uint64_t srcLen = src.size(), resultLen = HashLen + MaskLen + srcLen;
	std::vector<uint8_t> result(resultLen);
	*(uint64_t*)&result[0] = getHash(src);
	uint8_t* mask = &result[HashLen];
	CRand::Read(mask, MaskLen);
	uint8_t* data = &mask[MaskLen];
	for (uint64_t i = 0; i < srcLen; ++i) {
		data[i] = src[i] ^ mask[i % MaskLen] ^ key[i % keyLen];
	}
	if (mode == Mode::OptimizeEncryption) {
		CShuffler::Shuffle(key, &result[0], resultLen);
	} else {
		CShuffler::Unshuffle(key, &result[0], resultLen);
	}
	dest = std::move(result);
	return Status::Success;
}

CFxms::Status CFxms::Decrypt(const std::vector<uint8_t>& key, std::vector<uint8_t> src, std::vector<uint8_t>& dest, Mode mode) {
	uint64_t keyLen = key.size();
	if (keyLen < 1 || keyLen > 256) {
		return Status::InvalidKeyLength;
	}
	uint64_t srcLen = src.size(), dataLen = srcLen - MaskLen - HashLen;
	if ((int64_t)dataLen < 0) {
		return Status::InvalidDataLength;
	}
	if (mode == Mode::OptimizeEncryption) {
		CShuffler::Unshuffle(key, &src[0], srcLen);
	} else {
		CShuffler::Shuffle(key, &src[0], srcLen);
	}
	uint8_t* mask = &src[HashLen], * data = &mask[MaskLen];
	dest.resize(dataLen);
	for (uint64_t i = 0; i < dataLen; ++i) {
		dest[i] = data[i] ^ mask[i % MaskLen] ^ key[i % keyLen];
	}
	if (getHash(dest) != *(uint64_t*)&src[0]) {
		return Status::DecryptionFailed;
	}
	return Status::Success;
}
