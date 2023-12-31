#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
enum class TokenType
{

	IDENTIFIER,
	INTEGER,
	FLOAT,
	PLUS,
	MINUS,
	EQUAL,
	SYMBOLE,
	END_OF_FILE,
	OPEN_PARANTHESE,
	CLOSE_PARANTHESE,
	ERROR,
};

struct Token
{
	TokenType type;
	std::string lexeme;
	int line;
	int column;
};

class Lexer
{
public:
	Lexer(const std::string &input);
	Token getNextToken();

	std::string sourceCode;
	int currentPosition;
	int currentLine;
	int currentColumn;

	// methode
	char advanced();
	char peek();
	bool isEndOfFile();
	bool isWhiteSpace(char c);
	bool isDigit(char c);
	bool isAlpha(char c);
	void skipWitheSpace();
	Token recognizeToken();
	Token recognizeIdentifier();
	Token recognizeNumber();
};

#endif // !DEBUG
