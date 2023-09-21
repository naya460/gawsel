add_library(SlidePuzzleSys STATIC SlidePuzzleSys.cpp)
target_include_directories(SlidePuzzleSys PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_library(SlidePuzzleCUI STATIC SlidePuzzleCUI.cpp)
target_include_directories(SlidePuzzleCUI PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_executable(SlidePuzzle SlidePuzzle.cpp)
target_include_directories(SlidePuzzle PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(SlidePuzzle SlidePuzzleSys SlidePuzzleCUI)