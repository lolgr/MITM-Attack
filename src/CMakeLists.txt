# Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
# reserved. Use of this source code is governed by a BSD-style license that
# can be found in the LICENSE file.

#
# Source files.
#

# cefsimple sources.

set(CEFSIMPLE_SRCS
  MITMApp.cpp
  MITMApp.h
  MITMHandler.cpp
  MITMHandler.h
  )
set(CEFSIMPLE_SRCS_LINUX
  )
  
APPEND_PLATFORM_SOURCES(CEFSIMPLE_SRCS)
source_group(MITMAttack FILES ${CEFSIMPLE_SRCS})

set(CEFSIMPLE_SRCS
  ${CEFSIMPLE_SRCS}
  )
APPEND_PLATFORM_SOURCES(CEFSIMPLE_HELPER_SRCS)
source_group(MITMAttack FILES ${CEFSIMPLE_HELPER_SRCS})

# Target executable names.
set(CEF_TARGET "MITMAttack")

ADD_LOGICAL_TARGET("libcef_lib" "${CEF_LIB_DEBUG}" "${CEF_LIB_RELEASE}")

# Determine the target output directory.
# SET_CEF_TARGET_OUT_DIR()
set(CEF_TARGET_OUT_DIR ${CMAKE_SOURCE_DIR}/Release)


#
# Linux configuration.
#
# include_directories(${CEF_ROOT})
# include_directories(${CMAKE_SOURCE_DIR})
# include_directories(${CMAKE_SOURCE_DIR}/third_party/cpprestsdk/Release/Release/include/cpprest)
# add_executable(${CEF_TARGET} ${CEFSIMPLE_SRCS})
# target_link_libraries(${CEF_TARGET} libcef_lib ${CEF_ROOT}/libcef_dll_wrapper/libcef_dll_wrapper.a ${CEF_STANDARD_LIBS})
# target_link_libraries(${CEF_TARGET} ${CMAKE_SOURCE_DIR}/third_party/cpprestsdk/Release/Release/Binaries/libcpprest.so)



if(true)
  # Executable target.
  # include_directories(${CMAKE_SOURCE_DIR})
  # link_directories(${CEF_ROOT})

  # include_directories(${CMAKE_SOURCE_DIR}/third_party/restinio/dev/restinio)
  # include_directories(${CMAKE_SOURCE_DIR}/third_party/restinio/dev)
  # include_directories(${CMAKE_SOURCE_DIR}/third_party/boost/boost)
  # include_directories(${CMAKE_SOURCE_DIR}/third_party/boost)
  # include_directories(${CMAKE_SOURCE_DIR}/third_party/http-parser)

  #include_directories(${CMAKE_SOURCE_DIR}/third_party/restinio/vcpkg/local_installs/include)
  #include_directories(${CMAKE_SOURCE_DIR}/third_party/restinio/dev/asio/include)
  include_directories(${CMAKE_SOURCE_DIR}/third_party/cef_binary_141.0.11+g7e73ac4+chromium-141.0.7390.123_linux64)
  include_directories(${CMAKE_SOURCE_DIR}/third_party)
  


  add_executable(${CEF_TARGET} ${CEFSIMPLE_SRCS})
  link_directories(${CMAKE_SOURCE_DIR}/third_party/boost/lib)
  #link_directories(${CMAKE_SOURCE_DIR}/third_party/restinio/vcpkg/local_installs/lib)
  
  #set_target_properties(${CEF_TARGET} PROPERTIES LINKER_LANGUAGE CXX)


  # SET_EXECUTABLE_TARGET_PROPERTIES(${CEF_TARGET})
  target_link_libraries(${CEF_TARGET} boost_system)
  #target_link_libraries(${CEF_TARGET} ${CMAKE_SOURCE_DIR}/third_party/restinio/vcpkg/local_installs/lib/libfmt.a)
  #target_link_libraries(${CEF_TARGET} ${CMAKE_SOURCE_DIR}/third_party/restinio/vcpkg/local_installs/lib/libhttp_parser.a)
  target_link_libraries(${CEF_TARGET} libcef_lib ${CEF_ROOT}/libcef_dll_wrapper/libcef_dll_wrapper.a ${CEF_STANDARD_LIBS})

  # Set rpath so that libraries can be placed next to the executable.
  set_target_properties(${CEF_TARGET} PROPERTIES INSTALL_RPATH "$ORIGIN")
  set_target_properties(${CEF_TARGET} PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
  set_target_properties(${CEF_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CEF_TARGET_OUT_DIR})
  
  
  #set_target_properties(${CEF_TARGET} PROPERTIES LINKER_LANGUAGE CXX)



  # Copy binary and resource files to the target output directory.
  COPY_FILES("${CEF_TARGET}" "${CEF_BINARY_FILES}" "${CEF_BINARY_DIR}" "${CEF_TARGET_OUT_DIR}")
  COPY_FILES("${CEF_TARGET}" "${CEF_RESOURCE_FILES}" "${CEF_RESOURCE_DIR}" "${CEF_TARGET_OUT_DIR}")
  if (EXISTS "${CEF_BINARY_DIR}/libminigbm.so")
    COPY_FILES("${CEF_TARGET}" "libminigbm.so" "${CEF_BINARY_DIR}" "${CEF_TARGET_OUT_DIR}")
  endif()

  # Set SUID permissions on the chrome-sandbox target.
  SET_LINUX_SUID_PERMISSIONS("${CEF_TARGET}" "${CEF_TARGET_OUT_DIR}/chrome-sandbox")


endif()