CC = gcc
CFLAGS = -MMD
EXEC = relay
OBJECTS = main.o config.o run_threads.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	${CC} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
PHONY:clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}