/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Hyper/Ast/Expressions/IdentifierExpression.hpp"

#include "Hyper/Generators/Generator.hpp"
#include "Hyper/Logger.hpp"

namespace Hyper
{
	IdentifierExpression::IdentifierExpression(std::string identifier)
		: m_identifier(std::move(identifier))
	{
	}

	void IdentifierExpression::accept(Generator &generator) const
	{
		generator.visit(*this);
	}

	void IdentifierExpression::dump(size_t indent) const
	{
		AstNode::indent(indent);
		Logger::raw("{} (identifier={})\n", class_name(), m_identifier);
	}

	AstNode::Category IdentifierExpression::class_category() const noexcept
	{
		return AstNode::Category::IdentifierExpression;
	}

	std::string_view IdentifierExpression::class_name() const noexcept
	{
		return "IdentifierExpression";
	}

	std::string IdentifierExpression::identifier() const
	{
		return m_identifier;
	}
} // namespace Hyper