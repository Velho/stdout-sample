
add_executable (json-consumer "json-consumer.h" "json-consumer.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET json-consumer PROPERTY CXX_STANDARD 20)
endif()

