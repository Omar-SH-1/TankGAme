# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TankGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TankGame_autogen.dir\\ParseCache.txt"
  "TankGame_autogen"
  )
endif()
