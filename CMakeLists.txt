cmake_minimum_required(VERSION 3.20...3.21)
project(ninja-clean-failure
        VERSION 0.0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

include(FetchContent)
FetchContent_Declare(doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest
    GIT_TAG f0ab4e793fa863d4a5929ff263ddd3bebec8767e # 2.4.5
    GIT_SHALLOW ON
)

set(LWS_WITH_SSL ON CACHE BOOL "Use SSL with libwebsockets")
set(LWS_WITHOUT_TESTAPPS ON CACHE BOOL "Don't build the libwebsocket-test-apps")
set(LWS_WITH_MINIMAL_EXAMPLES OFF CACHE BOOL "Don't build the minimal examples")
set(LWS_WITHOUT_TEST_CLIENT ON CACHE BOOL "Don't build the client test application")
set(LWS_WITHOUT_TEST_PING ON CACHE BOOL "Don't build the ping test application")
set(LWS_WITHOUT_SERVER ON CACHE BOOL "Don't build the server part of the library")
set(LWS_WITHOUT_TEST_SERVER ON CACHE BOOL "Don't build the test server")
FetchContent_Declare(libwebsockets
        GIT_REPOSITORY https://github.com/warmcat/libwebsockets
        GIT_TAG 91f0b3bc0f6530f74e4961b9ae49fba6bee8f7b6 #v4.3.1
        GIT_SHALLOW ON)

FetchContent_MakeAvailable(doctest libwebsockets)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} doctest::doctest websockets)