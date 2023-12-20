module;

#include <doctest/doctest.h>

export module cipher.tests:alphabet;

import std;
import cipher;

TEST_CASE("latin_lowercase")
{
    CHECK(cipher::latin_lowercase.size() == 26);

    CHECK(cipher::latin_lowercase[0] == 'a');
    CHECK(cipher::latin_lowercase[1] == 'b');
    CHECK(cipher::latin_lowercase[2] == 'c');
    CHECK(cipher::latin_lowercase[3] == 'd');
    CHECK(cipher::latin_lowercase[4] == 'e');
    CHECK(cipher::latin_lowercase[5] == 'f');
    CHECK(cipher::latin_lowercase[6] == 'g');
    CHECK(cipher::latin_lowercase[7] == 'h');
    CHECK(cipher::latin_lowercase[8] == 'i');
    CHECK(cipher::latin_lowercase[9] == 'j');
    CHECK(cipher::latin_lowercase[10] == 'k');
    CHECK(cipher::latin_lowercase[11] == 'l');
    CHECK(cipher::latin_lowercase[12] == 'm');
    CHECK(cipher::latin_lowercase[13] == 'n');
    CHECK(cipher::latin_lowercase[14] == 'o');
    CHECK(cipher::latin_lowercase[15] == 'p');
    CHECK(cipher::latin_lowercase[16] == 'q');
    CHECK(cipher::latin_lowercase[17] == 'r');
    CHECK(cipher::latin_lowercase[18] == 's');
    CHECK(cipher::latin_lowercase[19] == 't');
    CHECK(cipher::latin_lowercase[20] == 'u');
    CHECK(cipher::latin_lowercase[21] == 'v');
    CHECK(cipher::latin_lowercase[22] == 'w');
    CHECK(cipher::latin_lowercase[23] == 'x');
    CHECK(cipher::latin_lowercase[24] == 'y');
    CHECK(cipher::latin_lowercase[25] == 'z');
}

TEST_CASE("latin_uppercase")
{
    CHECK(cipher::latin_uppercase.size() == 26);

    CHECK(cipher::latin_uppercase[0] == 'A');
    CHECK(cipher::latin_uppercase[1] == 'B');
    CHECK(cipher::latin_uppercase[2] == 'C');
    CHECK(cipher::latin_uppercase[3] == 'D');
    CHECK(cipher::latin_uppercase[4] == 'E');
    CHECK(cipher::latin_uppercase[5] == 'F');
    CHECK(cipher::latin_uppercase[6] == 'G');
    CHECK(cipher::latin_uppercase[7] == 'H');
    CHECK(cipher::latin_uppercase[8] == 'I');
    CHECK(cipher::latin_uppercase[9] == 'J');
    CHECK(cipher::latin_uppercase[10] == 'K');
    CHECK(cipher::latin_uppercase[11] == 'L');
    CHECK(cipher::latin_uppercase[12] == 'M');
    CHECK(cipher::latin_uppercase[13] == 'N');
    CHECK(cipher::latin_uppercase[14] == 'O');
    CHECK(cipher::latin_uppercase[15] == 'P');
    CHECK(cipher::latin_uppercase[16] == 'Q');
    CHECK(cipher::latin_uppercase[17] == 'R');
    CHECK(cipher::latin_uppercase[18] == 'S');
    CHECK(cipher::latin_uppercase[19] == 'T');
    CHECK(cipher::latin_uppercase[20] == 'U');
    CHECK(cipher::latin_uppercase[21] == 'V');
    CHECK(cipher::latin_uppercase[22] == 'W');
    CHECK(cipher::latin_uppercase[23] == 'X');
    CHECK(cipher::latin_uppercase[24] == 'Y');
    CHECK(cipher::latin_uppercase[25] == 'Z');
}
