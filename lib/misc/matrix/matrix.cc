#include "matrix.hh"

namespace misc::matrix
{
    Matrix::Matrix(size_t height, size_t width)
        : Matrix(height, width, 0)
    {}

    Matrix::Matrix(size_t height, size_t width, data_t value)
        : height_(height)
        , width_(width)
        , data_(width * height, value)
    {}

    Matrix::data_t& Matrix::at(size_t height_index, size_t width_index)
    {
#ifndef RELEASE
        if (height_index >= this->height_)
            throw std::out_of_range("height_index out of range");
        if (width_index >= this->width_)
            throw std::out_of_range("width_index out of range");
#endif

        return data_[height_index * this->width_ + width_index];
    }

    Matrix::data_t Matrix::at(size_t height_index, size_t width_index) const
    {
#ifndef RELEASE
        if (height_index >= this->height_)
            throw std::out_of_range("height_index out of range");
        if (width_index >= this->width_)
            throw std::out_of_range("width_index out of range");
#endif

        return data_[height_index * this->width_ + width_index];
    }

    Matrix Matrix::transpose() const
    {
        Matrix newMatrix(this->width_, this->height_);

        for (size_t i = 0; i < this->height_; i++)
        {
            for (size_t j = 0; j < this->width_; j++)
                newMatrix.at(j, i) = this->at(i, j);
        }

        return newMatrix;
    }

    Matrix& Matrix::operator+=(const Matrix& rhs)
    {
#ifndef RELEASE
        if (this->height_ != rhs.height_ || this->width_ != rhs.width_)
            throw std::invalid_argument("the matrix must be of the same size");
#endif

        for (size_t i = 0; i < this->height_ * this->width_; i++)
            this->data_[i] += rhs.data_[i];

        return *this;
    }

    Matrix operator+(Matrix lhs, const Matrix& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    Matrix& Matrix::operator-=(const Matrix& rhs)
    {
#ifndef RELEASE
        if (this->height_ != rhs.height_ || this->width_ != rhs.width_)
            throw std::invalid_argument("the matrix must be of the same size");
#endif

        for (size_t i = 0; i < this->height_ * this->width_; i++)
            this->data_[i] -= rhs.data_[i];

        return *this;
    }

    Matrix operator-(Matrix lhs, const Matrix& rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    Matrix& Matrix::operator*=(const Matrix::data_t& scalar)
    {
        for (size_t i = 0; i < this->height_ * this->width_; i++)
            this->data_[i] *= scalar;

        return *this;
    }

    Matrix operator*(Matrix matrix, const Matrix::data_t& scalar)
    {
        matrix *= scalar;
        return matrix;
    }

    Matrix& Matrix::operator/=(const Matrix::data_t& scalar)
    {
        for (size_t i = 0; i < this->height_ * this->width_; i++)
            this->data_[i] /= scalar;

        return *this;
    }

    Matrix operator/(Matrix matrix, const Matrix::data_t& scalar)
    {
        matrix /= scalar;
        return matrix;
    }

    Matrix operator*(Matrix lhs, const Matrix& rhs)
    {
#ifndef RELEASE
        if (lhs.width_ != rhs.height_)
        {
            throw std::invalid_argument("matrix multiplication can not be "
                                        "performed on those two matrix");
        }
#endif

        Matrix newMatrix(lhs.height_, rhs.width_, 0);

        for (size_t i = 0; i < lhs.height_; i++)
        {
            for (size_t j = 0; j < rhs.width_; j++)
            {
                for (size_t k = 0; k < lhs.width_; k++)
                    newMatrix.at(i, j) += lhs.at(i, k) * rhs.at(k, j);
            }
        }

        return newMatrix;
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (size_t i = 0; i < matrix.height_; i++)
        {
            os << "| ";

            for (size_t j = 0; j < matrix.width_; j++)
                os << matrix.at(i, j) << " ";

            os << "|" << std::endl;
        }

        return os;
    }
} // namespace misc::matrix