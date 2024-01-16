/*
 *  Copyright 2006 Mike McCormack
 *
 *  based on arc4.cpp - written and placed in the public domain by Wei Dai
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

 /* http://cryptopp.sourceforge.net/docs/ref521/arc4_8cpp-source.html */

#include "Rc4.h"

void CRc4::Init(CContext* a4i, const void* key, uint32_t keyLen) {
	uint32_t keyIndex = 0, stateIndex = 0;
	uint32_t i, a;

	a4i->x = a4i->y = 0;

	for (i = 0; i < 256; i++) {
		a4i->state[i] = i;
	}

	for (i = 0; i < 256; i++) {
		a = a4i->state[i];
		stateIndex += ((const uint8_t*)key)[keyIndex] + a;
		stateIndex &= 0xff;
		a4i->state[i] = a4i->state[stateIndex];
		a4i->state[stateIndex] = a;
		if (++keyIndex >= keyLen) {
			keyIndex = 0;
		}
	}
}

void CRc4::Crypt(CContext* a4i, void* inoutString, uint32_t length) {
	uint8_t* const s = a4i->state;
	uint32_t x = a4i->x;
	uint32_t y = a4i->y;
	uint32_t a, b;

	while (length--) {
		x = (x + 1) & 0xff;
		a = s[x];
		y = (y + a) & 0xff;
		b = s[y];
		s[x] = b;
		s[y] = a;
		*(uint8_t*)inoutString ^= s[(a + b) & 0xff];
		inoutString = (uint8_t*)inoutString + 1;
	}

	a4i->x = x;
	a4i->y = y;
}
