# Locations and default files
INC_DIR = ./include
PREFIX=/usr/local
INCINSTALLDIR=$(PREFIX)/include/g2field/core

install:
	mkdir -p $(INCINSTALLDIR)
	install $(INC_DIR)/*.hh $(INCINSTALLDIR)

