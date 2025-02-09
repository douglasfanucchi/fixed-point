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

void test_should_create_fixed_object_passing_double_to_constructor()
{
    Fixed fixed(10.5);
    int expected = 2688;

    int result = fixed.getRawBits();

    ASSERT_EQ(expected, result);
}

void test_should_convert_fixed_value_to_int()
{
    Fixed fixed(10);
    int expected = 10;

    int result = fixed.toInt();

    ASSERT_EQ(expected, result);
}

void test_should_convert_fixed_value_to_double()
{
    Fixed fixed(10.5);
    double expected = 10.5;

    double result = fixed.toDouble();

    ASSERT_TRUE(abs(expected - result) < 0.001);
}

void test_should_compare_decimals_fixed_values_as_greater_than()
{
    Fixed n1(10.6);
    Fixed n2(10.5);

    bool result = n1 > n2;

    ASSERT_TRUE(result);
}

void test_should_compare_decimals_fixed_values_as_less_than()
{
    Fixed n1(10.5), n2(10.6);

    bool result = n1 < n2;

    ASSERT_TRUE(result);
}

void test_should_compare_integer_fixed_values_as_greater_than()
{
    Fixed n1(11), n2(10);

    bool result = n1 > n2;

    ASSERT_TRUE(result);
}

void test_should_compare_integer_fixed_values_as_less_than()
{
    Fixed n1(10), n2(11);

    bool result = n1 < n2;

    ASSERT_TRUE(result);
}

void test_should_compare_decimals_fixed_values_as_equal()
{
    Fixed n1(10.5), n2(10.5);

    bool result = n1 == n2;

    ASSERT_TRUE(result);
}

void test_should_compare_integer_fixed_values_as_equal()
{
    Fixed n1(10), n2(10);

    bool result = n1 == n2;

    ASSERT_TRUE(result);
}

void test_should_compare_decimals_fixed_values_as_greater_equal()
{
    Fixed n1(10.5), n2(10.5);
    bool result = n1 >= n2;
    ASSERT_TRUE(result);

    Fixed n3(10.6), n4(10.5);
    result = n3 >= n4;
    ASSERT_TRUE(result);
}

void test_should_compare_integer_fixed_values_as_greater_equal()
{
    Fixed n1(10), n2(10);
    bool result = n1 >= n2;
    ASSERT_TRUE(result);

    Fixed n3(11), n4(10);
    result = n3 >= n4;
    ASSERT_TRUE(result);
}

void test_should_compare_decimals_values_as_less_equal()
{
    Fixed n1(10.5), n2(10.5);
    bool result = n1 <= n2;
    ASSERT_TRUE(result);

    Fixed n3(10.5), n4(10.6);
    result = n3 <= n4;
    ASSERT_TRUE(result);
}

void test_should_compare_integer_fixed_values_as_less_equal()
{
    Fixed n1(10), n2(10);
    bool result = n1 <= n2;
    ASSERT_TRUE(result);

    Fixed n3(10), n4(11);
    result = n3 <= n4;
    ASSERT_TRUE(result);
}

void test_should_compare_decimal_fixed_values_as_not_equal()
{
    Fixed n1(10.55), n2(10.56);

    bool result = n1 != n2;

    ASSERT_TRUE(result);
}

void test_should_compare_integer_fixed_values_as_not_equal()
{
    Fixed n1(10), n2(11);

    bool result = n1 != n2;

    ASSERT_TRUE(result);
}

void test_should_add_two_fixed_points()
{
    Fixed n1(0.3), n2(0.7);
    Fixed expected(1);

    Fixed result = n1 + n2;

    ASSERT_EQ(expected.getRawBits(), result.getRawBits());
}

void test_should_subtract_two_fixed_values()
{
    Fixed n1(1), n2(0.7);
    Fixed expected(0.3);

    Fixed result = n1 - n2;

    ASSERT_EQ(expected.getRawBits(), result.getRawBits());
}

void test_should_multiply_two_fixed_values()
{
    Fixed n1(2.5), n2(2);
    Fixed expected(5);

    Fixed result = n1 * n2;

    ASSERT_EQ(expected.getRawBits(), result.getRawBits());
}

