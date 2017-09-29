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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Mutex.o \
	${OBJECTDIR}/src/PeriodicCaller.o \
	${OBJECTDIR}/src/Semaphore.o \
	${OBJECTDIR}/src/Thread.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wextra
CXXFLAGS=-Wextra

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/librtypes.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/librtypes.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/librtypes.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/librtypes.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/librtypes.a

${OBJECTDIR}/src/Mutex.o: src/Mutex.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Mutex.o src/Mutex.cpp

${OBJECTDIR}/src/PeriodicCaller.o: src/PeriodicCaller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/PeriodicCaller.o src/PeriodicCaller.cpp

${OBJECTDIR}/src/Semaphore.o: src/Semaphore.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Semaphore.o src/Semaphore.cpp

${OBJECTDIR}/src/Thread.o: src/Thread.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Thread.o src/Thread.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
