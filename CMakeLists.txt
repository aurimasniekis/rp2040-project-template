cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from GIT
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_FETCH_FROM_GIT on)

# pico_sdk_import.cmake is a single file copied from this SDK
# note: this must happen before project()
include(.cmake/pico_sdk_import.cmake)

project(rp2040_project)

# set svd file path fro CLion
set(CLION_SVD_FILE_PATH ${PICO_SDK_PATH}/src/rp2040/hardware_regs/rp2040.svd)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(rp2040_project
    main.c
)

pico_enable_stdio_usb(rp2040_project 1)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(rp2040_project pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(rp2040_project)
