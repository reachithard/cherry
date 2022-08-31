include(ExternalProject)

# 该项目没有cmake 所以要自己手动写

SET(LUA_OUTPUT ${SRC_DIR}/lua/install)
message("lua dir: ${SRC_DIR}/lua ${LUA_OUTPUT} ${INSTALL_DIR}")
SET(LUA_CONFIGURE cd ${SRC_DIR}/lua)
SET(LUA_MAKE cd ${SRC_DIR}/lua &&  make)
SET(LUA_INSTALL cd ${SRC_DIR}/lua && make install INSTALL_TOP=${INSTALL_DIR})

ExternalProject_Add(lua
  INSTALL_DIR ${INSTALL_DIR}
  SOURCE_DIR  ${SRC_DIR}/lua
  # URL http://www.lua.org/ftp/lua-5.4.4.tar.gz
  # CONFIGURE_COMMAND ${CMAKE_COMMAND}
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/lua
  CONFIGURE_COMMAND ${LUA_CONFIGURE}
  BUILD_COMMAND ${LUA_MAKE}
  INSTALL_COMMAND ${LUA_INSTALL}
)
