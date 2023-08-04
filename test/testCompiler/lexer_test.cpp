#include <../include/lexer/lexer.h>
#include <gtest/gtest.h>

TEST(lexer_test, test_whiteSpace)
{
    Lexer lexer(" ");

    EXPECT_TRUE(lexer.isWhiteSpace(' '));
    EXPECT_TRUE(lexer.isWhiteSpace('\t'));
    EXPECT_TRUE(lexer.isWhiteSpace('\n'));
    EXPECT_TRUE(lexer.isWhiteSpace('\r'));
    EXPECT_FALSE(lexer.isWhiteSpace('\0'));
    EXPECT_FALSE(lexer.isWhiteSpace('a'));
}
TEST(lexer_test, EndOfFile)
{
    Lexer lexer("");
    EXPECT_TRUE(lexer.isEndOfFile());
    Lexer lexer2("Error");
    EXPECT_FALSE(lexer2.isEndOfFile());
}

TEST(lexer_test, Digit)
{
    Lexer lexer(" ");
    EXPECT_TRUE(lexer.isDigit('2'));
    EXPECT_FALSE(lexer.isDigit('a'));
}

TEST(lexer_test, Alpha)
{
    Lexer lexer(" ");

    // lower case test
    for (char c = 'a'; c <= 'z'; ++c)
    {
        EXPECT_TRUE(lexer.isAlpha(c));
    }
    // upperCase test
    for (char c = 'A'; c<= 'Z'; ++c)
    {
        EXPECT_TRUE(lexer.isAlpha(c));
    }

    //Other
    EXPECT_FALSE(lexer.isAlpha('_'));
    EXPECT_FALSE(lexer.isAlpha('19'));
}

TEST(lexer_test,peekTest)
{
    Lexer lexer("test");
    EXPECT_EQ(lexer.peek(),'t');
    lexer.advanced();
    EXPECT_EQ(lexer.peek(),'e');
    for (int i = 0; i < 3; ++i)
    {
        lexer.advanced();
    }
    EXPECT_EQ(lexer.peek(),'\O');

}

TEST(lexer_token,recognizeTokenInteger)
{
    Lexer lexer("5");
    Token token = lexer.recognizeToken();
    EXPECT_EQ(token.type,TokenType::INTEGER);
    EXPECT_EQ(token.lexeme,"5");


}

TEST(lexer_token,recognizeToken_Left_Right_Parenthese)
{
    Lexer lexer("()");
    Token token = lexer.recognizeToken();
    EXPECT_EQ(token.type,TokenType::OPEN_PARANTHESE);
    EXPECT_EQ(token.lexeme,"(");
    Token token2 = lexer.recognizeToken();
    EXPECT_EQ(token2.type,TokenType::CLOSE_PARANTHESE);
    EXPECT_EQ(token2.lexeme,")");
}