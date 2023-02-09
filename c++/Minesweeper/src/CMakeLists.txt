# MinesweeperSys
add_library(MinesweeperSys STATIC MinesweeperSys.cpp)

target_include_directories(MinesweeperSys PRIVATE ${PROJECT_SOURCE_DIR}/include)

# MinesweeperCUI
add_library(MinesweeperCUI STATIC MinesweeperCUI.cpp)

target_link_libraries(MinesweeperCUI MinesweeperSys)

target_include_directories(MinesweeperCUI PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Minesweeper
add_executable(Minesweeper Minesweeper.cpp)

target_link_libraries(Minesweeper MinesweeperSys MinesweeperCUI)

target_include_directories(Minesweeper PRIVATE ${PROJECT_SOURCE_DIR}/include)