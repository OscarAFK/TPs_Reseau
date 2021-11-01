#pragma once
#include <cstdint>

namespace uqac {
	namespace utils {

		enum class ClassID : uint8_t
		{
			Player = 0x00,
			Enemy = 0x01,
			ClassID_Max
		};
	}
}