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
CND_PLATFORM=GNU-Linux-x86
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
	${OBJECTDIR}/_ext/2068375979/Grafo.o \
	${OBJECTDIR}/_ext/2068375979/LstAdy.o \
	${OBJECTDIR}/_ext/2068375979/Simulador.o \
	${OBJECTDIR}/_ext/2068375979/Visualizador.o \
	${OBJECTDIR}/_ext/2068375979/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/automata-celular

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/automata-celular: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/automata-celular ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/2068375979/Grafo.o: ../../Automata-Celular/Grafo.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/Grafo.o ../../Automata-Celular/Grafo.cpp

${OBJECTDIR}/_ext/2068375979/LstAdy.o: ../../Automata-Celular/LstAdy.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/LstAdy.o ../../Automata-Celular/LstAdy.cpp

${OBJECTDIR}/_ext/2068375979/Simulador.o: ../../Automata-Celular/Simulador.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/Simulador.o ../../Automata-Celular/Simulador.cpp

${OBJECTDIR}/_ext/2068375979/Visualizador.o: ../../Automata-Celular/Visualizador.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/Visualizador.o ../../Automata-Celular/Visualizador.cpp

${OBJECTDIR}/_ext/2068375979/main.o: ../../Automata-Celular/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/main.o ../../Automata-Celular/main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/2068375979/pba_grafo.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/_ext/2068375979/pba_grafo.o: ../../Automata-Celular/pba_grafo.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/2068375979
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/2068375979/pba_grafo.o ../../Automata-Celular/pba_grafo.cpp


${OBJECTDIR}/_ext/2068375979/Grafo_nomain.o: ${OBJECTDIR}/_ext/2068375979/Grafo.o ../../Automata-Celular/Grafo.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2068375979/Grafo.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/Grafo_nomain.o ../../Automata-Celular/Grafo.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2068375979/Grafo.o ${OBJECTDIR}/_ext/2068375979/Grafo_nomain.o;\
	fi

${OBJECTDIR}/_ext/2068375979/LstAdy_nomain.o: ${OBJECTDIR}/_ext/2068375979/LstAdy.o ../../Automata-Celular/LstAdy.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2068375979/LstAdy.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/LstAdy_nomain.o ../../Automata-Celular/LstAdy.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2068375979/LstAdy.o ${OBJECTDIR}/_ext/2068375979/LstAdy_nomain.o;\
	fi

${OBJECTDIR}/_ext/2068375979/Simulador_nomain.o: ${OBJECTDIR}/_ext/2068375979/Simulador.o ../../Automata-Celular/Simulador.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2068375979/Simulador.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/Simulador_nomain.o ../../Automata-Celular/Simulador.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2068375979/Simulador.o ${OBJECTDIR}/_ext/2068375979/Simulador_nomain.o;\
	fi

${OBJECTDIR}/_ext/2068375979/Visualizador_nomain.o: ${OBJECTDIR}/_ext/2068375979/Visualizador.o ../../Automata-Celular/Visualizador.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2068375979/Visualizador.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/Visualizador_nomain.o ../../Automata-Celular/Visualizador.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2068375979/Visualizador.o ${OBJECTDIR}/_ext/2068375979/Visualizador_nomain.o;\
	fi

${OBJECTDIR}/_ext/2068375979/main_nomain.o: ${OBJECTDIR}/_ext/2068375979/main.o ../../Automata-Celular/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2068375979
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2068375979/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2068375979/main_nomain.o ../../Automata-Celular/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2068375979/main.o ${OBJECTDIR}/_ext/2068375979/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/automata-celular

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
