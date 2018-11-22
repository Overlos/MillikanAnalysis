LIBS:=`root-config --libs`
INCS:=`root-config --cflags`
GLIBS:=`root-config --glibs`
CPP:=g++
EXEC:=Millikan

all: ${EXEC}

${EXEC}: ${EXEC}.cxx funzioni.o
	${CPP} ${EXEC}.cxx funzioni.o ${LIBS} ${INCS} ${GLIBS} -o ${EXEC}
funzioni.o: funzioni.h funzioni.cxx
	${CPP} -c funzioni.cxx -o funzioni.o

clean:
	rm -f *.o
	rm -f core
