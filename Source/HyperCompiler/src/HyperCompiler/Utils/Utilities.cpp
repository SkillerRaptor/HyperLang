/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "HyperCompiler/Utils/Utilities.hpp"

#include "HyperCompiler/Logger.hpp"

#include <cstdlib>

namespace HyperCompiler::Utils
{
	char* duplicate_string(const char* source)
	{
		char* string = new char[strlen(source) + 1];
		char* ptr = string;
		while (*source)
		{
			*ptr++ = *source++;
		}

		*ptr = '\0';

		return string;
	}

	int64_t get_character_position(const std::string& source, char character)
	{
		for (size_t position = 0; source[position] != '\0'; ++position)
		{
			if (source[position] != character)
			{
				continue;
			}

			return static_cast<int64_t>(position);
		}

		return -1;
	}
} // namespace HyperCompiler::Utils
