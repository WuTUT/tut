#include <iostream>

#include <fmt/core.h>
#include <tut/log_common.h>
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout <<  fmt::format(tut::log::Level::toStringView(tut::log::Level::levelNum::DEBUG)) << std::endl;
    return 0;
}
