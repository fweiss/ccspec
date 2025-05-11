file(GLOB_RECURSE SPEC "*.h" "*.cc")
add_executable(ccspec_spec ${SPEC})
target_link_libraries(ccspec_spec LINK_PUBLIC ccspec)

if(MSVC) # issue-10
    target_compile_options(ccspec PUBLIC
        -D_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
        -D_ITERATOR_DEBUG_LEVEL=0
        )
endif()
