#ifndef TVECTOR_H
#define TVECTOR_H

#include <cstddef>

template <typename T>
class TVector
{
private:
    T* _data;
    size_t _size;
    size_t _capacity;

public:
    TVector(size_t size = 0)
    {
        _size = size;
        _capacity = size;

        if (size > 0)
            _data = new T[size];
        else
            _data = nullptr;
    }

    ~TVector()
    {
        delete[] _data;
    }

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    T& operator[](size_t index)
    {
        return _data[index];
    }

    const T& operator[](size_t index) const
    {
        return _data[index];
    }

    void reserve(size_t new_capacity)
    {
        if (new_capacity <= _capacity)
            return;

        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < _size; i++)
        {
            new_data[i] = _data[i];
        }

        delete[] _data;

        _data = new_data;
        _capacity = new_capacity;
    }

    void shrink_to_fit()
    {
        if (_size == _capacity)
            return;

        T* new_data = nullptr;

        if (_size > 0)
        {
            new_data = new T[_size];

            for (size_t i = 0; i < _size; i++)
            {
                new_data[i] = _data[i];
            }
        }

        delete[] _data;

        _data = new_data;
        _capacity = _size;
    }

    template <typename Type>
    class Iterator
    {
    private:
        Type* _ptr;

    public:
        Iterator()
        {
            _ptr = nullptr;
        }

        Iterator(Type* ptr)
        {
            _ptr = ptr;
        }

        Iterator(const Iterator& other)
        {
            _ptr = other._ptr;
        }

        Iterator& operator=(const Iterator& other)
        {
            _ptr = other._ptr;
            return *this;
        }

        bool operator==(const Iterator& other) const
        {
            return _ptr == other._ptr;
        }

        bool operator!=(const Iterator& other) const
        {
            return _ptr != other._ptr;
        }

        Iterator& operator++()
        {
            ++_ptr;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp(*this);
            ++_ptr;
            return temp;
        }

        Iterator& operator--()
        {
            --_ptr;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp(*this);
            --_ptr;
            return temp;
        }

        Iterator operator+(int value) const
        {
            return Iterator(_ptr + value);
        }

        Iterator operator-(int value) const
        {
            return Iterator(_ptr - value);
        }

        Iterator& operator+=(int value)
        {
            _ptr += value;
            return *this;
        }

        Iterator& operator-=(int value)
        {
            _ptr -= value;
            return *this;
        }

        Type& operator*()
        {
            return *_ptr;
        }

        const Type& operator*() const
        {
            return *_ptr;
        }
    };

    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;

    iterator begin()
    {
        return iterator(_data);
    }

    iterator end()
    {
        return iterator(_data + _size);
    }

    const_iterator begin() const
    {
        return const_iterator(_data);
    }

    const_iterator end() const
    {
        return const_iterator(_data + _size);
    }
};

#endif