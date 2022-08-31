file(REMOVE_RECURSE
  "CMakeFiles/lua"
  "CMakeFiles/lua-complete"
  "lua/src/lua-stamp/lua-build"
  "lua/src/lua-stamp/lua-configure"
  "lua/src/lua-stamp/lua-download"
  "lua/src/lua-stamp/lua-install"
  "lua/src/lua-stamp/lua-mkdir"
  "lua/src/lua-stamp/lua-patch"
  "lua/src/lua-stamp/lua-update"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/lua.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
