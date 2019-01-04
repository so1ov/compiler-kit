//
// Created by Octavia on 02.01.2019.
//

#include <ExpressionParser.hpp>

#include "StringTools.hpp"
#include "ALphabet.hpp"
#include "Token.hpp"
#include "ErrorDescriptor.hpp"

#include <algorithm>
#include <numeric>

cs::ErrorDescriptor cs::ExpressionParser::SplitLexemesBySpaceAndAcquireTokens(std::string _text, std::vector<Token>& _outTokens)
{
	auto tokens = StringTools::Split(std::move(_text));
	for(auto& token : tokens)
	{
		_outTokens.emplace_back(ExpressionParser::AcquireToken(token));
	}

	return ErrorDescriptor();
}

cs::Token cs::ExpressionParser::AcquireToken(std::string _lexeme)
{
	Token acquiredLexeme;
	acquiredLexeme.Body = _lexeme;
	acquiredLexeme.Type = TokenType::Undefined;

	// If token is only one character length and this character belongs to binary operators
	if(_lexeme.size() == 1 && cs::ALphabet::BinaryOperators.find(_lexeme) != std::string::npos)
	{
		acquiredLexeme.Type = TokenType::BinaryOperator;
		return acquiredLexeme;
	}

	bool containsOneOrNoDot = false;
	if(std::count(_lexeme.begin(), _lexeme.end(), ALphabet::NumericDelimeter) <= 1)
	{
		containsOneOrNoDot = true;
	}

	// Check if token consists only of digits and optional the one dot.
	bool containsSomethingNotADigitOrDot = (_lexeme.find_first_not_of(ALphabet::Numeric + ALphabet::NumericDelimeter) != std::string::npos);

	if(containsOneOrNoDot && !containsSomethingNotADigitOrDot)
	{
		acquiredLexeme.Type = TokenType::NumericLiteral;
		return acquiredLexeme;
	}

	// Type is still TokenType::Undefined (unknown)
	return acquiredLexeme;
}

cs::ErrorDescriptor cs::ExpressionParser::FromInfixToPostfix(std::vector<Token> _infixTokens, std::vector<Token>& _outTokens)
{
	std::vector<Token> operators;
	ErrorDescriptor error;

	for(auto& it : _infixTokens)
	{
		switch(it.Type)
		{
			case TokenType::NumericLiteral:
			{
				_outTokens.emplace_back(it);
				break;
			}
			case TokenType::BinaryOperator:
			{
				if(operators.empty())
				{
					operators.emplace_back(it);
				}
				else
				{
					// TOOD operator priority
					_outTokens.emplace_back(*operators.begin());
					operators.clear();
					operators.emplace_back(it);
				}
				break;
			}
			default:
			{
				error.SetErrorMessage("Unrecognized token: " + it.Body);
				return error;
				break;
			}
		}
	}

	if(!operators.empty())
	{
		_outTokens.emplace_back(*operators.begin());
		operators.clear();
	}

	return error;
}

cs::ErrorDescriptor cs::ExpressionParser::TransformNotation(cs::Expression _source, cs::Expression& _destination)
{
	ErrorDescriptor error;

	// Return OK if nothing to transform
	if(_source.GetType() == _destination.GetType())
	{
		return error; // Still has OK
	}

	if(_source.GetType() == ExpressionType::Undefined)
	{
		error.SetErrorMessage("Unknown input expression type.");
		return error;
	}

	if(_destination.GetType() == ExpressionType::Undefined)
	{
		error.SetErrorMessage("Expected result expression type is not set.");
		return error;
	}

	// Infix-to-postfix
	if(_source.GetType() == ExpressionType::Infix && _destination.GetType() == ExpressionType::Postfix)
	{
		std::vector<Token> sourceAsTokens;

		error = SplitLexemesBySpaceAndAcquireTokens(_source.GetBody(), sourceAsTokens);
		if(error)
		{
			return error;
		}

		std::vector<Token> resultTokens;

		error = FromInfixToPostfix(sourceAsTokens, resultTokens);
		if(error)
		{
			return error;
		}

		_destination.SetBody(VectorOfTokensToString(resultTokens));
	}

	return error;
}

std::string cs::ExpressionParser::VectorOfTokensToString(std::vector<cs::Token>& _tokens)
{
	auto result =
			std::accumulate(
				_tokens.begin(),
				_tokens.end(),
				std::string(),
				[](std::string& _resultString, const Token& _token)
				{
					_resultString += _token.Body;
					_resultString += ' ';
					return _resultString;
				}
			);

	// Use Trim(...) to remove the last ' ', if present
	return StringTools::Trim(result);
}
