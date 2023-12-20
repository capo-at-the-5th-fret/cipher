export module cipher:alphabet;

import std;

namespace cipher
{
    export enum class alphabet
    {
        latin
    };

    export constexpr std::string_view latin_lowercase
    {
        "abcdefghijklmnopqrstuvwxyz"
    };

    export constexpr std::string_view latin_uppercase
    {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    };
}
