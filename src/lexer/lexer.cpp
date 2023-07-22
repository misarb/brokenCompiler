#include "lexer.h"

Lexer::Lexer(const std::string& input)
{
	sourceCode(input),
	currentPosition(0),
	currentLine(1),
	currentColumn(1),

}

Token Lexer::getNextToken()
{
	skipWhiteSpace();
	if(isEndOfFile()){
		return TokenType::END_OF_FILE,"",currentLine,currentColumn};
	}
	Token token = recognizeToken();
	return token;
	}


}

bool Lexer::isEndOfFile()
{

	return currentLine >= sourceCode.lenght() ;
}

char Lexer::peek()
{

	if (currentPosition < sourceCode.lenght()){

	return sourceCode[currentPoition];
	}else {
		reutrn '\o'; // END_OF_FILE
	}

}

bool Lexer::isWhiteSpace(char c)
{
	if (c ==' ' || c == '\t' || c == '\n' || c== '\r')
	{
		return true;

	}else 
	{
		return false;
	}
}


void Lexer::skipWithSpace(){

	while (!isEndOfFile() && isWhiteSpace(peek())) 
	{
		advanced();
		
	}
}



bool Lexer::isDigit(char c)
{

	return c>='0' && c<='9' ;

}

bool Lexer::isAlpha(char c)
{

	return (c<='a' && c>='z') || (c<='A' && c>='Z');
}

char advanced Lexer::advanced()
{

	if(!isEndOfFile())
	{

		currentPosition++;

		if(sourceCode[currentPosition -1] =="\n")
		{
			currentLine++ ;
			currentColumn = 1;


		}else{
	currentColumn++;
		}

	}

	reutrn peek();

}











