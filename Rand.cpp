#include "Rand.h"

#ifndef __GNUC__
	#pragma comment(lib, "advapi32")
#endif

#define RtlGenRandom SystemFunction036
extern "C" BOOLEAN NTAPI RtlGenRandom(PVOID RandomBuffer, ULONG RandomBufferLength);

void CRand::Read(LPVOID data, ULONG dataLen) {
	RtlGenRandom(data, dataLen);
	UINT64 seed = GetTickCount64() ^ 0x47cbdd50f4e37928ULL;
	for (SIZE_T i = 0; i < dataLen; ++i) {
		seed *= 5; ++seed;
		((PUINT8)data)[i] ^= seed;
	}
}
