# -*- coding: utf-8 -*-
# ----------------------------------------------------------------------
# Copyright © 2011-2014, RedJack, LLC.
# All rights reserved.
#
# Please see the LICENSE.txt file in this distribution for license
# details.
# ----------------------------------------------------------------------

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#-----------------------------------------------------------------------
# Build the library

set(LIBCROISSANT_SRC
    libcroissant/application.c
    libcroissant/context.c
    libcroissant/id.c
    libcroissant/local.c
    libcroissant/message.c
    libcroissant/node.c
    libcroissant/node-ref.c
    libcroissant/routing.c
    libcroissant/tests.c
)

# Update the VERSION and SOVERSION properties below according to the following
# rules (taken from [1]):
#
# VERSION = current.revision.age
#
#   1. Start with a VERSION of `0.0.0` for each shared library.
#   2. Update VERSION only immediately before a public release of your software.
#      More frequent updates are unnecessary, and only guarantee that the
#      current interface number gets larger faster.
#   3. If the library source code has changed at all since the last update, then
#      increment `revision` (`c.r.a` becomes `c.r+1.a`).
#   4. If any interfaces have been added, removed, or changed since the last
#      update, increment `current`, and set `revision` to 0.
#   5. If any interfaces have been added since the last public release, then
#      increment `age`.
#   6. If any interfaces have been removed or changed since the last public
#      release, then set `age` to 0.
#
# SOVERSION should always equal `current`.
#
# Note that changing `current` means that you are releasing a new
# backwards-incompatible version of the library.  This has implications on
# packaging, so once an API has stabilized, these should be a rare occurrence.
#
# [1] http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html#Updating-version-info

add_library(libcroissant SHARED ${LIBCROISSANT_SRC})
set_target_properties(libcroissant PROPERTIES
    OUTPUT_NAME croissant
    VERSION 0.0.0
    SOVERSION 0)
target_link_libraries(libcroissant
    ${CORK_LIBRARIES}
    ${CLOG_LIBRARIES}
)

install(TARGETS libcroissant DESTINATION ${CMAKE_INSTALL_LIBDIR})

#-----------------------------------------------------------------------
# Generate the pkg-config file

set(prefix ${CMAKE_INSTALL_PREFIX})
configure_file(croissant.pc.in ${CMAKE_CURRENT_BINARY_DIR}/croissant.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/croissant.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

#-----------------------------------------------------------------------
# croissant

set(CROISSANT_RAGEL
    croissant/test.c.rl
)

set_property(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    PROPERTY CLEAN_NO_CUSTOM true
)

foreach(RAGEL_INPUT ${CROISSANT_RAGEL})
    string(REGEX REPLACE "\\.rl$" "" RAGEL_OUTPUT "${RAGEL_INPUT}")
    if (RAGEL)
        add_custom_command(
            OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/${RAGEL_OUTPUT}"
            COMMAND ragel -G2 -o "${RAGEL_OUTPUT}" "${RAGEL_INPUT}"
            MAIN_DEPENDENCY "${RAGEL_INPUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMENT "Ragel ${RAGEL_INPUT}"
        )
    else (RAGEL)
        # Ragel is not present; if the Ragel source files get out of date,
        # that's an error.
        add_custom_command(
            OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/${RAGEL_OUTPUT}"
            COMMAND false
            MAIN_DEPENDENCY "${RAGEL_INPUT}"
            COMMENT "Ragel not found; cannot update ${RAGEL_OUTPUT}"
        )
    endif (RAGEL)
endforeach(RAGEL_INPUT)

set(CROISSANT_SRC
    croissant/root.c
    croissant/test.c
)

add_executable(croissant ${CROISSANT_SRC})
target_link_libraries(croissant
    libcroissant
    ${CORK_LIBRARIES}
    ${CLOG_LIBRARIES}
)
install(TARGETS croissant DESTINATION bin)
