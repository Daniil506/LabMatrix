#ifndef TMATHVECTOR_H
#define TMATHVECTOR_H

#include "TVector.h"

template <typename T>
class TMathVector : public TVector<T>
{
public:
    using TVector<T>::TVector;

    TMathVector<T> operator+(const TMathVector<T>& other) const
    {
        TMathVector<T> result(this->size());

        for (size_t i = 0; i < this->size(); i++)
        {
            result[i] = (*this)[i] + other[i];
        }

        return result;
    }

    TMathVector<T> operator-(const TMathVector<T>& other) const
    {
        TMathVector<T> result(this->size());

        for (size_t i = 0; i < this->size(); i++)
        {
            result[i] = (*this)[i] - other[i];
        }

        return result;
    }

    TMathVector<T> operator*(const T& value) const
    {
        TMathVector<T> result(this->size());

        for (size_t i = 0; i < this->size(); i++)
        {
            result[i] = (*this)[i] * value;
        }

        return result;
    }

    T operator*(const TMathVector<T>& other) const
    {
        T result = T();

        for (size_t i = 0; i < this->size(); i++)
        {
            result += (*this)[i] * other[i];
        }

        return result;
    }

    bool operator==(const TMathVector<T>& other) const
    {
        if (this->size() != other.size())
            return false;

        for (size_t i = 0; i < this->size(); i++)
        {
            if ((*this)[i] != other[i])
                return false;
        }

        return true;
    }

    bool operator!=(const TMathVector<T>& other) const
    {
        return !(*this == other);
    }
};

#endif