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

file(GLOB_RECURSE LIBCROISSANT_SRC libcroissant/*.c)

add_library(libcroissant SHARED ${LIBCROISSANT_SRC})
set_target_properties(libcroissant PROPERTIES
    OUTPUT_NAME croissant
    SOVERSION 0.0.0)
target_link_libraries(libcroissant
    ${CORK_LIBRARIES}
)

install(TARGETS libcroissant LIBRARY DESTINATION lib)

#-----------------------------------------------------------------------
# Generate the pkg-config file

set(prefix ${CMAKE_INSTALL_PREFIX})
configure_file(croissant.pc.in croissant.pc)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/croissant.pc
        DESTINATION lib/pkgconfig)
