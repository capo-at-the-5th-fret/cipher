module;

#include <doctest/doctest.h>

export module cipher.tests:math;

import std;
import cipher;

TEST_CASE("mod_floored")
{
    using namespace cipher::math;

    CHECK(mod_floored(0, 4) == 0);
    CHECK(mod_floored(1, 4) == 1);
    CHECK(mod_floored(2, 4) == 2);
    CHECK(mod_floored(3, 4) == 3);
    CHECK(mod_floored(4, 4) == 0);
    CHECK(mod_floored(5, 4) == 1);
    CHECK(mod_floored(6, 4) == 2);
    CHECK(mod_floored(7, 4) == 3);
    CHECK(mod_floored(8, 4) == 0);

    CHECK(mod_floored(-1, 4) == 3);
    CHECK(mod_floored(-2, 4) == 2);
    CHECK(mod_floored(-3, 4) == 1);
    CHECK(mod_floored(-4, 4) == 0);
    CHECK(mod_floored(-5, 4) == 3);
    CHECK(mod_floored(-6, 4) == 2);
    CHECK(mod_floored(-7, 4) == 1);
    CHECK(mod_floored(-8, 4) == 0);

    CHECK(mod_floored(0, -4) == 0);
    CHECK(mod_floored(1, -4) == -3);
    CHECK(mod_floored(2, -4) == -2);
    CHECK(mod_floored(3, -4) == -1);
    CHECK(mod_floored(4, -4) == 0);
    CHECK(mod_floored(5, -4) == -3);
    CHECK(mod_floored(6, -4) == -2);
    CHECK(mod_floored(7, -4) == -1);
    CHECK(mod_floored(8, -4) == 0);

    CHECK(mod_floored(-1, -4) == -1);
    CHECK(mod_floored(-2, -4) == -2);
    CHECK(mod_floored(-3, -4) == -3);
    CHECK(mod_floored(-4, -4) == 0);
    CHECK(mod_floored(-5, -4) == -1);
    CHECK(mod_floored(-6, -4) == -2);
    CHECK(mod_floored(-7, -4) == -3);
    CHECK(mod_floored(-8, -4) == 0);
}