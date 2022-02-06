/*
 * Copyright (c) 2020-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "hyper/ast/expressions/conditional_expression.hpp"

namespace hyper
{
	ConditionalExpression::ConditionalExpression(
		SourceRange source_range,
		ExpressionPtr condition,
		ExpressionPtr true_expression,
		ExpressionPtr false_expression)
		: Expression(source_range)
		, m_condition(std::move(condition))
		, m_true_expression(std::move(true_expression))
		, m_false_expression(std::move(false_expression))
	{
	}

	void ConditionalExpression::validate_scope(
		const ScopeValidator &scope_validator) const
	{
		(void) scope_validator;
	}

	void ConditionalExpression::validate_type(
		const TypeValidator &type_validator) const
	{
		(void) type_validator;
	}
} // namespace hyper