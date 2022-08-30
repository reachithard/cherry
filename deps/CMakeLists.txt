cmake_minimum_required(VERSION 3.12)

project(deps)

# 设置基础变量
SET(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../output)
SET(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../third)
MESSAGE("INSTALL_DIR: ${INSTALL_DIR} SRC_DIR:${SRC_DIR}")

# INCLUDE(gtest.cmake)
INCLUDE(spdlog.cmake)