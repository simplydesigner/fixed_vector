#ifndef fixed_vector_hpp
#define fixed_vector_hpp

#include <iostream>
#include <algorithm>

template <typename T, std::size_t size>
class fixed_vector
{
    using iterator = T *;
    using const_iterator = const T *;
public:
    fixed_vector()
    {
        
    }
    
    fixed_vector(fixed_vector const & other)
    {
        std::copy(other.begin(), other.end(), begin());
    }
    
    auto operator =(fixed_vector const & other) -> fixed_vector &
    {
        std::copy(other.begin(), other.end(), begin());
    }
    
    template <typename U, std::size_t osize>
    fixed_vector(fixed_vector<U, osize> const & other)
    {
        std::copy(other.begin(), other.begin() + std::min(size, osize), begin());
    }
    
    template <typename U, std::size_t osize>
    auto operator =(fixed_vector<U, osize> const & other) -> fixed_vector &
    {
        std::copy(other.begin(), other.begin() + std::min(size, osize), begin());
    }
    
    auto begin() -> iterator
    {
        return v_;
    }
    
    auto end() -> iterator
    {
        return v_ + size;
    }
    
    auto cbegin() const -> const_iterator
    {
        return v_;
    }
    
    auto cend() const -> const_iterator
    {
        return v_ + size;
    }
    
    
private:
    T v_[size];
};

#endif /* fixed_vector_hpp */
