cmake_minimum_required(VERSION 3.14)

project(QmlMutableDomSample01 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core Qml QmlDomPrivate)

add_executable(QmlMutableDomSample01
  main.cpp
)
target_link_libraries(QmlMutableDomSample01
    Qt6::Core
    Qt6::Qml
    Qt6::QmlDomPrivate
)

install(TARGETS QmlMutableDomSample01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
