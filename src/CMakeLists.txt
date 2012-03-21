# -*- coding: utf-8 -*-
# ----------------------------------------------------------------------
# Copyright © 2011, RedJack, LLC.
# All rights reserved.
#
# Please see the LICENSE.txt file in this distribution for license
# details.
# ----------------------------------------------------------------------

include_directories(../include)

#-----------------------------------------------------------------------
# Build the library

file(GLOB_RECURSE LIBDUNKIN_SRC libdunkin/*.c)

add_library(libdunkin SHARED ${LIBDUNKIN_SRC})
set_target_properties(libdunkin PROPERTIES
    OUTPUT_NAME dunkin
    SOVERSION 0.0.0)
target_link_libraries(libdunkin
    ${CORK_LIBRARIES}
)

install(TARGETS libdunkin LIBRARY DESTINATION lib)

#-----------------------------------------------------------------------
# Generate the pkg-config file

set(prefix ${CMAKE_INSTALL_PREFIX})
configure_file(dunkin.pc.in dunkin.pc)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/dunkin.pc
        DESTINATION lib/pkgconfig)
