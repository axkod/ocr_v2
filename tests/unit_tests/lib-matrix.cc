#include "misc/matrix/lib-matrix.hh"

#include "gtest/gtest.h"
#include "misc/matrix/matrix.hh"

namespace tests::unit_tests
{
    misc::matrix::Matrix create_simple_matrix()
    {
        misc::matrix::Matrix matrix(3, 2);

        matrix.at(0, 0) = 0;
        matrix.at(0, 1) = 1;
        matrix.at(1, 0) = 2;
        matrix.at(1, 1) = 3;
        matrix.at(2, 0) = 4;
        matrix.at(2, 1) = 5;

        return matrix;
    }

    misc::matrix::Matrix create_simple_row_matrix()
    {
        misc::matrix::Matrix matrix(1, 2);

        matrix.at(0, 0) = 1;
        matrix.at(0, 1) = 2;

        return matrix;
    }

    TEST(LibMatrix, transpose)
    {
        const auto& matrix = create_simple_matrix();
        const auto& matrix_result = matrix.transpose();

        ASSERT_EQ(0, matrix_result.at(0, 0));
        ASSERT_EQ(1, matrix_result.at(1, 0));
        ASSERT_EQ(2, matrix_result.at(0, 1));
        ASSERT_EQ(3, matrix_result.at(1, 1));
        ASSERT_EQ(4, matrix_result.at(0, 2));
        ASSERT_EQ(5, matrix_result.at(1, 2));
    }

    TEST(LibMatrix, addition_in_place)
    {
        auto matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_matrix();

        matrix_1 += matrix_2;

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(2, matrix_1.at(0, 1));
        ASSERT_EQ(4, matrix_1.at(1, 0));
        ASSERT_EQ(6, matrix_1.at(1, 1));
        ASSERT_EQ(8, matrix_1.at(2, 0));
        ASSERT_EQ(10, matrix_1.at(2, 1));

        ASSERT_EQ(0, matrix_2.at(0, 0));
        ASSERT_EQ(1, matrix_2.at(0, 1));
        ASSERT_EQ(2, matrix_2.at(1, 0));
        ASSERT_EQ(3, matrix_2.at(1, 1));
        ASSERT_EQ(4, matrix_2.at(2, 0));
        ASSERT_EQ(5, matrix_2.at(2, 1));
    }

    TEST(LibMatrix, addition_with_vector_in_place)
    {
        auto matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_row_matrix();

        matrix_1 += matrix_2;

        ASSERT_EQ(1, matrix_1.at(0, 0));
        ASSERT_EQ(3, matrix_1.at(0, 1));
        ASSERT_EQ(3, matrix_1.at(1, 0));
        ASSERT_EQ(5, matrix_1.at(1, 1));
        ASSERT_EQ(5, matrix_1.at(2, 0));
        ASSERT_EQ(7, matrix_1.at(2, 1));

        ASSERT_EQ(1, matrix_2.at(0, 0));
        ASSERT_EQ(2, matrix_2.at(0, 1));
    }

    TEST(LibMatrix, addition)
    {
        const auto& matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_matrix();

        const auto& matrix_result = matrix_1 + matrix_2;

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(2, matrix_result.get_width());

        ASSERT_EQ(0, matrix_result.at(0, 0));
        ASSERT_EQ(2, matrix_result.at(0, 1));
        ASSERT_EQ(4, matrix_result.at(1, 0));
        ASSERT_EQ(6, matrix_result.at(1, 1));
        ASSERT_EQ(8, matrix_result.at(2, 0));
        ASSERT_EQ(10, matrix_result.at(2, 1));

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(1, matrix_1.at(0, 1));
        ASSERT_EQ(2, matrix_1.at(1, 0));
        ASSERT_EQ(3, matrix_1.at(1, 1));
        ASSERT_EQ(4, matrix_1.at(2, 0));
        ASSERT_EQ(5, matrix_1.at(2, 1));

        ASSERT_EQ(0, matrix_2.at(0, 0));
        ASSERT_EQ(1, matrix_2.at(0, 1));
        ASSERT_EQ(2, matrix_2.at(1, 0));
        ASSERT_EQ(3, matrix_2.at(1, 1));
        ASSERT_EQ(4, matrix_2.at(2, 0));
        ASSERT_EQ(5, matrix_2.at(2, 1));
    }

