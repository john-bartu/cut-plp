project(LAB3)

add_subdirectory(matrix-lib)

add_executable(LAB3_Matrix_Test exercise_matrix.cpp)

target_link_libraries (LAB3_Matrix_Test LINK_PUBLIC MATRIX_LIB)