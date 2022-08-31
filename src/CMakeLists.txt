FILE(GLOB CHERRY_SRC    ${BASE_DIR}/src/base/*.cpp ${BASE_DIR}/src/base/*.hpp
                        ${BASE_DIR}/src/bind/*.cpp ${BASE_DIR}/src/bind/*.hpp
                        ${BASE_DIR}/src/network/*.cpp ${BASE_DIR}/src/network/*.hpp
                        ${BASE_DIR}/src/utils/*.cpp ${BASE_DIR}/src/utils/*.hpp)
add_executable(cherry cherry.cpp)
TARGET_SOURCES(cherry PRIVATE ${CHERRY_SRC})
TARGET_LINK_LIBRARIES(cherry PRIVATE intf -lstdc++fs)
spdlog_deps(cherry)
yyjson_deps(cherry)