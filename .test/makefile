TARGET = unittest
HEADER = ../cpp-util.h
SOURCE = unittest.cpp ../cpp-util.cpp
CXXFLAG = -std=c++0x
CXXFLAG += -DGTEST_LANG_CXX11=0
LINKFLAG = -l gmock_main -l gmock -l gtest

all : ${TARGET} run ascii2bin

${TARGET}: ${HEADER} ${SOURCE}
	g++ ${CXXFLAG} -o ${TARGET} ${SOURCE} ${LINKFLAG}

run: ${TARGET}
	./${TARGET}

clean:
	rm -f ./${TARGET}

ascii2bin : ../cpp-util.h ../cpp-util.cpp ascii2bin.cpp
	g++ ${CXXFLAG} -o $@ ../cpp-util.cpp ascii2bin.cpp
	./ascii2bin test
