# LightsOutSys
add_library(LightsOutSys STATIC LightsOutSys.cpp)

target_include_directories(LightsOutSys PRIVATE ${PROJECT_SOURCE_DIR}/include)

# LightsOut
add_executable(LightsOut LightsOut.cpp)

target_link_libraries(LightsOut LightsOutSys)

target_include_directories(LightsOut PRIVATE ${PROJECT_SOURCE_DIR}/include)