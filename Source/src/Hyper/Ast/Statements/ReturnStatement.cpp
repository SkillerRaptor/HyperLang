/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Hyper/Ast/Statements/ReturnStatement.hpp"

#include "Hyper/Ast/Expressions/Expression.hpp"
#include "Hyper/Generators/Generator.hpp"
#include "Hyper/Logger.hpp"

namespace Hyper
{
	ReturnStatement::ReturnStatement(ExpressionPtr expression)
		: m_expression(std::move(expression))
	{
	}

	void ReturnStatement::accept(Generator &generator) const
	{
		generator.visit(*this);
	}

	void ReturnStatement::dump(size_t indent) const
	{
		AstNode::indent(indent);
		Logger::raw("{}\n", class_name());

		m_expression->dump(indent + 1);
	}

	AstNode::Category ReturnStatement::class_category() const noexcept
	{
		return AstNode::Category::ReturnStatement;
	}

	std::string_view ReturnStatement::class_name() const noexcept
	{
		return "ReturnStatement";
	}

	const ExpressionPtr &ReturnStatement::expression() const
	{
		return m_expression;
	}
} // namespace Hyper