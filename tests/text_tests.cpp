module;

#include <doctest/doctest.h>

export module cipher.tests:text;

import std;
import cipher;

namespace
{
    using namespace std::string_view_literals;

    constexpr std::array to_upper_test_values =
    {
        std::tuple{ ""sv, ""sv },
        std::tuple{ " "sv, " "sv },
        std::tuple{ "@"sv, "@"sv },
        std::tuple{ "a"sv, "A"sv },
        std::tuple{ "A"sv, "A"sv },
        std::tuple
        {
            " abcdefghijklmnopqrstuvwxyz!"sv,
            " ABCDEFGHIJKLMNOPQRSTUVWXYZ!"sv
        },
        std::tuple
        {
            " ABCDEFGHIJKLMNOPQRSTUVWXYZ!"sv,
            " ABCDEFGHIJKLMNOPQRSTUVWXYZ!"sv
        }
    };

    constexpr std::array to_lower_test_values =
    {
        std::tuple{ ""sv, ""sv },
        std::tuple{ " "sv, " "sv },
        std::tuple{ "@"sv, "@"sv },
        std::tuple{ "A"sv, "a"sv },
        std::tuple{ "a"sv, "a"sv },
        std::tuple
        {
            " ABCDEFGHIJKLMNOPQRSTUVWXYZ!"sv,
            " abcdefghijklmnopqrstuvwxyz!"sv
        },
        std::tuple
        {
            " abcdefghijklmnopqrstuvwxyz!"sv,
            " abcdefghijklmnopqrstuvwxyz!"sv
        }
    };
}

TEST_CASE("lower")
{
    cipher::text::lower op;

    // lower case letters
    CHECK(op('a') == 'a');
    CHECK(op('b') == 'b');
    CHECK(op('c') == 'c');
    CHECK(op('d') == 'd');
    CHECK(op('e') == 'e');
    CHECK(op('f') == 'f');
    CHECK(op('g') == 'g');
    CHECK(op('h') == 'h');
    CHECK(op('i') == 'i');
    CHECK(op('j') == 'j');
    CHECK(op('k') == 'k');
    CHECK(op('l') == 'l');
    CHECK(op('m') == 'm');
    CHECK(op('n') == 'n');
    CHECK(op('o') == 'o');
    CHECK(op('p') == 'p');
    CHECK(op('q') == 'q');
    CHECK(op('r') == 'r');
    CHECK(op('s') == 's');
    CHECK(op('t') == 't');
    CHECK(op('u') == 'u');
    CHECK(op('v') == 'v');
    CHECK(op('w') == 'w');
    CHECK(op('x') == 'x');
    CHECK(op('y') == 'y');
    CHECK(op('z') == 'z');

    // upper case letters
    CHECK(op('A') == 'a');
    CHECK(op('B') == 'b');
    CHECK(op('C') == 'c');
    CHECK(op('D') == 'd');
    CHECK(op('E') == 'e');
    CHECK(op('F') == 'f');
    CHECK(op('G') == 'g');
    CHECK(op('H') == 'h');
    CHECK(op('I') == 'i');
    CHECK(op('J') == 'j');
    CHECK(op('K') == 'k');
    CHECK(op('L') == 'l');
    CHECK(op('M') == 'm');
    CHECK(op('N') == 'n');
    CHECK(op('O') == 'o');
    CHECK(op('P') == 'p');
    CHECK(op('Q') == 'q');
    CHECK(op('R') == 'r');
    CHECK(op('S') == 's');
    CHECK(op('T') == 't');
    CHECK(op('U') == 'u');
    CHECK(op('V') == 'v');
    CHECK(op('W') == 'w');
    CHECK(op('X') == 'x');
    CHECK(op('Y') == 'y');
    CHECK(op('Z') == 'z');

    // non-letters
    constexpr std::string_view non_letter_test_values =
    {
        "`1234567890-=~!@#$%^&*()_+[]\\{}|;':\",./<>? "
    };

    for (const auto ch : non_letter_test_values)
    {
        CAPTURE(ch);
        CHECK(op(ch) == ch);
    }
}

