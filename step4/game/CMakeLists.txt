add_library(game life.c life.h)

install(TARGETS game DESTINATION lib)
install(FILES life.h DESTINATION include)