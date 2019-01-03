//
// Created by Octavia on 02.01.2019.
//

#include <ExpressionParser.hpp>

#include "StringTools.hpp"
#include "ALphabet.hpp"
#include "Lexeme.hpp"

#include <algorithm>

std::vector<cs::Lexeme> cs::ExpressionParser::SplitBySpaceAndAcquireTokens(std::string _text)
{
	std::vector<cs::Lexeme> lexemes;

	auto tokens = StringTools::Split(std::move(_text));
	for(auto& token : tokens)
	{
		lexemes.emplace_back(ExpressionParser::AcquireLexeme(token));
	}

	return lexemes;
}

cs::Lexeme cs::ExpressionParser::AcquireLexeme(std::string _token)
{
	Lexeme acquiredLexeme;
	acquiredLexeme.Body = _token;
	acquiredLexeme.Type = LexemeType::Undefined;

	// If token is only one character length and this character belongs to binary operators
	if(_token.size() == 1 && cs::ALphabet::BinaryOperators.find(_token) != std::string::npos)
	{
		acquiredLexeme.Type = LexemeType::BinaryOperator;
		return acquiredLexeme;
	}

	bool containsOneOrNoDot = false;
	if(std::count(_token.begin(), _token.end(), ALphabet::NumericDelimeter) <= 1)
	{
		containsOneOrNoDot = true;
	}

	// Check if token consists only of digits and optional the one dot.
	bool containsSomethingNotADigitOrDot = (_token.find_first_not_of(ALphabet::Numeric + ALphabet::NumericDelimeter) != std::string::npos);

	if(containsOneOrNoDot && !containsSomethingNotADigitOrDot)
	{
		acquiredLexeme.Type = LexemeType::NumericLiteral;
		return acquiredLexeme;
	}

	// Type is still LexemeType::Undefined (unknown)
	return acquiredLexeme;
}

std::vector<cs::Lexeme> cs::ExpressionParser::FromInfixToPostfix(std::vector<Lexeme> _infixLexemes)
{
	std::vector<Lexeme> postfixLexemes;

	std::vector<Lexeme> operators;

	for(auto& it : _infixLexemes)
	{
		switch(it.Type)
		{
			case LexemeType::NumericLiteral:
			{
				postfixLexemes.emplace_back(it);
				break;
			}
			case LexemeType::BinaryOperator:
			{
				if(operators.empty())
				{
					operators.emplace_back(it);
				}
				else
				{
					// TOOD operator priority
					postfixLexemes.emplace_back(*operators.begin());
					operators.clear();
					operators.emplace_back(it);
				}
				break;
			}
		}
	}

	if(!operators.empty())
	{
		postfixLexemes.emplace_back(*operators.begin());
		operators.clear();
	}

	return postfixLexemes;
}
