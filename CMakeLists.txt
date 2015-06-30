
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT( ParticleEditor )

SET(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")

#设置输出路径
SET(OUTPUT_BINDIR ${PROJECT_BINARY_DIR}/bin)
SET(OUTPUT_LIBDIR ${PROJECT_BINARY_DIR}/lib)


FOREACH(CONF ${CMAKE_CONFIGURATION_TYPES})        # For each configuration (Debug, Release, MinSizeRel... and/or anything the user chooses)
	STRING(TOUPPER "${CONF}" CONF)                # Go uppercase (DEBUG, RELEASE...)
	SET("CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_LIBDIR}")
	SET("CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_BINDIR}")
	IF(MSVC)
		SET("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_BINDIR}")
	ELSE(MSVC)
		SET("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF}" "${OUTPUT_LIBDIR}")
	ENDIF(MSVC)
ENDFOREACH()

#CMake包
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}")

FIND_PACKAGE(Qt4)
FIND_PACKAGE(OSG)
FIND_PACKAGE(OSGANIMATION)
FIND_PACKAGE(OSGFX)
FIND_PACKAGE(OSGTEXT)
FIND_PACKAGE(OSGDB)
FIND_PACKAGE(OSGGA)
FIND_PACKAGE(OSGVIEWER)
FIND_PACKAGE(OSGPARTICLE)
FIND_PACKAGE(OSGUTIL)
FIND_PACKAGE(OSGSIM)
FIND_PACKAGE(OSGMANIPULATOR)
FIND_PACKAGE(OSGQT)
FIND_PACKAGE(OPENTHREADS)

FIND_PATH(OSG_GEN_DIR include/osg/Referenced)

#文件包含路径
SET(ParticleEditor_DIR ${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(
	${ParticleEditor_DIR}/include
	${QT_INCLUDE_DIR}
	${OSG_GEN_DIR}/include
	)

#依赖库
LINK_DIRECTORIES(
	${QT_LIBRARY_DIR}
	${OSG_GEN_DIR}/lib
	)

#Qt moc
FILE(GLOB ALL_HEADER include/*.h)
QT4_WRAP_CPP(MOC_SOURCES ${ALL_HEADER})

#设置源码
SET(ParticleEditor_TARGET_H
	include/MainWindow.h
	include/OsgScene.h
	include/OsgWidget.h
	include/SquareGrid.h

	)

SET(ParticleEditor_TARGET_SRC
	src/main.cpp
	src/MainWindow.cpp
	src/OsgScene.cpp
	src/OsgWidget.cpp
	src/SquareGrid.cpp
	)

ADD_EXECUTABLE(ParticleEditor
	${ParticleEditor_TARGET_H}
	${ParticleEditor_TARGET_SRC}
	)

TARGET_LINK_LIBRARIES( ParticleEditor
    debug qtmaind       optimized qtmain
    debug QtCored4      optimized QtCore4
    debug QtGuid4       optimized QtGui4
    debug QtOpenGLd4    optimized QtOpenGL4

    debug osgd          optimized osg
    debug osgDBd        optimized osgDB
    debug osgGAd        optimized osgGA
    debug osgViewerd    optimized osgViewer
    debug osgQtd	optimized osgQt
)

SET_TARGET_PROPERTIES( ParticleEditor PROPERTIES "ARCHIVE_OUTPUT_DIRECTORY" "${OUTPUT_LIBDIR}" )
SET_TARGET_PROPERTIES( ParticleEditor PROPERTIES "RUNTIME_OUTPUT_DIRECTORY" "${OUTPUT_BINDIR}" )
SET_TARGET_PROPERTIES( ParticleEditor PROPERTIES "LIBRARY_OUTPUT_DIRECTORY" "${OUTPUT_LIBDIR}" )

