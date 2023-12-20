export module cipher:text;

import std;

namespace cipher::text
{
    export enum class letter_case
    {
        lowercase,
        uppercase
    };

    export enum class case_sensitivity
    {
        sensitive,
        insensitive
    };

    // Reference:
    // https://en.cppreference.com/w/cpp/string/byte/tolower
    // https://en.cppreference.com/w/cpp/string/byte/toupper
    // https://en.cppreference.com/w/cpp/algorithm/ranges/transform

    export struct lower
    {
        [[nodiscard]] constexpr char operator()(const char ch) const
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                return static_cast<char>(
                    std::tolower(static_cast<unsigned char>(ch)));
            }
            return ch;
        }
    };

    export struct upper
    {
        [[nodiscard]] constexpr char operator()(const char ch) const
        {
            if (ch >= 'a' && ch <= 'z')
            {
                return static_cast<char>(
                    std::toupper(static_cast<unsigned char>(ch)));
            }
            return ch;
        }
    };

    export std::string to_lower(std::string_view s)
    {
        std::string ret{ s };
        std::ranges::transform(ret, ret.begin(), lower{});
        return ret;
    }

    export template <std::ranges::input_range R>
    void to_lower_inplace(R&& r)
    {
        std::ranges::transform(r, std::ranges::begin(r), lower{});
    }

    export std::string to_upper(std::string_view s)
    {
        std::string ret{ s };
        std::ranges::transform(ret, ret.begin(), upper{});
        return ret;
    }

    export template <std::ranges::input_range R>
    void to_upper_inplace(R&& r)
    {
        std::ranges::transform(r, std::ranges::begin(r), upper{});
    }
}
