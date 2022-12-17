# LightsOutSys
add_library(LightsOutSys STATIC LightsOutSys.cpp)

target_include_directories(LightsOutSys PRIVATE ${PROJECT_SOURCE_DIR}/include)

# LightsOutCUI
add_library(LightsOutCUI STATIC LightsOutCUI.cpp)

target_link_libraries(LightsOutCUI LightsOutSys)

target_include_directories(LightsOutCUI PRIVATE ${PROJECT_SOURCE_DIR}/include)

# LightsOut
add_executable(LightsOut LightsOut.cpp)

target_link_libraries(LightsOut LightsOutCUI)

target_include_directories(LightsOut PRIVATE ${PROJECT_SOURCE_DIR}/include)