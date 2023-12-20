export module cipher:substitution;

import std;
import :math;

namespace cipher
{
    export struct rotate_letter
    {
        explicit constexpr rotate_letter(int n) : n_(n) {}

        [[nodiscard]] constexpr char operator()(const char ch) const
        {
            if (ch >= 'a' && ch <= 'z')
            {
                return 'a' + math::mod_floored(ch - 'a' + n_, 26);
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                return 'A' + math::mod_floored(ch - 'A' + n_, 26);
            }

            return ch;
        }

    private:
        int n_{ 0 };
    };

    // f(x) = a * x + b
    export struct affine_letter
    {
        explicit constexpr affine_letter(int a, int b) : a_{ a }, b_{ b } {}

        [[nodiscard]] constexpr char operator()(const char ch) const
        {
            if (ch >= 'a' && ch <= 'z')
            {
                return 'a' + math::mod_floored(a_ * (ch - 'a') + b_, 26);
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                return 'A' + math::mod_floored(a_ * (ch - 'A') + b_, 26);
            }

            return ch;
        }

    private:
        int a_{ 0 };
        int b_{ 0 };
    };

    export struct reverse_letter
    {
        [[nodiscard]] constexpr char operator()(const char ch) const
        {
            if (ch >= 'a' && ch <= 'z')
            {
                return 'a' + (25 - (ch - 'a'));
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                return 'A' + (25 - (ch - 'A'));
            }

            return ch;
        }
    };

    export [[nodiscard]] std::string caesar(std::string_view s, int n)
    {
        std::string ret{ s };
        std::ranges::transform(ret, ret.begin(), rotate_letter{ n });
        return ret;
    }

    export template <std::ranges::input_range R>
    void caesar_inplace(R&& r, int n)
    {
        std::ranges::transform(r, std::ranges::begin(r), rotate_letter{ n });
    }

    export [[nodiscard]] std::string rot13(std::string_view s)
    {
        std::string ret{ s };
        std::ranges::transform(ret, ret.begin(), rotate_letter{ 13 });
        return ret;
    }

    export template <std::ranges::input_range R>
    void rot13_inplace(R&& r)
    {
        std::ranges::transform(r, std::ranges::begin(r), rotate_letter{ 13 });
    }

    export [[nodiscard]] std::string affine(std::string_view s, int a, int b)
    {
        std::string ret{ s };
        std::ranges::transform(ret, ret.begin(), affine_letter{ a, b });
        return ret;
    }

    export template <std::ranges::input_range R>
    void affine_inplace(R&& r, int a, int b)
    {
        std::ranges::transform(r, std::ranges::begin(r), affine_letter{ a, b });
    }

    export [[nodiscard]] std::string atbash(std::string_view s)
    {
        std::string ret{ s };
        std::ranges::transform(ret, ret.begin(), reverse_letter{});
        return ret;
    }

    export template <std::ranges::forward_range R>
    void atbash_inplace(R&& r)
    {
        std::ranges::transform(r, std::ranges::begin(r), reverse_letter{});
    }
}
