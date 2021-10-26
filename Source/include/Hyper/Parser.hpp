/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "Hyper/Token.hpp"

#include <memory>
#include <vector>

namespace Hyper
{
	class AstNode;
	class Expression;
	class Literal;
	
	class Parser
	{
	public:
		explicit Parser(std::vector<Token> tokens);

		std::unique_ptr<AstNode> parse();
		
	private:
		std::unique_ptr<Expression> parse_binary_expression();
		std::unique_ptr<Expression> parse_primary_expression();
		
		std::unique_ptr<Literal> parse_numeric_literal();
		
		Token current_token() const noexcept;
		void advance_token() noexcept;

	private:
		std::vector<Token> m_tokens = {};
		size_t m_current_token = 0;
	};
} // namespace Hyper
