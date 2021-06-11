add_library(gui gui.c gui.h)

include_directories(../game)

install(TARGETS gui DESTINATION lib)
install(FILES gui.h DESTINATION include)