    TEST(LibMatrix, addition_with_vector)
    {
        const auto& matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_row_matrix();

        const auto& matrix_result = matrix_1 + matrix_2;

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(2, matrix_result.get_width());

        ASSERT_EQ(1, matrix_result.at(0, 0));
        ASSERT_EQ(3, matrix_result.at(0, 1));
        ASSERT_EQ(3, matrix_result.at(1, 0));
        ASSERT_EQ(5, matrix_result.at(1, 1));
        ASSERT_EQ(5, matrix_result.at(2, 0));
        ASSERT_EQ(7, matrix_result.at(2, 1));

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(1, matrix_1.at(0, 1));
        ASSERT_EQ(2, matrix_1.at(1, 0));
        ASSERT_EQ(3, matrix_1.at(1, 1));
        ASSERT_EQ(4, matrix_1.at(2, 0));
        ASSERT_EQ(5, matrix_1.at(2, 1));

        ASSERT_EQ(1, matrix_2.at(0, 0));
        ASSERT_EQ(2, matrix_2.at(0, 1));
    }

    TEST(LibMatrix, subtraction_in_place)
    {
        auto matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_matrix();

        matrix_1 -= matrix_2;

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(0, matrix_1.at(0, 1));
        ASSERT_EQ(0, matrix_1.at(1, 0));
        ASSERT_EQ(0, matrix_1.at(1, 1));
        ASSERT_EQ(0, matrix_1.at(2, 0));
        ASSERT_EQ(0, matrix_1.at(2, 1));

        ASSERT_EQ(0, matrix_2.at(0, 0));
        ASSERT_EQ(1, matrix_2.at(0, 1));
        ASSERT_EQ(2, matrix_2.at(1, 0));
        ASSERT_EQ(3, matrix_2.at(1, 1));
        ASSERT_EQ(4, matrix_2.at(2, 0));
        ASSERT_EQ(5, matrix_2.at(2, 1));
    }

    TEST(LibMatrix, subtraction_with_vector_in_place)
    {
        auto matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_row_matrix();

        matrix_1 -= matrix_2;

        ASSERT_EQ(-1, matrix_1.at(0, 0));
        ASSERT_EQ(-1, matrix_1.at(0, 1));
        ASSERT_EQ(1, matrix_1.at(1, 0));
        ASSERT_EQ(1, matrix_1.at(1, 1));
        ASSERT_EQ(3, matrix_1.at(2, 0));
        ASSERT_EQ(3, matrix_1.at(2, 1));

        ASSERT_EQ(1, matrix_2.at(0, 0));
        ASSERT_EQ(2, matrix_2.at(0, 1));
    }

    TEST(LibMatrix, subtraction)
    {
        const auto& matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_matrix();

        const auto& matrix_result = matrix_1 - matrix_2;

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(2, matrix_result.get_width());

        ASSERT_EQ(0, matrix_result.at(0, 0));
        ASSERT_EQ(0, matrix_result.at(0, 1));
        ASSERT_EQ(0, matrix_result.at(1, 0));
        ASSERT_EQ(0, matrix_result.at(1, 1));
        ASSERT_EQ(0, matrix_result.at(2, 0));
        ASSERT_EQ(0, matrix_result.at(2, 1));

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(1, matrix_1.at(0, 1));
        ASSERT_EQ(2, matrix_1.at(1, 0));
        ASSERT_EQ(3, matrix_1.at(1, 1));
        ASSERT_EQ(4, matrix_1.at(2, 0));
        ASSERT_EQ(5, matrix_1.at(2, 1));

        ASSERT_EQ(0, matrix_2.at(0, 0));
        ASSERT_EQ(1, matrix_2.at(0, 1));
        ASSERT_EQ(2, matrix_2.at(1, 0));
        ASSERT_EQ(3, matrix_2.at(1, 1));
        ASSERT_EQ(4, matrix_2.at(2, 0));
        ASSERT_EQ(5, matrix_2.at(2, 1));
    }

    TEST(LibMatrix, subtraction_with_vector)
    {
        const auto& matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_row_matrix();

        const auto& matrix_result = matrix_1 - matrix_2;

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(2, matrix_result.get_width());

        ASSERT_EQ(-1, matrix_result.at(0, 0));
        ASSERT_EQ(-1, matrix_result.at(0, 1));
        ASSERT_EQ(1, matrix_result.at(1, 0));
        ASSERT_EQ(1, matrix_result.at(1, 1));
        ASSERT_EQ(3, matrix_result.at(2, 0));
        ASSERT_EQ(3, matrix_result.at(2, 1));

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(1, matrix_1.at(0, 1));
        ASSERT_EQ(2, matrix_1.at(1, 0));
        ASSERT_EQ(3, matrix_1.at(1, 1));
        ASSERT_EQ(4, matrix_1.at(2, 0));
        ASSERT_EQ(5, matrix_1.at(2, 1));

        ASSERT_EQ(1, matrix_2.at(0, 0));
        ASSERT_EQ(2, matrix_2.at(0, 1));
    }

