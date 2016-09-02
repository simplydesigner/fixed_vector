#include <iostream>
#include "fixed_vector.hpp"

class logable
{
public:
    logable() : attribute_(0)
    {
        ++count;
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    logable(logable const & other) : attribute_ (other.attribute_)
    {
        ++count;
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    auto operator =(logable const & other) -> logable &
    {
        attribute_ = other.attribute_;
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }
    
    logable(logable && other)
    {
        ++count;
        attribute_ = other.attribute_;
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
        
    auto operator =(logable && other) -> logable &
    {
        attribute_ = other.attribute_;
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }
        
    ~logable()
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
        
    static auto clear_count() -> void
    {
        count = 0;
    }
        
    static size_t count;
private:
    std::size_t attribute_;
        
    friend auto operator <<(std::ostream & stream, logable const &) -> std::ostream &;
    friend auto operator >>(std::istream & stream, logable &) -> std::istream &;
};
        
size_t logable::count = 0;
        
auto operator <<(std::ostream & stream, logable const & logable) -> std::ostream &
{
    stream << logable.attribute_;
    return stream;
}
        
auto operator >>(std::istream & stream, logable & logable) -> std::istream &
{
    stream >> logable.attribute_;
    return stream;
}
        
auto generic_implementation() -> void
{
    fixed_vector<logable, 2> v1;
    
    auto first = std::istream_iterator<logable> { std::cin };
    std::cout << "constructed first iterator" << std::endl;
    
    auto end = std::istream_iterator<logable> { };
    std::cout << "constructed end iterator" << std::endl;
    
    std::copy(first, end, v1.begin());
    std::cout << "completed copying to vector" << std::endl;
    
//    std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<logable> { std::cout, " " });
    
    std::cout << std::endl;
    
    std::cin.clear();
    clearerr(stdin);
}
        
auto generic_implementation_with_rvalue() -> void
{
    fixed_vector<logable, 2> v1;
    
    std::cout << "constructed end iterator" << std::endl;
    
    std::copy(std::istream_iterator<logable> { std::cin }, std::istream_iterator<logable> { }, v1.begin());
    std::cout << "completed copying to vector" << std::endl;
    
//    std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<logable> { std::cout, " " });
    
    std::cout << std::endl;
    
    std::cin.clear();
    clearerr(stdin);
}
        
auto no_generic_implementation() -> void
{
    fixed_vector<logable, 2> v1;
    auto it = v1.begin();
    
    while ( std::cin >> *it++ ) {
        
    }
    
//    std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<logable> { std::cout, " " });
    
    std::cout << std::endl;
    
    std::cin.clear();
    clearerr(stdin);
}

int main(int argc, const char * argv[]) {

    generic_implementation();
    std::cout << logable::count << std::endl;
    logable::clear_count();
    
//    generic_implementation_with_rvalue();
//    std::cout << logable::count << std::endl;
//    logable::clear_count();
//    
//    no_generic_implementation();
//    std::cout << logable::count << std::endl;
//    logable::clear_count();
    
    
    return 0;
}
