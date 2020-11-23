add_library(MATRIX_LIB matrix.h matrix.cpp)

install(TARGETS MATRIX_LIB DESTINATION lib)
install(FILES matrix.h DESTINATION include)