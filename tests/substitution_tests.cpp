module;

#include <doctest/doctest.h>

export module cipher.tests:substitution;

import std;
import cipher;

namespace
{
    using namespace std::string_view_literals;

    constexpr std::string_view non_letter_test_values =
    {
        "`1234567890-=~!@#$%^&*()_+[]\\{}|;':\",./<>? "
    };

    constexpr auto panagram = "pack my box with five dozen liquor jugs."sv;
    constexpr auto panagram_upper = "PACK MY BOX WITH FIVE DOZEN LIQUOR JUGS."sv;
}

TEST_CASE("rotate_letter")
{
    for (int shift = -52; shift <= 52; ++shift)
    {
        cipher::rotate_letter op{ shift };

        // lower case letters
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            CAPTURE(ch);

            const char expected = 'a' +
                cipher::math::mod_floored(ch - 'a' + shift, 26);
            CHECK(op(ch) == expected);
        }

        // upper case letters
        for (char ch = 'A'; ch <= 'Z'; ++ch)
        {
            CAPTURE(ch);

            const char expected = 'A' +
                cipher::math::mod_floored(ch - 'A' + shift, 26);
            CHECK(op(ch) == expected);
        }

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
}

TEST_CASE("affine_letter")
{
    std::array ab_test_values =
    {
        std::tuple{ -1, -1 },
        std::tuple{ -1, 0 },
        std::tuple{ -1, 1 },
        std::tuple{ 0, -1 },
        std::tuple{ 0, 0 },
        std::tuple{ 0, 1 },
        std::tuple{ 1, -1 },
        std::tuple{ 1, 0 },
        std::tuple{ 1, 1 }
    };

    for (const auto [a, b] : ab_test_values)
    {
        CAPTURE(a);
        CAPTURE(b);

        cipher::affine_letter op{ a, b };

        // lower case letters
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            CAPTURE(ch);

            const char expected = 'a' +
                cipher::math::mod_floored(a * (ch - 'a') + b, 26);
            CHECK(op(ch) == expected);
        }

        // upper case letters
        for (char ch = 'A'; ch <= 'Z'; ++ch)
        {
            CAPTURE(ch);

            const char expected = 'A' +
                cipher::math::mod_floored(a * (ch - 'A') + b, 26);
            CHECK(op(ch) == expected);
        }

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
}

