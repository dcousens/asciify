CFLAGS=$(shell cat compile_flags.txt)
OFLAGS=-O3

asciify: asciify.cpp
	$(CXX) $(CFLAGS) $(OFLAGS) $< -o $@

clean:
	rm asciify

install: asciify
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f asciify ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/asciify