    TEST(LibMatrix, scalar_multiplication_in_place)
    {
        auto matrix = create_simple_matrix();

        matrix *= 2;

        ASSERT_EQ(0, matrix.at(0, 0));
        ASSERT_EQ(2, matrix.at(0, 1));
        ASSERT_EQ(4, matrix.at(1, 0));
        ASSERT_EQ(6, matrix.at(1, 1));
        ASSERT_EQ(8, matrix.at(2, 0));
        ASSERT_EQ(10, matrix.at(2, 1));
    }

    TEST(LibMatrix, scalar_multiplication)
    {
        const auto& matrix = create_simple_matrix();

        const auto& matrix_result = matrix * 2;

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(2, matrix_result.get_width());

        ASSERT_EQ(0, matrix_result.at(0, 0));
        ASSERT_EQ(2, matrix_result.at(0, 1));
        ASSERT_EQ(4, matrix_result.at(1, 0));
        ASSERT_EQ(6, matrix_result.at(1, 1));
        ASSERT_EQ(8, matrix_result.at(2, 0));
        ASSERT_EQ(10, matrix_result.at(2, 1));

        ASSERT_EQ(0, matrix.at(0, 0));
        ASSERT_EQ(1, matrix.at(0, 1));
        ASSERT_EQ(2, matrix.at(1, 0));
        ASSERT_EQ(3, matrix.at(1, 1));
        ASSERT_EQ(4, matrix.at(2, 0));
        ASSERT_EQ(5, matrix.at(2, 1));
    }

    TEST(LibMatrix, scalar_division_in_place)
    {
        auto matrix = create_simple_matrix();

        matrix /= 2;

        ASSERT_EQ(0, matrix.at(0, 0));
        ASSERT_EQ(0.5, matrix.at(0, 1));
        ASSERT_EQ(1, matrix.at(1, 0));
        ASSERT_EQ(1.5, matrix.at(1, 1));
        ASSERT_EQ(2, matrix.at(2, 0));
        ASSERT_EQ(2.5, matrix.at(2, 1));
    }

    TEST(LibMatrix, scalar_division)
    {
        const auto& matrix = create_simple_matrix();

        const auto& matrix_result = matrix / 2;

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(2, matrix_result.get_width());

        ASSERT_EQ(0, matrix_result.at(0, 0));
        ASSERT_EQ(0.5, matrix_result.at(0, 1));
        ASSERT_EQ(1, matrix_result.at(1, 0));
        ASSERT_EQ(1.5, matrix_result.at(1, 1));
        ASSERT_EQ(2, matrix_result.at(2, 0));
        ASSERT_EQ(2.5, matrix_result.at(2, 1));

        ASSERT_EQ(0, matrix.at(0, 0));
        ASSERT_EQ(1, matrix.at(0, 1));
        ASSERT_EQ(2, matrix.at(1, 0));
        ASSERT_EQ(3, matrix.at(1, 1));
        ASSERT_EQ(4, matrix.at(2, 0));
        ASSERT_EQ(5, matrix.at(2, 1));
    }

    TEST(LibMatrix, multiplication)
    {
        const auto& matrix_1 = create_simple_matrix();
        const auto& matrix_2 = matrix_1.transpose();

        const auto& matrix_result = matrix_1 * matrix_2;

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(3, matrix_result.get_width());

        ASSERT_EQ(1, matrix_result.at(0, 0));
        ASSERT_EQ(3, matrix_result.at(0, 1));
        ASSERT_EQ(5, matrix_result.at(0, 2));
        ASSERT_EQ(3, matrix_result.at(1, 0));
        ASSERT_EQ(13, matrix_result.at(1, 1));
        ASSERT_EQ(23, matrix_result.at(1, 2));
        ASSERT_EQ(5, matrix_result.at(2, 0));
        ASSERT_EQ(23, matrix_result.at(2, 1));
        ASSERT_EQ(41, matrix_result.at(2, 2));

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(1, matrix_1.at(0, 1));
        ASSERT_EQ(2, matrix_1.at(1, 0));
        ASSERT_EQ(3, matrix_1.at(1, 1));
        ASSERT_EQ(4, matrix_1.at(2, 0));
        ASSERT_EQ(5, matrix_1.at(2, 1));

        ASSERT_EQ(0, matrix_2.at(0, 0));
        ASSERT_EQ(1, matrix_2.at(1, 0));
        ASSERT_EQ(2, matrix_2.at(0, 1));
        ASSERT_EQ(3, matrix_2.at(1, 1));
        ASSERT_EQ(4, matrix_2.at(0, 2));
        ASSERT_EQ(5, matrix_2.at(1, 2));
    }

