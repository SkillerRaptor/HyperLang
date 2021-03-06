/*
 * Copyright (c) 2022-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "hyper/ast/statements/statement.hpp"

namespace hyper
{
	class Expression;

	class ExpressionStatement final : public Statement
	{
	public:
		ExpressionStatement(SourceRange source_range, Expression *expression);
		~ExpressionStatement() override;

		const Expression *expression() const;

		constexpr Category class_category() const override
		{
			return AstNode::Category::ExpressionStatement;
		}

		constexpr Kind class_kind() const override
		{
			return AstNode::Kind::Statement;
		}

		constexpr std::string_view class_name() const override
		{
			return "ExpressionStatement";
		}

	private:
		Expression *m_expression = nullptr;
	};
} // namespace hyper
