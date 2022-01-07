cmake_minimum_required(VERSION 3.9.0)

project(react-native-simple-jsi)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)
set (BUILD_DIR ./build)

file (GLOB LIBRN_DIR "${BUILD_DIR}/react-native-0*/jni/${ANDROID_ABI}")
if (JSI_LIB)
  # React Native 0.66.x and above
  add_library(
          cpp
          SHARED
          ../cpp/example.cpp
          ./cpp-adapter.cpp
  )

  find_library(
        JSI_LIB
        jsi
        PATHS ${LIBRN_DIR}
        NO_CMAKE_FIND_ROOT_PATH
  )
else()
  # React Native 0.65.x and below
  add_library(
          cpp
          SHARED
          ../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
          ../cpp/example.cpp
          ./cpp-adapter.cpp
  )
endif()


include_directories(
            ../node_modules/react-native/React
            ../node_modules/react-native/React/Base
            ../node_modules/react-native/ReactCommon/jsi
            ../cpp
)

set_target_properties(
        cpp PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        POSITION_INDEPENDENT_CODE ON
)


target_link_libraries(
        cpp
        android
        log
)
