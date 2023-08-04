#include <../include/lexer/lexer.h>
#include <gtest/gtest.h>

// defining test fixture
class LexerTest : public ::testing::Test
{
protected:
    Lexer lexer;
    LexerTest():lexer(""){};
};

TEST_F(LexerTest, test_whiteSpace)
{
    lexer.sourceCode = " ";

    EXPECT_TRUE(lexer.isWhiteSpace(' '));
    EXPECT_TRUE(lexer.isWhiteSpace('\t'));
    EXPECT_TRUE(lexer.isWhiteSpace('\n'));
    EXPECT_TRUE(lexer.isWhiteSpace('\r'));
    EXPECT_FALSE(lexer.isWhiteSpace('\0'));
    EXPECT_FALSE(lexer.isWhiteSpace('a'));
}

TEST_F(LexerTest, EndOfFile)
{
    lexer.sourceCode = "";
    EXPECT_TRUE(lexer.isEndOfFile());
    lexer.sourceCode = "Error";
    EXPECT_FALSE(lexer.isEndOfFile());
}

TEST_F(LexerTest, Digit)
{
    EXPECT_TRUE(lexer.isDigit('2'));
    EXPECT_FALSE(lexer.isDigit('a'));
}

TEST_F(LexerTest, Alpha)
{
    // lower case test
    for (char c = 'a'; c <= 'z'; ++c)
    {
        EXPECT_TRUE(lexer.isAlpha(c));
    }
    // upperCase test
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        EXPECT_TRUE(lexer.isAlpha(c));
    }

    // Other
    EXPECT_FALSE(lexer.isAlpha('_'));
    EXPECT_FALSE(lexer.isAlpha('9'));
}

TEST_F(LexerTest, peekTest)
{
    lexer.sourceCode = "test";
    EXPECT_EQ(lexer.peek(), 't');
    lexer.advanced();
    EXPECT_EQ(lexer.peek(), 'e');
    for (int i = 0; i < 3; ++i)
    {
        lexer.advanced();
    }
    EXPECT_EQ(lexer.peek(), '\0');
}

TEST_F(LexerTest, recognizeTokenInteger)
{
    
    lexer.sourceCode = "123";
    Token token = lexer.recognizeNumber();
    EXPECT_EQ(token.type, TokenType::INTEGER);
    EXPECT_EQ(token.lexeme, "123");
}

TEST_F(LexerTest, recognizeToken_Left_Right_Parenthese)
{
    lexer.sourceCode = "()";
    Token token = lexer.recognizeToken();
    EXPECT_EQ(token.type, TokenType::OPEN_PARANTHESE);
    EXPECT_EQ(token.lexeme, "(");
    Token token2 = lexer.recognizeToken();
    EXPECT_EQ(token2.type, TokenType::CLOSE_PARANTHESE);
    EXPECT_EQ(token2.lexeme, ")");
}
