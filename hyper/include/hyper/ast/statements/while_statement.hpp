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

	class WhileStatement final : public Statement
	{
	public:
		WhileStatement(
			SourceRange source_range,
			Expression *condition,
			Statement *body);
		~WhileStatement() override;

		const Expression *condition() const;
		const Statement *body() const;

		constexpr Category class_category() const override
		{
			return AstNode::Category::WhileStatement;
		}

		constexpr Kind class_kind() const override
		{
			return AstNode::Kind::Statement;
		}

		constexpr std::string_view class_name() const override
		{
			return "WhileStatement";
		}

	private:
		Expression *m_condition = nullptr;
		Statement *m_body = nullptr;
	};
} // namespace hyper
