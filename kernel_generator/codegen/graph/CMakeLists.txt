set(SRC
    graph.cpp
    gnode.cpp
    gedge.cpp
    graph_util.cpp
)

add_library(codegen_graph STATIC ${SRC})
target_include_directories(codegen_graph SYSTEM PUBLIC
    ${GLOBAL_INCLUDE_PATH}
)
target_link_libraries(codegen_graph PRIVATE codegen_serialize)