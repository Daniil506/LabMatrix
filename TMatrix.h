#ifndef TMATRIX_H
#define TMATRIX_H

#include "TMathVector.h"

template <typename T>
class TMatrix : public TMathVector<TMathVector<T>>
{
private:
    size_t _rows;
    size_t _columns;

public:
    TMatrix(size_t rows = 0, size_t columns = 0)
        : TMathVector<TMathVector<T>>(rows)
    {
        _rows = rows;
        _columns = columns;

        for (size_t i = 0; i < _rows; i++)
        {
            (*this)[i] = TMathVector<T>(columns);
        }
    }

    size_t rows() const
    {
        return _rows;
    }

    size_t columns() const
    {
        return _columns;
    }
};

#endif