FILE(GLOB CHERRY_SRC    ${BASE_DIR}/base/*.cpp ${BASE_DIR}/base/*.hpp
                        ${BASE_DIR}/bind/*.cpp ${BASE_DIR}/bind/*.hpp
                        ${BASE_DIR}/network/*.cpp ${BASE_DIR}/network/*.hpp
                        ${BASE_DIR}/utils/*.cpp ${BASE_DIR}/utils/*.hpp)
add_executable(cherry cherry.cpp)
TARGET_SOURCES(cherry PRIVATE ${CHERRY_SRC})
TARGET_LINK_LIBRARIES(cherry PRIVATE intf)