include ../Make.defines

PROGS=	daytimeclient daytimeserver

all:	${PROGS}

daytimeclient:	daytimeclient.o
		${CC} ${CFLAGS} -o $@ daytimeclient.o ${LIBS}

daytimeserver:	daytimeserver.o
		${CC} ${CFLAGS} -o $@ daytimeserver.o ${LIBS}

clean:	
		rm -f ${PROGS} ${CLEANFILES}
               		
