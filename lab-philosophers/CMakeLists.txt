set(CMAKE_CXX_STANDARD 11)
project(LAB7_Philosophers)
find_package( Threads )

add_executable(LAB7_Philosophers src/main.cpp)



target_link_libraries( LAB7_Philosophers ${CMAKE_THREAD_LIBS_INIT} )