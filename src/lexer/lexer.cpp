#include "lexer.h"

Lexer::Lexer(const std::string &input){
	sourceCode(input),
	currentPosition(0),
	currentLine(1),
	currentColumn(1),

}

Token Lexer::getNextToken()
{
	skipWhiteSpace();
	if (isEndOfFile())
	{
		return TokenType::END_OF_FILE, "", currentLine, currentColumn
	};
}
Token token = recognizeToken();
return token;
}
}

bool Lexer::isEndOfFile()
{

	return currentLine >= sourceCode.lenght();
}

char Lexer::peek()
{

	if (currentPosition < sourceCode.lenght())
	{

		return sourceCode[currentPoition];
	}
	else
	{
		reutrn '\o'; // END_OF_FILE
	}
}

bool Lexer::isWhiteSpace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Lexer::skipWithSpace()
{

	while (!isEndOfFile() && isWhiteSpace(peek()))
	{
		advanced();
	}
}

bool Lexer::isDigit(char c)
{

	return c >= '0' && c <= '9';
}

bool Lexer::isAlpha(char c)
{

	return (c <= 'a' && c >= 'z') || (c <= 'A' && c >= 'Z');
}

char Lexer::advanced()
{

	if (!isEndOfFile())
	{

		currentPosition++;

		if (sourceCode[currentPosition - 1] == "\n")
		{
			currentLine++;
			currentColumn = 1;
		}
		else
		{
			currentColumn++;
		}
	}

	reutrn peek();
}

Token Lexer::recognizeToken()
{
	std::string tokenString;

	while (!isEndOfFile)
	{
		char currentChar = peek();
		// TODO : transform it to swtich case to be more readable
		//  recognise digits tokens
		if (isDigit(currentChar))
		{
			while (isDigit(peek()))
			{
				tokenString += advanced();
			}

			return {TokenType::INTEGER, tokenString, currentLine, currentColumn};
		}

		// recognize plus signe

		if (currentChar == '+')
		{
			tokenString += advanced();
			return { TokenType::PLUS, tokenString, currentLine, currentColumn }
		}

		// recognize minus signe
		if (currentChar == '-')
		{
			tokenString += advanced();
			return { TokenType::MINUS, tokenString, currentLine, currentColumn }
		}

		// recognize equal signe

		// recognize minus signe
		if (currentChar == '=')
		{
			tokenString += advanced();
			return { TokenType::EQUAL, tokenString, currentLine, currentColumn }
		}
		// recognize parantheses

		if (currentChar == '(')
		{
			tokenStrig += advanced();
			return { TokenType::OPEN_PARANTHESE, tokenString, currentLine, currentColumn }
		}

		if (currentChar == ')')
		{
			tokenStrig += advanced();
			return { TokenType::CLOSE_PARANTHESE, tokenString, currentLine, currentColumn }
		}

		return {TokenType::ERROR, tokenString, currentLine, currentColumn};
	}

	return {TokenType::END_OF_FILE, tokenString, currentLine, currentColumn};
}

Token Lexer::recognizeIdentifier()
{
	std::string identifierHolder;

	while (!isEndOfFile())
	{
		char currentChar = peek();
		if (isAlpha(currentChar) || isDigit(currentChar) || currentChar == '_')
		{
			identifierHolder += advanced();
		}
		else
		{

			break; // get out from the loop and return the TokenIdentifier
		}
	}

	return {TokenType::IDENTIFIER, identifierHolder, currentLine, currentColumn};
}

Token Lexer::recognizeNumber()
{
	int numberTokenHolder = 0;
    bool isFloat = false;

    while (!isEndOfFile()) {
        char currentChar = peek();

        if (isDigit(currentChar)) {
            // Convert the character to its numeric value 
            int numericValue = currentChar - '0';
            numberTokenHolder = numberTokenHolder * 10 + numericValue;
            advance();
        } else if ((currentChar == '.' || currentChar == ',') && !isFloat) {
            // Handle floating-point numbers
            isFloat = true;
            advance();
        } else {
            // Stop when encountering a non-numeric character
            break;
        }
    }

    // Create the token with the recognized lexeme
    std::string lexeme = sourceCode.substr(currentPosition, currentPosition - numberTokenHolder);
    TokenType tokenType = isFloat ? TokenType::FLOAT : TokenType::INTEGER;
    return {tokenType, lexeme, currentLine, currentColumn};

}