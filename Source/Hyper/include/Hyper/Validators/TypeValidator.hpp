/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "Hyper/Ast/Forward.hpp"
#include "Hyper/Symbol.hpp"
#include "Hyper/Validator.hpp"

namespace Hyper
{
	class Diagnostics;

	class TypeValidator final : public Validator
	{
	public:
		TypeValidator(
			Diagnostics &diagnostics,
			AstPtr &ast,
			std::vector<Symbol> symbols);

		void accept(FunctionDeclaration &declaration) override;
		void accept(TranslationUnitDeclaration &declaration) override;
		void accept(VariableDeclaration &declaration) override;

		void accept(BinaryExpression &expression) override;
		void accept(CallExpression &expression) override;
		void accept(CastExpression &expression) override;
		void accept(ConditionalExpression &expression) override;
		void accept(IdentifierExpression &expression) override;
		void accept(UnaryExpression &expression) override;

		void accept(BoolLiteral &literal) override;
		void accept(IntegerLiteral &literal) override;
		void accept(StringLiteral &literal) override;

		void accept(AssignStatement &statement) override;
		void accept(CompoundAssignStatement &statement) override;
		void accept(CompoundStatement &statement) override;
		void accept(ExpressionStatement &statement) override;
		void accept(IfStatement &statement) override;
		void accept(ReturnStatement &statement) override;
		void accept(WhileStatement &statement) override;

	private:
		Symbol find_symbol(const std::string &identifier) const;

	private:
		std::vector<Symbol> m_symbols = {};

		Symbol m_current_function = {};

		Type m_current_type = {};
	};
} // namespace Hyper
