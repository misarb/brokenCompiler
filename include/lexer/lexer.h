#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
enum class TokenType{

	IDENTIFIER,
	INTEGER,
	FLOAT,
	PLUS,
	MINUS,
	EQUAL,
	SYMBOLE,
};

strun Token {
	TokenType type;
	std::string lexeme;
	int line;
	int column;
};

class Lexer{
public:
	Lexer(const std::string& input);
	Token getNextToken();
	

private:
std::string input;
	int currentPosition;
	int curentLine;
	int currentColumn;


	char peek();
	bool isEndOfFile();
	bool iswhiteSpace(char c);
	bool isDigit(char c);
	bool isAlpha();
	void skipWitheSpace();
	Token recognizeToken();
	Token recognizeIdentifier();
	Token recognizeNumber();
	Token recognizeOperater();


}








#endif // !DEBUG
