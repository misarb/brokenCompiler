#include <../include/lexer/lexer.h>
#include <gtest/gtest.h>




TEST(Lexer_test,test_whiteSpace){
    Lexer lexer(" ");

    EXPECT_TRUE(lexer.isWhiteSpace(' '));
    EXPECT_FALSE(lexer.isWhiteSpace('a'));


}
