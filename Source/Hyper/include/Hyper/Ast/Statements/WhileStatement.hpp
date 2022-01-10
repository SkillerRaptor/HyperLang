/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "Hyper/Ast/Forward.hpp"
#include "Hyper/Ast/Statement.hpp"

namespace Hyper
{
	class Expression;

	class WhileStatement final : public Statement
	{
	public:
		WhileStatement(
			SourceRange range,
			ExpressionPtr condition,
			StatementPtr body);

		void dump(std::string_view prefix, bool self_last) const override;
		void validate(Validator &validator) override;

		const ExpressionPtr &condition() const;
		const StatementPtr &body() const;

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
} // namespace Hyper
