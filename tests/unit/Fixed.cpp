#include <asserts.hpp>
#include <Fixed.hpp>

void test_should_create_a_fix_point()
{
    Fixed fixed;
    int expected = 0;

    int result = fixed.getRawBits();

    ASSERT_EQ(expected, result);
}

void test_should_change_raw_bits()
{
    Fixed fixed;
    int const expected = 25;

    fixed.setRawBits(25);
    int result = fixed.getRawBits();

    ASSERT_EQ(expected, result);
}

void RUN_EXAMPLE_SUITE()
{
    test_should_create_a_fix_point();
    test_should_change_raw_bits();
}
