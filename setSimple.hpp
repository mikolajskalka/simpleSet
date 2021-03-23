#pragma once

#include <climits>
#include <iostream>

template <std::size_t N>
class setSimple
{
public:
    static constexpr const unsigned int IntBits = CHAR_BIT * sizeof(int);
    unsigned int simpleSet[(N + IntBits - 1) / IntBits];

public:
    setSimple() : simpleSet(){};
    setSimple(const setSimple& other);
    setSimple(setSimple&& other);
    ~setSimple() = default;

    setSimple operator+(const setSimple &other);
    setSimple operator*(const setSimple &other);
    setSimple operator-(const setSimple &other);
    setSimple &operator=(const setSimple &other);
    setSimple &operator=(setSimple &&other);
    bool operator==(const setSimple &other);
    bool operator!=(const setSimple &other);

    setSimple sum(const setSimple &other);

    void insert(const std::size_t elem);
    void remove(const std::size_t elem);
    bool contains(const std::size_t elem);

    template <std::size_t T>
    friend std::ostream &operator<<(std::ostream &ostream, const setSimple<T> &set);
};

template <std::size_t N>
setSimple<N>::setSimple(const setSimple &other)
{
    for(size_t i = 0; i < (N + IntBits - 1) / IntBits; i++ )
    {
        simpleSet[i / IntBits] = other.simpleSet[i / IntBits];
    }
}

template <std::size_t N>
setSimple<N>::setSimple(setSimple &&other)
{
    for(size_t i = 0; i < (N + IntBits - 1) / IntBits; i++ )
    {
    simpleSet[i / IntBits] = other.simpleSet[i / IntBits];
    }
}

template <std::size_t N>
setSimple<N> &setSimple<N>::operator=(const setSimple &other)
{
    for(size_t i = 0; i < (N + IntBits - 1) / IntBits; i++ )
    {
        simpleSet[i / IntBits] = other.simpleSet[i / IntBits];
    }
    return *this;
}

template <std::size_t N>
setSimple<N> &setSimple<N>::operator=(setSimple &&other)
{
    for(size_t i = 0; i < (N + IntBits - 1) / IntBits; i++ )
    {
        simpleSet[i / IntBits] = other.simpleSet[i / IntBits];
    }
    return *this;
}


template <std::size_t N>
setSimple<N> setSimple<N>::operator-(const setSimple &other)
{
    setSimple<N> output;
    for(size_t i = 0; i < N; i++)
    {
        output.simpleSet[i / IntBits] |= (((simpleSet[i / IntBits])) & (~(other.simpleSet[i / IntBits])));
    }
    return output;
}

template <std::size_t N>
setSimple<N> setSimple<N>::operator+(const setSimple &other)
{
    setSimple<N> output;
    for (size_t i = 0; i < N; i++)
    {
        output.simpleSet[i / IntBits] |= (((simpleSet[i / IntBits])) | ((other.simpleSet[i / IntBits])));
    }
    return output;
}

template <std::size_t N>
setSimple<N> setSimple<N>::operator*(const setSimple &other)
{
    setSimple<N> output;
    for (size_t i = 0; i < N; i++)
    {
        output.simpleSet[i / IntBits] |= (((simpleSet[i / IntBits])) & ((other.simpleSet[i / IntBits])));
    }
    return output;
}


template <std::size_t N>
setSimple<N> setSimple<N>::sum(const setSimple &other)
{
    setSimple<N> output;
    for (size_t i = 0; i < N; i++)
    {
        output.simpleSet[i / IntBits] |= (((simpleSet[i / IntBits])) | ((other.simpleSet[i / IntBits])));
    }
    return output;
}

template <std::size_t N>
void setSimple<N>::remove(const std::size_t elem)
{
    simpleSet[elem / IntBits] &= ~(1U << (elem % IntBits));
}

template <std::size_t N>
void setSimple<N>::insert(const std::size_t elem)
{
    simpleSet[elem / IntBits] |= (1U << (elem % IntBits));
}

template <std::size_t N>
bool setSimple<N>::contains(const std::size_t elem)
{
    return simpleSet[elem / IntBits] >> (elem % IntBits) & 1U;
}

template <std::size_t N>
bool setSimple<N>::operator==(const setSimple<N> &other)
{
    return false;
}

template <std::size_t N>
std::ostream &operator<<(std::ostream &os, const setSimple<N> &obj)
{
    for (std::size_t i = 0; i < N; i++)
    {
        os << ((obj.simpleSet[i / obj.IntBits] >> (i % obj.IntBits)) & 1U) << " ";
    }

    return os;
}