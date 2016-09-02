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
    fixed_vector(): v_(new T[size], [](T * ptr) { delete [] ptr; } )
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    fixed_vector(fixed_vector const & other): v_(new T[size], [](T * ptr) { delete [] ptr; } )
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::copy(other.cbegin(), other.cend(), begin());
    }
    
    auto operator =(fixed_vector const & other) -> fixed_vector &
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::copy(other.begin(), other.end(), begin());
        return *this;
    }
    
    fixed_vector(fixed_vector && other) = default;
    
    auto operator =(fixed_vector && other) -> fixed_vector & = default;
    
    template <typename U, std::size_t osize>
    fixed_vector(fixed_vector<U, osize> const & other)
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::copy(other.begin(), other.begin() + std::min(size, osize), begin());
    }
    
    template <typename U, std::size_t osize>
    auto operator =(fixed_vector<U, osize> const & other) -> fixed_vector &
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::copy(other.begin(), other.begin() + std::min(size, osize), begin());
        return  *this;
    }
    
    auto begin() -> iterator
    {
        return v_.get();
    }
    
    auto end() -> iterator
    {
        return v_.get() + size;
    }
    
    auto cbegin() const -> const_iterator
    {
        return v_.get();
    }
    
    auto cend() const -> const_iterator
    {
        return v_.get() + size;
    }
    
    
private:
    std::unique_ptr<T, void (*)(T *)> v_;
};

#endif /* fixed_vector_hpp */
