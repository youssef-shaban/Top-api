project(API_lib)

set(HEADER_FILES
        API.h
        Component.h
        Device.h
        json.hpp
        Resistance.h
        terminalScreen.h
        Topology.h
        Transistor.h
        )

set(SOURCE_FILES
        API.cpp
        Component.cpp
        Device.cpp
        Resistance.cpp
        terminalScreen.cpp
        Topology.cpp
        Transistor.cpp
        )

add_library(API_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})