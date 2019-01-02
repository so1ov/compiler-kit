//
// Created by Octavia on 02.01.2019.
//

#include <StringTools.hpp>

std::vector<std::string> cs::StringTools::Split(std::string _source, std::string _delims)
{
	enum State
	{
		OutsideToken,
		InsideToken
	};

	State state = OutsideToken;
	std::size_t currentTokenStartIndex;

	std::vector<std::string> parsedTokens;

	// Insert space to the end of source string to determine last lexeme end
	_source += ' ';
	for(std::size_t i = 0; i < _source.size(); i++)
	{
		bool isDelimeter = false;

		if(_delims.find(_source[i]) != std::string::npos)
		{
			isDelimeter = true;
		}

		switch(state)
		{
			case OutsideToken:
			{
				if(isDelimeter) // We are outside token and next symbol is not a token part, skip it
				{
					break;
				}
				currentTokenStartIndex = i;
				state = InsideToken;
				break;
			}
			case InsideToken:
			{
				if(!isDelimeter) // We are inside token and next symbol is not a token end, skip
				{
					break;
				}
				// Take a substring from the current token beginning to the current position (i). Token parsed.
				parsedTokens.emplace_back(_source.substr(currentTokenStartIndex, i - currentTokenStartIndex));
				state = OutsideToken;
				break;
			}
		}
	}

	return parsedTokens;
}
