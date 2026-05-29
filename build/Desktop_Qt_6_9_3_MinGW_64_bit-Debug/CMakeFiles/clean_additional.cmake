# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\tasukete_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tasukete_autogen.dir\\ParseCache.txt"
  "tasukete_autogen"
  )
endif()
