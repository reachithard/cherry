include(ExternalProject)
ExternalProject_Add(spdlog
  INSTALL_DIR ${INSTALL_DIR}
  SOURCE_DIR  ${SRC_DIR}/spdlog
  # CONFIGURE_COMMAND ${CMAKE_COMMAND}
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/spdlog
  CMAKE_ARGS  -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
              -DCMAKE_BUILD_TYPE=Release
              -DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}
              -DCMAKE_C_COMPILE=${CMAKE_C_COMPILE}
              -DCMAKE_CXX_COMPILE=${CMAKE_CXX_COMPILE}
              -DCMAKE_VERBOSE_MAKEFILE=${CMAKE_VERBOSE_MAKEFILE}
              -DCMAKE_INSTALL_MESSAGE=TRUE
  INSTALL_COMMAND ${CMAKE_MAKE_PROGRAM} install
  )