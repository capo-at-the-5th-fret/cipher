export module cipher:caesar;

import std;

namespace cipher
{
    std::string caesar_encode(std::string_view plain_text, int offset)
    {
        return 
        for (auto& ch : plain_text)
        {
            const auto value = ch + offset;
            ch = static_cast<char>(value);
        }
    }

    void caesar_decode(std::string_view cipher_text, int offset)
    {
        for (auto& ch : plain_text)
        {
            const auto value = ch - offset;
            ch = static_cast<char>(value);
        }
    }
}