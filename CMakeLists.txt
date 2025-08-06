cmake_minimum_required(VERSION 3.16)

project(SevenTools VERSION 1.0 LANGUAGES CXX)

add_subdirectory(Macros)
add_subdirectory(Threads)
add_subdirectory(Utility)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_SHARED "是否构建动态库" OFF)
option(INSTALL_DOC "是否安装文档" ON)

file(GLOB SRC
    "Threads/*.cpp"
    "Utility/*.cpp"
)

include_directories(
    "./"
    "Macros"
    "Threads"
    "Utility"
)
add_compile_definitions(BuildSevenTools)

if(NOT SRC STREQUAL "")
    if(BUILD_SHARED)
        add_library(SevenTools SHARED ${SRC})
        set_target_properties(SevenTools PROPERTIES SOVERSION 1)
        add_compile_definitions(SharedSevenTools)
        install(TARGETS SevenTools LIBRARY)
    else()
        add_library(SevenTools STATIC ${SRC})
        install(TARGETS SevenTools ARCHIVE)
    endif()
endif()

if(INSTALL_DOC)
    install(DIRECTORY Docs DESTINATION ".")
endif()

install(DIRECTORY cmake DESTINATION "." PATTERN "*.in" EXCLUDE)

include(CMakePackageConfigHelpers)
configure_package_config_file("cmake/SevenToolsConfig.cmake.in" "${CMAKE_BINARY_DIR}/cmake/SevenToolsConfig.cmake" INSTALL_DESTINATION "cmake")
install(FILES "${CMAKE_BINARY_DIR}/cmake/SevenToolsConfig.cmake" DESTINATION "cmake")

message(STATUS "已配置完成，将安装至目录 ${CMAKE_INSTALL_PREFIX}")
