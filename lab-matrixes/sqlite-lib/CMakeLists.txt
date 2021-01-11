add_library(SQLITE_LIB shell.c sqlite3.c sqlite3.h sqlite3ext.h)

install(TARGETS SQLITE_LIB DESTINATION lib)
install(FILES shell.c sqlite3.c sqlite3.h sqlite3ext.h DESTINATION include)