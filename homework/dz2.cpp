Файл print.cpp:

#include "inout.h"
#include <iostream>

void print(const std::vector<int> &vec) {
    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

Файл read.cpp:

#include "inout.h"
#include <iostream>

void read(std::vector<int> &vec) {
    int n;
    std::cin >> n;
    vec.resize(n);
    for (auto &x : vec) {
        std::cin >> x;
    }
}

Файл CMakeLists.txt:

cmake_minimum_required(VERSION 3.10)

project(my_project)

add_library(inoutlib read.cpp print.cpp)
target_include_directories(inoutlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(my_exec main.cpp)
target_link_libraries(my_exec PRIVATE inoutlib)

Файл main.cpp:

#include "inout.h"
#include <algorithm>

int main() {
    std::vector<int> vec;
    read(vec);
    std::sort(vec.begin(), vec.end());
    print(vec);
    return 0;
}
