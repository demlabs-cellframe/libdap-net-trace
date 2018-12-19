cmake_minimum_required(VERSION 3.0)
project(libdap-net-trace C)

file(GLOB SRCS *.c)
file(GLOB HEADERS *.h)

# fix implicit declaration warnings
add_definitions ("-D_GNU_SOURCE")
add_definitions ("-DNODE_NETNAME=\"kelvin\"")

set(CMAKE_C_FLAGS "-std=c11 -Wall -Wextra")

add_executable(${PROJECT_NAME} ${SRCS})

add_subdirectory(libdap)
add_subdirectory(libdap-chain)
add_subdirectory(libdap-chain-crypto)
add_subdirectory(libdap-chain-block)
add_subdirectory(libdap-chain-net)

target_include_directories(${PROJECT_NAME}  INTERFACE .)
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR} CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

target_link_libraries(${PROJECT_NAME} dap_core dap_crypto dap_chain_net)

set(CMAKE_C_STANDARD 11)
