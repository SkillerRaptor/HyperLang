/*
 * Copyright (c) 2020-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "hyper/ast/forward.hpp"
#include "hyper/ast/statement.hpp"

namespace hyper
{
	class Expression;

	class WhileStatement final : public Statement
	{
	public:
		WhileStatement(
			SourceRange source_range,
			ExpressionPtr condition,
			StatementPtr body);

		void validate_scope(const ScopeValidator &scope_validator) const override;
		void validate_type(const TypeValidator &type_validator) const override;

		constexpr Category class_category() const noexcept override
		{
			return AstNode::Category::WhileStatement;
		}

		constexpr std::string_view class_name() const noexcept override
		{
			return "WhileStatement";
		}

	private:
		ExpressionPtr m_condition = nullptr;
		StatementPtr m_body = nullptr;
	};
} // namespace hyper