    TEST(LibMatrix, hadamard_product_in_place)
    {
        auto matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_matrix();

        matrix_1.hadamard_product(matrix_2);

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(1, matrix_1.at(0, 1));
        ASSERT_EQ(4, matrix_1.at(1, 0));
        ASSERT_EQ(9, matrix_1.at(1, 1));
        ASSERT_EQ(16, matrix_1.at(2, 0));
        ASSERT_EQ(25, matrix_1.at(2, 1));

        ASSERT_EQ(0, matrix_2.at(0, 0));
        ASSERT_EQ(1, matrix_2.at(0, 1));
        ASSERT_EQ(2, matrix_2.at(1, 0));
        ASSERT_EQ(3, matrix_2.at(1, 1));
        ASSERT_EQ(4, matrix_2.at(2, 0));
        ASSERT_EQ(5, matrix_2.at(2, 1));
    }

    TEST(LibMatrix, hadamard_product)
    {
        const auto& matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_matrix();

        const auto& matrix_result = misc::matrix::hadamard_product(matrix_1, matrix_2);

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(2, matrix_result.get_width());

        ASSERT_EQ(0, matrix_result.at(0, 0));
        ASSERT_EQ(1, matrix_result.at(0, 1));
        ASSERT_EQ(4, matrix_result.at(1, 0));
        ASSERT_EQ(9, matrix_result.at(1, 1));
        ASSERT_EQ(16, matrix_result.at(2, 0));
        ASSERT_EQ(25, matrix_result.at(2, 1));

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(1, matrix_1.at(0, 1));
        ASSERT_EQ(2, matrix_1.at(1, 0));
        ASSERT_EQ(3, matrix_1.at(1, 1));
        ASSERT_EQ(4, matrix_1.at(2, 0));
        ASSERT_EQ(5, matrix_1.at(2, 1));

        ASSERT_EQ(0, matrix_2.at(0, 0));
        ASSERT_EQ(1, matrix_2.at(0, 1));
        ASSERT_EQ(2, matrix_2.at(1, 0));
        ASSERT_EQ(3, matrix_2.at(1, 1));
        ASSERT_EQ(4, matrix_2.at(2, 0));
        ASSERT_EQ(5, matrix_2.at(2, 1));
    }

    TEST(LibMatrix, kronecker_product)
    {
        misc::matrix::Matrix matrix_1(1, 4);
        matrix_1.at(0, 0) = 1;
        matrix_1.at(0, 1) = 2;
        matrix_1.at(0, 2) = 3;
        matrix_1.at(0, 3) = 4;

        misc::matrix::Matrix matrix_2(3, 1);
        matrix_2.at(0, 0) = 1;
        matrix_2.at(1, 0) = 2;
        matrix_2.at(2, 0) = 3;

        const auto& matrix_result = misc::matrix::kronecker_product(matrix_1, matrix_2);

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(4, matrix_result.get_width());

        ASSERT_EQ(1, matrix_result.at(0, 0));
        ASSERT_EQ(2, matrix_result.at(0, 1));
        ASSERT_EQ(3, matrix_result.at(0, 2));
        ASSERT_EQ(4, matrix_result.at(0, 3));
        ASSERT_EQ(2, matrix_result.at(1, 0));
        ASSERT_EQ(4, matrix_result.at(1, 1));
        ASSERT_EQ(6, matrix_result.at(1, 2));
        ASSERT_EQ(8, matrix_result.at(1, 3));
        ASSERT_EQ(3, matrix_result.at(2, 0));
        ASSERT_EQ(6, matrix_result.at(2, 1));
        ASSERT_EQ(9, matrix_result.at(2, 2));
        ASSERT_EQ(12, matrix_result.at(2, 3));

        ASSERT_EQ(1, matrix_1.at(0, 0));
        ASSERT_EQ(2, matrix_1.at(0, 1));
        ASSERT_EQ(3, matrix_1.at(0, 2));
        ASSERT_EQ(4, matrix_1.at(0, 3));

        ASSERT_EQ(1, matrix_2.at(0, 0));
        ASSERT_EQ(2, matrix_2.at(1, 0));
        ASSERT_EQ(3, matrix_2.at(2, 0));
    }