TEST_CASE("reverse_letter")
{
    cipher::reverse_letter op;

    // lower case letters
    CHECK(op('a') == 'z');
    CHECK(op('b') == 'y');
    CHECK(op('c') == 'x');
    CHECK(op('d') == 'w');
    CHECK(op('e') == 'v');
    CHECK(op('f') == 'u');
    CHECK(op('g') == 't');
    CHECK(op('h') == 's');
    CHECK(op('i') == 'r');
    CHECK(op('j') == 'q');
    CHECK(op('k') == 'p');
    CHECK(op('l') == 'o');
    CHECK(op('m') == 'n');
    CHECK(op('n') == 'm');
    CHECK(op('o') == 'l');
    CHECK(op('p') == 'k');
    CHECK(op('q') == 'j');
    CHECK(op('r') == 'i');
    CHECK(op('s') == 'h');
    CHECK(op('t') == 'g');
    CHECK(op('u') == 'f');
    CHECK(op('v') == 'e');
    CHECK(op('w') == 'd');
    CHECK(op('x') == 'c');
    CHECK(op('y') == 'b');
    CHECK(op('z') == 'a');

    // upper case letters
    CHECK(op('A') == 'Z');
    CHECK(op('B') == 'Y');
    CHECK(op('C') == 'X');
    CHECK(op('D') == 'W');
    CHECK(op('E') == 'V');
    CHECK(op('F') == 'U');
    CHECK(op('G') == 'T');
    CHECK(op('H') == 'S');
    CHECK(op('I') == 'R');
    CHECK(op('J') == 'Q');
    CHECK(op('K') == 'P');
    CHECK(op('L') == 'O');
    CHECK(op('M') == 'N');
    CHECK(op('N') == 'M');
    CHECK(op('O') == 'L');
    CHECK(op('P') == 'K');
    CHECK(op('Q') == 'J');
    CHECK(op('R') == 'I');
    CHECK(op('S') == 'H');
    CHECK(op('T') == 'G');
    CHECK(op('U') == 'F');
    CHECK(op('V') == 'E');
    CHECK(op('W') == 'D');
    CHECK(op('X') == 'C');
    CHECK(op('Y') == 'B');
    CHECK(op('Z') == 'A');

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

TEST_CASE("caesar")
{
    SUBCASE("empty input")
    {
        CHECK(cipher::caesar("", -1) == "");
        CHECK(cipher::caesar("", 0) == "");
        CHECK(cipher::caesar("", 1) == "");
    }

    SUBCASE("lower case letters")
    {
        CHECK(cipher::caesar(cipher::latin_lowercase, -1) ==
            "zabcdefghijklmnopqrstuvwxy");
        CHECK(cipher::caesar(cipher::latin_lowercase, 0) ==
            "abcdefghijklmnopqrstuvwxyz");
        CHECK(cipher::caesar(cipher::latin_lowercase, 1) ==
            "bcdefghijklmnopqrstuvwxyza");
    }

    SUBCASE("upper case letters")
    {
        CHECK(cipher::caesar(cipher::latin_uppercase, -1) ==
            "ZABCDEFGHIJKLMNOPQRSTUVWXY");
        CHECK(cipher::caesar(cipher::latin_uppercase, 0) ==
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        CHECK(cipher::caesar(cipher::latin_uppercase, 1) ==
            "BCDEFGHIJKLMNOPQRSTUVWXYZA");
    }

    SUBCASE("non-letters")
    {
        CHECK(cipher::caesar(non_letter_test_values, -1) ==
            non_letter_test_values);
        CHECK(cipher::caesar(non_letter_test_values, 0) ==
            non_letter_test_values);
        CHECK(cipher::caesar(non_letter_test_values, 1) ==
            non_letter_test_values);
    }

    SUBCASE("panagram")
    {
        constexpr std::array expected_results =
        {
            // offset 0 through 25
            "pack my box with five dozen liquor jugs."sv,
            "qbdl nz cpy xjui gjwf epafo mjrvps kvht."sv,
            "rcem oa dqz ykvj hkxg fqbgp nkswqt lwiu."sv,
            "sdfn pb era zlwk ilyh grchq oltxru mxjv."sv,
            "tego qc fsb amxl jmzi hsdir pmuysv nykw."sv,
            "ufhp rd gtc bnym knaj itejs qnvztw ozlx."sv,
            "vgiq se hud cozn lobk jufkt rowaux pamy."sv,
            "whjr tf ive dpao mpcl kvglu spxbvy qbnz."sv,
            "xiks ug jwf eqbp nqdm lwhmv tqycwz rcoa."sv,
            "yjlt vh kxg frcq oren mxinw urzdxa sdpb."sv,
            "zkmu wi lyh gsdr psfo nyjox vsaeyb teqc."sv,
            "alnv xj mzi htes qtgp ozkpy wtbfzc ufrd."sv,
            "bmow yk naj iuft ruhq palqz xucgad vgse."sv,
            "cnpx zl obk jvgu svir qbmra yvdhbe whtf."sv,
            "doqy am pcl kwhv twjs rcnsb zweicf xiug."sv,
            "eprz bn qdm lxiw uxkt sdotc axfjdg yjvh."sv,
            "fqsa co ren myjx vylu tepud bygkeh zkwi."sv,
            "grtb dp sfo nzky wzmv ufqve czhlfi alxj."sv,
            "hsuc eq tgp oalz xanw vgrwf daimgj bmyk."sv,
            "itvd fr uhq pbma ybox whsxg ebjnhk cnzl."sv,
            "juwe gs vir qcnb zcpy xityh fckoil doam."sv,
            "kvxf ht wjs rdoc adqz yjuzi gdlpjm epbn."sv,
            "lwyg iu xkt sepd bera zkvaj hemqkn fqco."sv,
            "mxzh jv ylu tfqe cfsb alwbk ifnrlo grdp."sv,
            "nyai kw zmv ugrf dgtc bmxcl jgosmp hseq."sv,
            "ozbj lx anw vhsg ehud cnydm khptnq itfr."sv
        };
        static_assert(expected_results.size() == 26);

        for (int shift = -52; shift <= 52; ++shift)
        {
            CAPTURE(shift);

            const std::size_t index = cipher::math::mod_floored(shift, 26);
            const auto expected_result = expected_results[index];

            SUBCASE("lowercase letters")
            {
                CHECK(cipher::caesar(panagram, shift) == expected_result);
                CHECK(cipher::caesar(expected_result, -shift) == panagram);
            }

            SUBCASE("uppercase letters")
            {
                const auto expected_result_upper =
                    cipher::text::to_upper(expected_result);
                CHECK(cipher::caesar(panagram_upper, shift) ==
                    expected_result_upper);
                CHECK(cipher::caesar(expected_result_upper, -shift) ==
                    panagram_upper);
            }
            
            ++shift;
        }
    }
}

TEST_CASE("rot13")
{
    SUBCASE("empty input")
    {
        CHECK(cipher::rot13("") == "");
    }

    SUBCASE("lower case letters")
    {
        CHECK(cipher::rot13(cipher::latin_lowercase) ==
            "nopqrstuvwxyzabcdefghijklm");
    }

    SUBCASE("upper case letters")
    {
        CHECK(cipher::rot13(cipher::latin_uppercase) ==
            "NOPQRSTUVWXYZABCDEFGHIJKLM");
    }

    SUBCASE("non-letters")
    {
        CHECK(cipher::rot13(non_letter_test_values) == non_letter_test_values);
    }

    SUBCASE("panagram")
    {
        CHECK(cipher::rot13(panagram) ==
            "cnpx zl obk jvgu svir qbmra yvdhbe whtf.");
        CHECK(cipher::rot13(panagram_upper) ==
            "CNPX ZL OBK JVGU SVIR QBMRA YVDHBE WHTF.");
    }
}

TEST_CASE("affine")
{
    SUBCASE("empty input")
    {
        CHECK(cipher::affine("", -1, -1) == "");
        CHECK(cipher::affine("", -1, 0) == "");
        CHECK(cipher::affine("", -1, 1) == "");
        CHECK(cipher::affine("", 0, -1) == "");
        CHECK(cipher::affine("", 0, 0) == "");
        CHECK(cipher::affine("", 0, 1) == "");
        CHECK(cipher::affine("", 1, -1) == "");
        CHECK(cipher::affine("", 1, 0) == "");
        CHECK(cipher::affine("", 1, 1) == "");
    }

    SUBCASE("lower case letters")
    {
        CHECK(cipher::affine(cipher::latin_lowercase, -1, -1) == "zyxwvutsrqponmlkjihgfedcba");
        CHECK(cipher::affine(cipher::latin_lowercase, -1, 0) == "azyxwvutsrqponmlkjihgfedcb");
        CHECK(cipher::affine(cipher::latin_lowercase, -1, 1) == "bazyxwvutsrqponmlkjihgfedc");

        CHECK(cipher::affine(cipher::latin_lowercase, 0, -1) == "zzzzzzzzzzzzzzzzzzzzzzzzzz");
        CHECK(cipher::affine(cipher::latin_lowercase, 0, 0) == "aaaaaaaaaaaaaaaaaaaaaaaaaa");
        CHECK(cipher::affine(cipher::latin_lowercase, 0, 1) == "bbbbbbbbbbbbbbbbbbbbbbbbbb");

        CHECK(cipher::affine(cipher::latin_lowercase, 1, -1) == "zabcdefghijklmnopqrstuvwxy");
        CHECK(cipher::affine(cipher::latin_lowercase, 1, 0) == "abcdefghijklmnopqrstuvwxyz");
        CHECK(cipher::affine(cipher::latin_lowercase, 1, 1) == "bcdefghijklmnopqrstuvwxyza");
    }

    SUBCASE("upper case letters")
    {
        CHECK(cipher::affine(cipher::latin_uppercase, -1, -1) == "ZYXWVUTSRQPONMLKJIHGFEDCBA");
        CHECK(cipher::affine(cipher::latin_uppercase, -1, 0) == "AZYXWVUTSRQPONMLKJIHGFEDCB");
        CHECK(cipher::affine(cipher::latin_uppercase, -1, 1) == "BAZYXWVUTSRQPONMLKJIHGFEDC");

        CHECK(cipher::affine(cipher::latin_uppercase, 0, -1) == "ZZZZZZZZZZZZZZZZZZZZZZZZZZ");
        CHECK(cipher::affine(cipher::latin_uppercase, 0, 0) == "AAAAAAAAAAAAAAAAAAAAAAAAAA");
        CHECK(cipher::affine(cipher::latin_uppercase, 0, 1) == "BBBBBBBBBBBBBBBBBBBBBBBBBB");

        CHECK(cipher::affine(cipher::latin_uppercase, 1, -1) == "ZABCDEFGHIJKLMNOPQRSTUVWXY");
        CHECK(cipher::affine(cipher::latin_uppercase, 1, 0) == "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        CHECK(cipher::affine(cipher::latin_uppercase, 1, 1) == "BCDEFGHIJKLMNOPQRSTUVWXYZA");
    }

    SUBCASE("non-letters")
    {
        CHECK(cipher::affine(non_letter_test_values, -1, -1) == non_letter_test_values);
        CHECK(cipher::affine(non_letter_test_values, -1, 0) == non_letter_test_values);
        CHECK(cipher::affine(non_letter_test_values, -1, 1) == non_letter_test_values);
        CHECK(cipher::affine(non_letter_test_values, 0, -1) == non_letter_test_values);
        CHECK(cipher::affine(non_letter_test_values, 0, 0) == non_letter_test_values);
        CHECK(cipher::affine(non_letter_test_values, 0, 1) == non_letter_test_values);
        CHECK(cipher::affine(non_letter_test_values, 1, -1) == non_letter_test_values);
        CHECK(cipher::affine(non_letter_test_values, 1, 0) == non_letter_test_values);
        CHECK(cipher::affine(non_letter_test_values, 1, 1) == non_letter_test_values);
    }

    SUBCASE("panagram")
    {
        CHECK(cipher::affine(panagram, -8, -5) ==
            "fvft dl nnt bjzr hjjp xndpv ljxrnp brzh.");
        CHECK(cipher::affine(panagram_upper, -8, -5) ==
            "FVFT DL NNT BJZR HJJP XNDPV LJXRNP BRZH.");

            CHECK(cipher::affine(panagram, -8, 5) ==
            "pfpd nv xxd ltjb rttz hxnzf vthbxz lbjr.");
        CHECK(cipher::affine(panagram_upper, -8, 5) ==
            "PFPD NV XXD LTJB RTTZ HXNZF VTHBXZ LBJR.");

        CHECK(cipher::affine(panagram, 8, -5) ==
            "lvlx nf ddx phrz jhhb tdnbv fhtzdb pzrj.");
        CHECK(cipher::affine(panagram_upper, 8, -5) ==
            "LVLX NF DDX PHRZ JHHB TDNBV FHTZDB PZRJ.");

        CHECK(cipher::affine(panagram, 8, 5) ==
            "vfvh xp nnh zrbj trrl dnxlf prdjnl zjbt.");
        CHECK(cipher::affine(panagram_upper, 8, 5) ==
            "VFVH XP NNH ZRBJ TRRL DNXLF PRDJNL ZJBT.");
    }
}

TEST_CASE("atbash")
{
    SUBCASE("empty input")
    {
        CHECK(cipher::atbash("") == "");
    }

    SUBCASE("lower case letters")
    {
        CHECK(cipher::atbash(cipher::latin_lowercase) ==
            "zyxwvutsrqponmlkjihgfedcba");
    }

    SUBCASE("upper case letters")
    {
        CHECK(cipher::atbash(cipher::latin_uppercase) ==
            "ZYXWVUTSRQPONMLKJIHGFEDCBA");
    }

    SUBCASE("non-letters")
    {
        CHECK(cipher::atbash(non_letter_test_values) == non_letter_test_values);
    }

    SUBCASE("panagram")
    {
        CHECK(cipher::atbash(panagram) ==
            "kzxp nb ylc drgs urev wlavm orjfli qfth.");
        CHECK(cipher::atbash(panagram_upper) ==
            "KZXP NB YLC DRGS UREV WLAVM ORJFLI QFTH.");
    }
}
