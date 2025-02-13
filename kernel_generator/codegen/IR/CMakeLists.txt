set(SRC
    attribute.cpp
    instruction.cpp
    program.cpp
)

add_library(codegen_ir STATIC ${SRC})
target_include_directories(codegen_ir SYSTEM PUBLIC
    ${GLOBAL_INCLUDE_PATH}
)