    TEST(LibMatrix, horizontal_concatenation)
    {
        const auto& matrix_1 = create_simple_matrix();
        const auto& matrix_2 = create_simple_matrix();

        const auto& matrix_result = misc::matrix::horizontal_concatenate(matrix_1, matrix_2);

        ASSERT_EQ(3, matrix_result.get_height());
        ASSERT_EQ(4, matrix_result.get_width());

        ASSERT_EQ(0, matrix_result.at(0, 0));
        ASSERT_EQ(1, matrix_result.at(0, 1));
        ASSERT_EQ(0, matrix_result.at(0, 2));
        ASSERT_EQ(1, matrix_result.at(0, 3));
        ASSERT_EQ(2, matrix_result.at(1, 0));
        ASSERT_EQ(3, matrix_result.at(1, 1));
        ASSERT_EQ(2, matrix_result.at(1, 2));
        ASSERT_EQ(3, matrix_result.at(1, 3));
        ASSERT_EQ(4, matrix_result.at(2, 0));
        ASSERT_EQ(5, matrix_result.at(2, 1));
        ASSERT_EQ(4, matrix_result.at(2, 2));
        ASSERT_EQ(5, matrix_result.at(2, 3));

        ASSERT_EQ(0, matrix_1.at(0, 0));
        ASSERT_EQ(1, matrix_1.at(0, 1));
        ASSERT_EQ(2, matrix_1.at(1, 0));
        ASSERT_EQ(3, matrix_1.at(1, 1));
        ASSERT_EQ(4, matrix_1.at(2, 0));
        ASSERT_EQ(5, matrix_1.at(2, 1));

        ASSERT_EQ(0, matrix_2.at(0, 0));
        ASSERT_EQ(1, matrix_2.at(0, 1));
        ASSERT_EQ(2, matrix_2.at(1, 0));
        ASSERT_EQ(3, matrix_2.at(1, 1));
        ASSERT_EQ(4, matrix_2.at(2, 0));
        ASSERT_EQ(5, matrix_2.at(2, 1));
    }

    TEST(LibMatrix, apply_in_place)
    {
        auto matrix = create_simple_matrix();
        matrix.apply([](misc::matrix::Matrix::data_t element) { return element * 2; });

        ASSERT_EQ(0, matrix.at(0, 0));
        ASSERT_EQ(2, matrix.at(0, 1));
        ASSERT_EQ(4, matrix.at(1, 0));
        ASSERT_EQ(6, matrix.at(1, 1));
        ASSERT_EQ(8, matrix.at(2, 0));
        ASSERT_EQ(10, matrix.at(2, 1));
    }

    TEST(LibMatrix, apply)
    {
        auto matrix = create_simple_matrix();
        auto matrix_result =
            misc::matrix::apply(matrix, [](misc::matrix::Matrix::data_t element) { return element * 2; });

        ASSERT_EQ(0, matrix_result.at(0, 0));
        ASSERT_EQ(2, matrix_result.at(0, 1));
        ASSERT_EQ(4, matrix_result.at(1, 0));
        ASSERT_EQ(6, matrix_result.at(1, 1));
        ASSERT_EQ(8, matrix_result.at(2, 0));
        ASSERT_EQ(10, matrix_result.at(2, 1));

        ASSERT_EQ(0, matrix.at(0, 0));
        ASSERT_EQ(1, matrix.at(0, 1));
        ASSERT_EQ(2, matrix.at(1, 0));
        ASSERT_EQ(3, matrix.at(1, 1));
        ASSERT_EQ(4, matrix.at(2, 0));
        ASSERT_EQ(5, matrix.at(2, 1));
    }

    TEST(LibMatrix, sum)
    {
        auto matrix = create_simple_matrix();
        auto sum = matrix.sum();

        ASSERT_EQ(15, sum);
    }

    TEST(LibMatrix, columns_sum)
    {
        auto matrix = create_simple_matrix();
        auto matrix_result = matrix.columns_sum();

        ASSERT_EQ(6, matrix_result.at(0, 0));
        ASSERT_EQ(9, matrix_result.at(0, 1));
    }

    TEST(LibMatrix, rows_sum)
    {
        auto matrix = create_simple_matrix();
        auto matrix_result = matrix.rows_sum();

        ASSERT_EQ(1, matrix_result.at(0, 0));
        ASSERT_EQ(5, matrix_result.at(1, 0));
        ASSERT_EQ(9, matrix_result.at(2, 0));
    }
} // namespace tests::unit_tests