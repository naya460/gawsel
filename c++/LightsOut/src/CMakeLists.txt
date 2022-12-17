# find and include WxWidgets
if (${UI_MODE} MATCHES "WX_WIDGETS")
    find_package(wxWidgets REQUIRED COMPONENTS net core base)
    include(${wxWidgets_USE_FILE})
endif()

# LightsOutSys
add_library(LightsOutSys STATIC LightsOutSys.cpp)

target_include_directories(LightsOutSys PRIVATE ${PROJECT_SOURCE_DIR}/include)

# LightsOutCUI
if (${UI_MODE} MATCHES "CUI")
    add_library(LightsOutCUI STATIC LightsOutCUI.cpp)

    target_link_libraries(LightsOutCUI LightsOutSys)

    target_include_directories(LightsOutCUI PRIVATE ${PROJECT_SOURCE_DIR}/include)
endif()

# LightsOutWxWidgets
if (${UI_MODE} MATCHES "WX_WIDGETS")
    add_library(LightsOutWxWidgets STATIC LightsOutWxWidgets.cpp)

    target_link_libraries(LightsOutWxWidgets LightsOutSys)

    target_include_directories(LightsOutWxWidgets PRIVATE ${PROJECT_SOURCE_DIR}/include)
endif()

# LightsOut
add_executable(LightsOut LightsOut.cpp)

if (${UI_MODE} MATCHES "CUI")
    target_link_libraries(LightsOut LightsOutCUI)
elseif (${UI_MODE} MATCHES "WX_WIDGETS")
    target_link_libraries(LightsOut ${wxWidgets_LIBRARIES} LightsOutWxWidgets)
endif()

target_include_directories(LightsOut PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_compile_options(LightsOut PRIVATE -D${UI_MODE})