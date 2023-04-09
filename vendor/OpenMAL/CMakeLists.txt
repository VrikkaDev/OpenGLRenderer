project(openmal)

file(GLOB_RECURSE header_files
        "openmal/*.h"
        )

add_library(openmal SHARED ${header_files})
set_target_properties(openmal PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(openmal PUBLIC /)