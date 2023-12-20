export module cipher:math;

import std;

export namespace cipher::math
{
    // Reference:
    // https://www.youtube.com/watch?v=xVNYurap-lk&ab_channel=C%E1%90%A9%E1%90%A9WeeklyWithJasonTurner

    template <std::integral T>
    constexpr T mod_floored(T x, T y)
    {
        // NOTE: std::floor requires constexpr cmath feature
        // NOTE: The floor algorithm is faster
    #ifdef __cpp_lib_constexpr_cmath
        return x - y * T(std::floor(x / static_cast<double>(y)));
    #else
        return ((x % y) + y) % y;
    #endif
    }
}
