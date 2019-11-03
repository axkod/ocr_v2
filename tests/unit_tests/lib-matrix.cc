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

    TEST(LibMatrix, transpose)
    {
        auto matrix = create_simple_matrix();
        auto transposed_matrix = matrix.transpose();

        ASSERT_EQ(0, transposed_matrix.at(0, 0));
        ASSERT_EQ(1, transposed_matrix.at(1, 0));
        ASSERT_EQ(2, transposed_matrix.at(0, 1));
        ASSERT_EQ(3, transposed_matrix.at(1, 1));
        ASSERT_EQ(4, transposed_matrix.at(0, 2));
        ASSERT_EQ(5, transposed_matrix.at(1, 2));

        ASSERT_EQ(0, matrix.at(0, 0));
        ASSERT_EQ(1, matrix.at(0, 1));
        ASSERT_EQ(2, matrix.at(1, 0));
        ASSERT_EQ(3, matrix.at(1, 1));
        ASSERT_EQ(4, matrix.at(2, 0));
        ASSERT_EQ(5, matrix.at(2, 1));
    }

    TEST(LibMatrix, addition_in_place)
    {
        auto matrix_1 = create_simple_matrix();
        auto matrix_2 = create_simple_matrix();

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

    TEST(LibMatrix, addition)
    {
        auto matrix_1 = create_simple_matrix();
        auto matrix_2 = create_simple_matrix();

        auto matrix_result = matrix_1 + matrix_2;

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
}