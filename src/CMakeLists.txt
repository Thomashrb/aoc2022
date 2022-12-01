add_executable(aoc2022 main.cpp)

set(P_LIBS
  utils.hpp
  d01.cpp
  d02.cpp
  d03.cpp
  d04.cpp
  d05.cpp
  d06.cpp
  d07.cpp
  d08.cpp
  d09.cpp
  d10.cpp
)

add_library(aoc2022_lib ${P_LIBS})

# expose library files (used in testing)
target_include_directories(aoc2022_lib PUBLIC .)
