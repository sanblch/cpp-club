add_executable(embed embed.cxx)
target_link_libraries(embed PRIVATE pybind11::embed)