void test_should_divide_two_fixed_values()
{
    Fixed n1(5), n2(2);
    Fixed expected(2.5);

    Fixed result = n1 / n2;

    ASSERT_EQ(expected.getRawBits(), result.getRawBits());
}

void test_should_increment_fixed_value_by_epsilon()
{
    Fixed n1(1);
    Fixed n2(1);
    Fixed expected(1 + 0.00390625);

    n1++;
    ++n2;

    ASSERT_EQ(expected.getRawBits(), n1.getRawBits());
    ASSERT_EQ(expected.getRawBits(), n2.getRawBits());
}

void test_should_decrement_fixed_value_by_epsilon()
{
    Fixed n1(1), n2(1);
    Fixed expected(1 - 0.00390625);

    n1--;
    --n2;

    ASSERT_EQ(expected.getRawBits(), n1.getRawBits());
    ASSERT_EQ(expected.getRawBits(), n2.getRawBits());
}

void test_should_get_min_value_between_two_fixed_values()
{
    Fixed n1(1), n2(2), expected(1);

    Fixed &result_1 = Fixed::min(n1, n2);
    const Fixed &result_2 = Fixed::min(Fixed(1), Fixed(2));

    ASSERT_EQ(expected.getRawBits(), result_1.getRawBits());
    ASSERT_EQ(expected.getRawBits(), result_2.getRawBits());
}

void test_should_get_max_value_between_two_fixed_values()
{
    Fixed n1(1), n2(2), expected(2);

    Fixed &result_1 = Fixed::max(n1, n2);
    const Fixed &result_2 = Fixed::max(Fixed(1), Fixed(2));

    ASSERT_EQ(expected.getRawBits(), result_1.getRawBits());
    ASSERT_EQ(expected.getRawBits(), result_2.getRawBits());
}

void test_should_transform_negative_values_into_postive_using_abs_function()
{
    Fixed n1(-1), n2(-2.5), expected_1(1), expected_2(2.5);

    Fixed result_1 = n1.abs();
    Fixed result_2 = n2.abs();

    ASSERT_EQ(expected_1.getRawBits(), result_1.getRawBits());
    ASSERT_EQ(expected_2.getRawBits(), result_2.getRawBits());
}

void test_should_keep_positive_values_as_positive_using_abs_function()
{
    Fixed n1(1), n2(2.5), expected_1(1), expected_2(2.5);

    Fixed result_1 = n1.abs();
    Fixed result_2 = n2.abs();

    ASSERT_EQ(result_1.getRawBits(), expected_1.getRawBits());
    ASSERT_EQ(result_2.getRawBits(), expected_2.getRawBits());
}

void RUN_EXAMPLE_SUITE()
{
    test_should_create_a_fix_point();
    test_should_change_raw_bits();
    test_should_copy_using_copy_constructor();
    test_should_copy_using_assignment_operator();
    test_should_create_fixed_object_passing_integer_to_constructor();
    test_should_create_fixed_object_passing_double_to_constructor();
    test_should_convert_fixed_value_to_int();
    test_should_convert_fixed_value_to_double();
    test_should_compare_decimals_fixed_values_as_greater_than();
    test_should_compare_decimals_fixed_values_as_less_than();
    test_should_compare_integer_fixed_values_as_greater_than();
    test_should_compare_decimals_fixed_values_as_equal();
    test_should_compare_integer_fixed_values_as_equal();
    test_should_compare_decimals_fixed_values_as_greater_equal();
    test_should_compare_integer_fixed_values_as_greater_equal();
    test_should_compare_decimals_values_as_less_equal();
    test_should_compare_integer_fixed_values_as_less_equal();
    test_should_compare_decimal_fixed_values_as_not_equal();
    test_should_compare_integer_fixed_values_as_not_equal();
    test_should_add_two_fixed_points();
    test_should_subtract_two_fixed_values();
    test_should_multiply_two_fixed_values();
    test_should_divide_two_fixed_values();
    test_should_increment_fixed_value_by_epsilon();
    test_should_decrement_fixed_value_by_epsilon();
    test_should_get_min_value_between_two_fixed_values();
    test_should_get_max_value_between_two_fixed_values();
    test_should_transform_negative_values_into_postive_using_abs_function();
}
