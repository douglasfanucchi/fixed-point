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

void test_should_copy_using_copy_constructor()
{
    Fixed fixed;
    fixed.setRawBits(25);
    int expected = 25;

    Fixed result(fixed);

    ASSERT_EQ(expected, result.getRawBits());
}

void test_should_copy_using_assignment_operator()
{
    Fixed fixed, result;
    fixed.setRawBits(25);
    int expected = 25;

    result = fixed;

    ASSERT_EQ(expected, result.getRawBits());
}

void test_should_create_fixed_object_passing_integer_to_constructor()
{
    Fixed fixed(10);
    int expected = 2560;

    int result = fixed.getRawBits();

    ASSERT_EQ(expected, result);
}

void RUN_EXAMPLE_SUITE()
{
    test_should_create_a_fix_point();
    test_should_change_raw_bits();
    test_should_copy_using_copy_constructor();
    test_should_copy_using_assignment_operator();
    test_should_create_fixed_object_passing_integer_to_constructor();
}
