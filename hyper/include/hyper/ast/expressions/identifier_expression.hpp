/*
 * Copyright (c) 2022-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "hyper/ast/expressions/expression.hpp"
#include "hyper/identifier.hpp"

#include <string>

namespace hyper
{
	class IdentifierExpression final : public Expression
	{
	public:
		IdentifierExpression(SourceRange source_range, Identifier identifier);

		Identifier identifier() const;

		constexpr Category class_category() const override
		{
			return AstNode::Category::IdentifierExpression;
		}

		constexpr Kind class_kind() const override
		{
			return AstNode::Kind::Expression;
		}

		constexpr std::string_view class_name() const override
		{
			return "IdentifierExpression";
		}

	private:
		Identifier m_identifier;
	};
} // namespace hyper
