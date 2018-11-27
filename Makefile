LIBS:=`root-config --libs`
INCS:=`root-config --cflags`
GLIBS:=`root-config --glibs`
CPP:=g++
EXEC:=Millikan

all: ${EXEC}

${EXEC}: ${EXEC}.cxx funzioni.o class.o
	${CPP} ${EXEC}.cxx funzioni.o class.o ${LIBS} ${INCS} ${GLIBS} -o ${EXEC}
funzioni.o: funzioni.h funzioni.cxx
	${CPP} -c funzioni.cxx ${LIBS} ${INCS} ${GLIBS} -o funzioni.o
class.o: class.h class.cxx 
	${CPP} -c class.cxx -o class.o

clean:
	rm -f *.o
	rm -f core

