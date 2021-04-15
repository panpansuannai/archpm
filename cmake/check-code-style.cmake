find_program(CLANG_FORMAT_EXEC NAMES "clang-format")
if(NOT CLANG_FORMAT_EXEC)
  message(WARNING "Check for clang-format: Not found, clang-format will not be executed")
else()
  message(STATUS "Check for clang-format: Found")
  execute_process(
    COMMAND ./cmake/run-clang-format.sh
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    RESULT_VARIABLE status
  )
  if(NOT status EQUAL 0)
    message(FATAL_ERROR "Code Style issues found (clang-format)")
  endif()
endif()

