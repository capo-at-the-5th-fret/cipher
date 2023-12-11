import std;
#include <cassert>
import cipher;

int main()
{
    using namespace std::string_view_literals;

    // panagrams
    constexpr std::array sample_texts =
    {
        std::tuple{ "hello"sv, "khoor"sv, 3 },
        std::tuple{ "attackatonce"sv, "exxegoexsrgi"sv, 4 },
        std::tuple{ "xyz"sv, "abc"sv, 3 },
        std::tuple{ "caesar"sv, "fdhvdu"sv, 3 },
        std::tuple{ ""sv, ""sv, 5 },
        std::tuple{ "abc"sv, "abc"sv, 0 },
        std::tuple{ "abc"sv, "zab"sv, -1 },

        std::tuple{ "HELLO"sv, "KHOOR"sv, 3 },
        std::tuple{ "ATTACKATONCE"sv, "EXXEGOEXSRGI"sv, 4 },
        std::tuple{ "XYZ"sv, "ABC"sv, 3 },
        std::tuple{ "CAESAR"sv, "FDHVDU"sv, 3 },
        std::tuple{ ""sv, ""sv, 5 },
        std::tuple{ "ABC"sv, "ABC"sv, 0 },
        std::tuple{ "ABC"sv, "ZAB"sv, -1 },

        std::tuple
        {
            "the quick brown fox jumps over the lazy dog."sv,
            "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald."sv,
            -3
        },

        std::tuple
        {
            "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG."sv,
            "QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD."sv,
            -3
        },

        std::tuple
        {
            "sphinx of black quartz, judge my vow!"sv,
            "ifxydn ev rbqsa gkqhjp, zktwu co lem!"sv,
            42
        },

        std::tuple
        {
            "SPHINX OF BLACK QUARTZ, JUDGE MY VOW!"sv,
            "IFXYDN EV RBQSA GKQHJP, ZKTWU CO LEM!"sv,
            42
        },

        std::tuple
        {
            "sphinx of black quartz, judge my vow!"sv,
            "czrsxh yp lvkmu aekbdj, tenqo wi fyg!"sv,
            -42
        },

        std::tuple
        {
            "SPHINX OF BLACK QUARTZ, JUDGE MY VOW!"sv,
            "CZRSXH YP LVKMU AEKBDJ, TENQO WI FYG!"sv,
            -42
        }

        /*std::tuple
        {
            "waltz, bad nymph, for quick jigs vex."sv,
        },

        std::tuple
        {
            "Glib jocks quiz nymph to vex dwarf."sv
        },

        std::tuple
        {
            "Sphinx of black quartz, judge my vow."sv
        },

        std::tuple
        {
            "How quickly daft jumping zebras vex!"sv
        },

        std::tuple
        {
            "The five boxing wizards jump quickly."sv
        },

        std::tuple
        {
            "Jackdaws love my big sphinx of quartz."sv
        },

        std::tuple
        {
            "Pack my box with five dozen liquor jugs."sv
        }*/
    };

    for (const auto [sample_text, ciphertext, shift] : sample_texts)
    {
        const auto encrypted = cipher::caesar_encode(sample_text, shift);
        assert(encrypted == ciphertext);

        const auto decrypted = cipher::caesar_decode(encrypted, -shift);
        assert(decrypted == sample_text);
    }

    std::println("done.");
}
