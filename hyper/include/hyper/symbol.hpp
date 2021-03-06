/*
 * Copyright (c) 2022-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "hyper/data_type.hpp"
#include "hyper/source_range.hpp"

#include <string>

namespace hyper
{
	struct Symbol
	{
		enum class Kind : uint8_t
		{
			Invalid = 0,

			Function,
			Parameter,
			Variable,
		};

		std::string name;
		std::string file;
		Kind kind = Kind::Invalid;
		DataType data_type = {};
		bool exported = false;
		SourceRange source_range = {};
	};
} // namespace hyper
