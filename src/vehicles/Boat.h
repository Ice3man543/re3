#pragma once

#include "Vehicle.h"

class CBoat : public CVehicle
{
public:
	// 0x288
	uint8 stuff1[57];
	bool m_bIsAnchored;
	uint8 stuff[450];

	CBoat(int, uint8);
	CBoat* ctor(int, uint8);
};
static_assert(sizeof(CBoat) == 0x484, "CBoat: error");