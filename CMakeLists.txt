cmake_minimum_required(VERSION 3.12)

project(cherry)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

option(BUILD_TESTS "Build unit tests." ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
message("cmake_module_path: ${CMAKE_MODULE_PATH}")

# 设置基础变量
SET(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/output)
SET(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third)
SET(CMAKE_INSTALL_MESSAGE TRUE)
# 设置基础变量
SET(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("INSTALL_DIR: ${INSTALL_DIR} SRC_DIR:${SRC_DIR}")

if(BUILD_DEPS)
    INCLUDE(deps/gtest.cmake)
    INCLUDE(deps/spdlog.cmake)
    INCLUDE(deps/lua.cmake)
    INCLUDE(deps/yyjson.cmake)
else()


    # 链接interface 便于开发
    INCLUDE(cmake/interface.cmake)
    
    # 一些封装 find_package
    INCLUDE(cmake/spdlog.cmake)
    INCLUDE(cmake/yyjson.cmake)
    INCLUDE(cmake/lua.cmake)

    set(CHERRY_MAJOR_VERSION 0)
    set(CHERRY_MINOR_VERSION 0)
    set(CHERRY_PATCH_VERSION 1)
    set(CHERRY_VERSION
        ${CHERRY_MAJOR_VERSION}.${CHERRY_MINOR_VERSION}.${CHERRY_PATCH_VERSION})
    set(CHERRY_VERSION_STRING "${CHERRY_VERSION}")

    add_subdirectory(src)
endif()

install(FILES README.md
    DESTINATION ${INSTALL_DIR})