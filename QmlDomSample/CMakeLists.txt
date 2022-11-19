cmake_minimum_required(VERSION 3.14)

project(QmlDomSample LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Qml QmlDomPrivate)
find_package(Qt6 REQUIRED COMPONENTS Core Qml QmlDomPrivate)

add_executable(QmlDomSample
  main.cpp
)
target_link_libraries(QmlDomSample Qt6::Core Qt6::CorePrivate Qt6::QmlDomPrivate)

install(TARGETS QmlDomSample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
