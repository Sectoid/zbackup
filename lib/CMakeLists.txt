# Copyright (c) 2012-2014 Konstantin Isakov <ikm@zbackup.org> and ZBackup contributors, see CONTRIBUTORS
# Part of ZBackup. Licensed under GNU GPLv2 or later + OpenSSL, see LICENSE

PROTOBUF_GENERATE_CPP( protoSrcs protoHdrs zbackup.proto )

file( GLOB sourceFiles "*.cc" )

add_library(zbackup_dynamic SHARED ${sourceFiles} ${protoSrcs} ${protoHdrs} )

set_target_properties(zbackup_dynamic PROPERTIES
  OUTPUT_NAME zbackup
  VERSION ${ZBACKUP_VERSION}
  SOVERSION ${ZBACKUP_MAJOR_VERSION}
  )
target_include_directories (zbackup_dynamic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(zbackup_static STATIC ${sourceFiles} ${protoSrcs} ${protoHdrs} )

set_target_properties(zbackup_static PROPERTIES
  OUTPUT_NAME zbackup
  VERSION ${ZBACKUP_VERSION}
  SOVERSION ${ZBACKUP_MAJOR_VERSION}
  )
target_include_directories (zbackup_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
