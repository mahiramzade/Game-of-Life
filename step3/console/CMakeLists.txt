add_library(console ansi_console.c board_drawer.h)

include_directories(../game)

install(TARGETS console DESTINATION lib)
install(FILES board_drawer.h DESTINATION include)