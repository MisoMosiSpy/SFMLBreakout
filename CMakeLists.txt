cmake_minimum_required(VERSION 3.5)
project(SFMLBreakout LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(SFMLBreakout src/main.cpp
                    src/ball.cpp
                    src/border.cpp
                    src/paddle.cpp
)
target_link_libraries(SFMLBreakout PRIVATE sfml-graphics)
target_compile_features(SFMLBreakout PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET SFMLBreakout
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SFMLBreakout>
        VERBATIM)
    add_custom_command(
            TARGET SFMLBreakout
            COMMENT "Copy Resources"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:SFMLBreakout>/resources
            VERBATIM)
endif()
