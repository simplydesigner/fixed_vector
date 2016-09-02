#include <iostream>
#include "fixed_vector.hpp"

int main(int argc, const char * argv[]) {

    fixed_vector<std::size_t, 4> v1;
    
    std::copy(std::istream_iterator<std::size_t> { std::cin }, std::istream_iterator<std::size_t> {}, v1.begin());
    
    std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<std::size_t> { std::cout, " " });
    
    std::cout << std::endl;
    
    return 0;
}
