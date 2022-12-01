set(TEST_LIBS Catch2 aoc2022_lib)
set(UNIT_TESTS
  utilstest
  01test
  02test
  03test
  04test
  05test
  06test
  07test
  08test
  09test
  10test
)

foreach(_test ${UNIT_TESTS})
  add_executable(${_test} ./${_test}.cpp)
  # Each test is its own executable : link dependencies
  target_link_libraries(${_test} ${TEST_LIBS} Catch2::Catch2WithMain)
  # enable running of test executables with `ctest`
  add_test(${_test} ${_test})
endforeach()
