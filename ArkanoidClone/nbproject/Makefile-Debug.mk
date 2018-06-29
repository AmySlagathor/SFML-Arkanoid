#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Bola.o \
	${OBJECTDIR}/Ladrillo.o \
	${OBJECTDIR}/Nave.o \
	${OBJECTDIR}/Rectangulo.o \
	${OBJECTDIR}/arkanoid.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib/i386-linux-gnu /usr/lib/i386-linux-gnu/libsfml-graphics.so /usr/lib/i386-linux-gnu/libsfml-system.so /usr/lib/i386-linux-gnu/libsfml-window.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvp0

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvp0: /usr/lib/i386-linux-gnu/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvp0: /usr/lib/i386-linux-gnu/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvp0: /usr/lib/i386-linux-gnu/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvp0: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvp0 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Bola.o: Bola.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bola.o Bola.cpp

${OBJECTDIR}/Ladrillo.o: Ladrillo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ladrillo.o Ladrillo.cpp

${OBJECTDIR}/Nave.o: Nave.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nave.o Nave.cpp

${OBJECTDIR}/Rectangulo.o: Rectangulo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rectangulo.o Rectangulo.cpp

${OBJECTDIR}/arkanoid.o: arkanoid.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/arkanoid.o arkanoid.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-system.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-window.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-graphics.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvp0

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
