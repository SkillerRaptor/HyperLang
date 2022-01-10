/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "Hyper/Ast/Expression.hpp"
#include "Hyper/Ast/Forward.hpp"

namespace Hyper
{
	class UnaryExpression final : public Expression
	{
	public:
		struct Operation
		{
			enum class Kind
			{
				Invalid = 0,

				Not,
				Negative,
				Inverse,

				PreIncrement,
				PreDecrement,

				PostIncrement,
				PostDecrement,
			};

			Kind kind = Kind::Invalid;
			SourceRange range = {};
		};

	public:
		UnaryExpression(
			SourceRange range,
			Operation operation,
			ExpressionPtr expression);

		void dump(std::string_view prefix, bool self_last) const override;
		void validate(Validator &validator) override;

		Operation operation() const;
		const ExpressionPtr &expression() const;

		constexpr Category class_category() const noexcept override
		{
			return AstNode::Category::UnaryExpression;
		}

		constexpr std::string_view class_name() const noexcept override
		{
			return "UnaryExpression";
		}

	private:
		Operation m_operation = {};
		ExpressionPtr m_expression = nullptr;
	};
} // namespace Hyper
