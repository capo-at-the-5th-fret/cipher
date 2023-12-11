export module cipher:substitution;

import std;
import :math;

namespace cipher
{
    export struct caesar
    {
        constexpr explicit caesar(int shift) : shift_{ shift } {}

        constexpr char operator()(const char ch) const
        {
            if (ch >= 'a' && ch <= 'z')
            {
                return 'a' + math::mod_floored(ch - 'a' + shift_, 26);
                //return 'a' + (ch - 'a' + shift_) % 26;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                return 'A' + math::mod_floored(ch - 'A' + shift_, 26);
                //return 'A' + (ch - 'A' + shift_) % 26;
            }

            return ch;
        }

    private:
        int shift_{ 0 };
    };

    export struct rot13
    {
        constexpr char operator()(const char ch) const
        {
            if (ch >= 'a')
            {
                if (ch <= 'm')
                {
                    return ch + 13;
                }
                else if (ch <= 'z')
                {
                    return ch - 13;
                }
            }
            else if (ch >= 'A')
            {
                if (ch <= 'M')
                {
                    return ch + 13;
                }
                else if (ch <= 'Z')
                {
                    return ch - 13;
                }
            }

            return ch;
        }
    };

    export std::string caesar_encode(std::string_view plaintext, int shift)
    {
        std::string ret;

        if (!plaintext.empty())
        {
            ret.reserve(plaintext.size());

            std::ranges::copy(std::views::transform(plaintext, caesar{ shift }),
                std::back_inserter(ret));
        }

        return ret;
    }

    export std::string caesar_decode(std::string_view ciphertext, int shift)
    {
        std::string ret;

        if (!ciphertext.empty())
        {
            ret.reserve(ciphertext.size());

            std::ranges::copy(std::views::transform(ciphertext, caesar{ shift }),
                std::back_inserter(ret));
        }

        return ret;
    }

    export std::string rot13_encode(std::string_view plaintext)
    {
        std::string ret;

        if (!plaintext.empty())
        {
            ret.reserve(plaintext.size());

            std::ranges::copy(std::views::transform(plaintext, rot13{}),
                std::back_inserter(ret));
        }

        return ret;
    }

    export std::string rot13_decode(std::string_view ciphertext)
    {
        return rot13_encode(ciphertext);
    }

    constexpr char rot(const char ch, const char base, int offset)
    {
        return base + (ch - base + offset) % 26;
    }

    export constexpr char rot13_2(const char ch)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            return rot(ch, 'a', 13);
        }

        if (ch >= 'A' && ch <= 'Z')
        {
            return rot(ch, 'A', 13);
        }

        return ch;
    }
}
