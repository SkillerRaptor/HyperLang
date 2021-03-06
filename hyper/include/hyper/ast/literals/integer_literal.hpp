/*
 * Copyright (c) 2022-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "hyper/ast/literals/literal.hpp"

#include <string>

namespace hyper
{
	class IntegerLiteral final : public Literal
	{
	public:
		IntegerLiteral(SourceRange source_range, std::string integer);

		std::string_view integer() const;

		constexpr Category class_category() const override
		{
			return AstNode::Category::IntegerLiteral;
		}

		constexpr Kind class_kind() const override
		{
			return AstNode::Kind::Literal;
		}

		constexpr std::string_view class_name() const override
		{
			return "IntegerLiteral";
		}

	private:
		std::string m_integer;
	};
} // namespace hyper
