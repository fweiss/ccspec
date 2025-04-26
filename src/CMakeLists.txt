set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB_RECURSE SRC "*.h" "*.cc")
add_library(ccspec STATIC ${SRC})

if(MSVC) # issue-10
    target_compile_options(ccspec PUBLIC
        -D_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
        -D_ITERATOR_DEBUG_LEVEL=0
        )
endif()

set_target_properties(ccspec PROPERTIES VERSION "0.1.2")
target_include_directories(ccspec PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")
install(TARGETS ccspec DESTINATION lib)
