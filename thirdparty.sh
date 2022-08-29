#!/usr/bin/env bash

set -eux

# 使用git subaddmodule下载第三方开源库
# 然后使用cmake_externalproject进行编译

# spdlog lua gtest yyjson
git submodule add  git@github.com:gabime/spdlog.git ./third/spdlog
git submodule add  git@github.com:google/googletest.git ./third/gtest
git submodule add  git@github.com:lua/lua.git ./third/lua