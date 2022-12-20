add_library(MinesweeperSys STATIC MinesweeperSys.cpp)

target_include_directories(MinesweeperSys PRIVATE ${PROJECT_SOURCE_DIR}/include)


add_executable(Minesweeper Minesweeper.cpp)

target_link_libraries(Minesweeper MinesweeperSys)

target_include_directories(Minesweeper PRIVATE ${PROJECT_SOURCE_DIR}/include)