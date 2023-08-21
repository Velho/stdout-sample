# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# out of dir link enabled
cmake_policy (SET CMP0079 NEW)

project ("stdout-example")

# project configuration variables.
set (JSON_BuildTests OFF CACHE INTERNAL "")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include depedencies.
add_subdirectory (deps/json)

# include sub-projects.
add_subdirectory ("json-gen")
add_subdirectory ("json-consumer")

# link against deps
target_link_libraries (json-gen       PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries (json-consumer  PRIVATE nlohmann_json::nlohmann_json)

target_include_directories (json-gen      PRIVATE deps/json/include)
target_include_directories (json-consumer PRIVATE deps/json/include)
