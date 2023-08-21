# CMakeList.txt : CMake project for json-gen, include source and define
# project specific logic here.
#

set (JSON_GEN_SOURCES
	"json-gen.cpp" "json-gen.h"
	"win-wrapper.cpp" "win-wrapper.h")

# Add source to this project's executable.
add_executable (json-gen ${JSON_GEN_SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET json-gen PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