TEST_CASE("upper")
{
    cipher::text::upper op;

    // lower case letters
    CHECK(op('a') == 'A');
    CHECK(op('b') == 'B');
    CHECK(op('c') == 'C');
    CHECK(op('d') == 'D');
    CHECK(op('e') == 'E');
    CHECK(op('f') == 'F');
    CHECK(op('g') == 'G');
    CHECK(op('h') == 'H');
    CHECK(op('i') == 'I');
    CHECK(op('j') == 'J');
    CHECK(op('k') == 'K');
    CHECK(op('l') == 'L');
    CHECK(op('m') == 'M');
    CHECK(op('n') == 'N');
    CHECK(op('o') == 'O');
    CHECK(op('p') == 'P');
    CHECK(op('q') == 'Q');
    CHECK(op('r') == 'R');
    CHECK(op('s') == 'S');
    CHECK(op('t') == 'T');
    CHECK(op('u') == 'U');
    CHECK(op('v') == 'V');
    CHECK(op('w') == 'W');
    CHECK(op('x') == 'X');
    CHECK(op('y') == 'Y');
    CHECK(op('z') == 'Z');

    // upper case letters
    CHECK(op('A') == 'A');
    CHECK(op('B') == 'B');
    CHECK(op('C') == 'C');
    CHECK(op('D') == 'D');
    CHECK(op('E') == 'E');
    CHECK(op('F') == 'F');
    CHECK(op('G') == 'G');
    CHECK(op('H') == 'H');
    CHECK(op('I') == 'I');
    CHECK(op('J') == 'J');
    CHECK(op('K') == 'K');
    CHECK(op('L') == 'L');
    CHECK(op('M') == 'M');
    CHECK(op('N') == 'N');
    CHECK(op('O') == 'O');
    CHECK(op('P') == 'P');
    CHECK(op('Q') == 'Q');
    CHECK(op('R') == 'R');
    CHECK(op('S') == 'S');
    CHECK(op('T') == 'T');
    CHECK(op('U') == 'U');
    CHECK(op('V') == 'V');
    CHECK(op('W') == 'W');
    CHECK(op('X') == 'X');
    CHECK(op('Y') == 'Y');
    CHECK(op('Z') == 'Z');

    // non-letters
    constexpr std::string_view non_letter_test_values =
    {
        "`1234567890-=~!@#$%^&*()_+[]\\{}|;':\",./<>? "
    };

    for (const auto ch : non_letter_test_values)
    {
        CAPTURE(ch);
        CHECK(op(ch) == ch);
    }
}

TEST_CASE("to_lower")
{
    using namespace cipher::text;

    for (int i = 0; auto const [test_value, expected_result] :
        to_lower_test_values)
    {
        CAPTURE(i);

        CHECK(to_lower(test_value) == expected_result);
        ++i;
    }
}

TEST_CASE("to_lower_inplace")
{
    using namespace cipher::text;

    for (int i = 0; auto const [test_value, expected_result] :
        to_lower_test_values)
    {
        CAPTURE(i);

        std::string test_value_inplace{ test_value };
        to_lower_inplace(test_value_inplace);
        CHECK(test_value_inplace == expected_result);
        ++i;
    }
}

TEST_CASE("to_upper")
{
    using namespace cipher::text;

    for (int i = 0; auto const [test_value, expected_result] :
        to_upper_test_values)
    {
        CAPTURE(i);

        CHECK(to_upper(test_value) == expected_result);
        ++i;
    }
}

TEST_CASE("to_upper_inplace")
{
    using namespace cipher::text;

    for (int i = 0; auto const [test_value, expected_result] :
        to_upper_test_values)
    {
        CAPTURE(i);

        std::string test_value_inplace{ test_value };
        to_upper_inplace(test_value_inplace);
        CHECK(test_value_inplace == expected_result);
        ++i;
    }
}
