# Locations and default files
PREFIX=/usr/local
INSTALL_DIR=$(PREFIX)/include/g2field/core

all:

install:
	mkdir -p $(INSTALL_DIR)
	install *.hh $(INSTALL_DIR)

