TARGET = unittest
HEADER = ../cpp-util.h
SOURCE = unittest.cpp ../cpp-util.cpp
CXXFLAG = -std=c++0x
CXXFLAG += -DGTEST_LANG_CXX11=0
LINKFLAG = -l gmock_main -l gmock -l gtest

all : ${TARGET} run

${TARGET}: ${HEADER} ${SOURCE}
	g++ ${CXXFLAG} -o ${TARGET} ${SOURCE} ${LINKFLAG}

run: ${TARGET}
	./${TARGET}

clean:
	rm -f ./${TARGET}
