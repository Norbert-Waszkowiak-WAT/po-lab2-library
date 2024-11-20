#include "catch_amalgamated.hpp"
#include "book.cpp"
#include <sstream>

TEST_CASE("Book constructor initializes title, author, and isbn", "[constructor]") {
    Book book("Sample Title", "Sample Author", "123-456-789");
    REQUIRE(book.getTitle() == "Sample Title");
    REQUIRE(book.getAuthor() == "Sample Author");
    REQUIRE(book.getIsbn() == "123-456-789");
}

TEST_CASE("Book destructor outputs the correct string", "[destructor]") {
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    {
        Book book("Sample Title", "Sample Author", "123-456-789");
    }

    std::cout.rdbuf(p_cout_streambuf);
    REQUIRE(oss.str() == "Destroying book: Sample Title\n");
}