# Collect the header and source files of PyReaktoro
file(GLOB_RECURSE HEADER_FILES *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.cpp)

# This is needed to avoid some compilation issues when using clang-9 and c++17
if(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 10.0.0)
    add_compile_options(-fno-aligned-allocation -fno-sized-deallocation)
endif()

# Include the Reaktoro/python directory
include_directories(${PROJECT_SOURCE_DIR}/python)

# Include the Reaktoro/Reaktoro/Math directory where Eigen is located (for pybind11)
include_directories(${PROJECT_SOURCE_DIR}/Reaktoro/deps/eigen3)

# Create the PyReaktoro library
pybind11_add_module(PyReaktoro ${SOURCE_FILES} NO_EXTRAS) # NO_EXTRAS used to decrease linking time, but causes larger module file size

# Link PyReaktoro against Reaktoro library
target_link_libraries(PyReaktoro LINK_PRIVATE Reaktoro::Reaktoro)
