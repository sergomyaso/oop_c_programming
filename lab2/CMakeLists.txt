SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable (lab2 "src/main.cpp"  "src/workers/ReadWorker.cpp" "src/workers/WriteWorker.h" "src/workers/WriteWorker.cpp" "src/workers/GrepWorker.h"
"src/workers/GrepWorker.cpp" "src/workers/ReplaceWorker.h" "src/workers/ReplaceWorker.cpp" "src/workers/DumpWorker.h" "src/workers/DumpWorker.cpp" "src/workers/SortWorker.h" "src/workers/SortWorker.cpp" 
"src/handlers/ParserInterface.h" "src/handlers/Parser.h" "src/handlers/Parser.cpp"    "src/workers/WorkingCreatingContext.h" "src/workers/WorkingCreatingContext.cpp" "src/WorkflowApp.h" 
"src/WorkflowApp.cpp" "src/handlers/WorkflowReader.cpp" "src/handlers/WorkflowValidator.h" "src/handlers/WorkflowValidator.cpp"  "src/exceptions/WorkflowExceptionInterface.h"
"src/exceptions/WorkflowExceptionContext.h" "src/exceptions/WorkflowExceptionContext.cpp" "src/exceptions/OpenFileException.h" "src/exceptions/OpenFileException.cpp" "src/exceptions/ValidFileException.h" 
"src/exceptions/ValidFileException.cpp" "src/tests/TestWorkflowConstants.h" "src/tests/TestFunction.h" "src/tests/TestFunction.cpp"   "src/workers/WorkflowFunctions.h" "src/handlers/WorkflowValidatorInterface.h" "src/handlers/WorkflowReaderInterface.h")
target_link_libraries(lab2 gtest_main)
add_test(NAME example_test COMMAND lab2)


# Tests:
