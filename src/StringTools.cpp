//
// Created by Octavia on 02.01.2019.
//

#include <StringTools.hpp>

std::vector<std::string> cs::StringTools::Split(std::string _source, std::string _delims)
{
	enum State
	{
		OutsideSubstring,
		InsideSubstring
	};

	State state = OutsideSubstring;
	std::size_t currentTokenStartIndex = -1; // knowingly invalid index, just to fail-fast on possible bugs

	std::vector<std::string> parsedSubstrings;

	// Insert space to the end of source string to determine last substring end
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
			case OutsideSubstring:
			{
				if(isDelimeter) // We are outside substring and next symbol is not a next substring part, skip it
				{
					break;
				}
				currentTokenStartIndex = i;
				state = InsideSubstring;
				break;
			}
			case InsideSubstring:
			{
				if(!isDelimeter) // We are inside substring and next symbol is not a delimeter, skip
				{
					break;
				}
				// Take a substring from the current substring beginning to the current position (i). Another substring parsed.
				parsedSubstrings.emplace_back(_source.substr(currentTokenStartIndex, i - currentTokenStartIndex));
				state = OutsideSubstring;
				break;
			}
		}
	}

	return parsedSubstrings;
}
