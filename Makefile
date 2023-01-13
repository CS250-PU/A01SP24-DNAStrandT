MAKE=make

.PHONY: run valgrindDNAStrand clean

all: run

run:
	${MAKE} -C ./DNAStrand clean
	${MAKE} -C ./DNAStrand
	cd DNAStrand && bin/DNAStrandDriver && cd ..

valgrindDNAStrand:
	${MAKE} -C ./DNAStrand valgrind

clean:
	${MAKE} -C ./DNAStrand clean