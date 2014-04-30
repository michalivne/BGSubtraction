CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(BGSUBTRACTION)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# set path to include MacPorts rather thanl local python libraries.
IF(APPLE)
    SET(CMAKE_LIBRARY_PATH /opt/local/lib ${CMAKE_LIBRARY_PATH})

    ADD_DEFINITIONS(
    # C++ flags
        -std=c++11 
        -stdlib=libc++
#        -fno-strict-aliasing
    )
ENDIF (APPLE)

ADD_DEFINITIONS(
# optimization
    -O3 
    -fPIC
# debug 
#    -g
# warnings
    -Wall 
    -Wno-null-conversion 
    -Wno-unused-label 
    -Wno-overloaded-virtual 
    -Wno-deprecated-declarations 
    -Wno-tautological-constant-out-of-range-compare
)


SET(CMAKE_SWIG_FLAGS ${CMAKE_SWIG_FLAGS} "-builtin")

# make global SWIG interface files available
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/swig)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/eigen3)

# add project directories
ADD_SUBDIRECTORY(bgs_library)

# pybgs relies on bgs library
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/bgs_library)
ADD_SUBDIRECTORY(pybgs)
