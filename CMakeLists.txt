cmake_minimum_required(VERSION 3.14)
project(UnitTestProj)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 启用测试
enable_testing()

# 添加头文件目录
include_directories(${CMAKE_SOURCE_DIR}/src)

# 链接Google Test和Google Mock库
include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)

# 添加测试源文件
add_executable(
  unit_test_demo
  src/hello_test.cpp src/test_mock.cpp
)

# 链接Google Test、Google Mock
target_link_libraries(unit_test_demo gtest gmock gtest_main)

# 包含Google Test的发现测试功能
include(GoogleTest)
# 使用gtest_discover_tests命令自动发现并运行unit_test_demo目标中的所有测试
gtest_discover_tests(unit_test_demo)
