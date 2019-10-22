CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: memoapp

#
# Generates src/ui-resources.c from the UI description files. Run this
# when building the project for the first time and when a UI file is changed.
#
gresources:
	glib-compile-resources \
		src/memoapp.gresource.xml \
		--target src/ui-resources.c \
		--sourcedir=src \
		--generate-source

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo
	@echo "SOURCES: $(SOURCES)"
	@echo

memoapp: $(OBJECTS)
	$(CC) -o $(@F) $(OBJECTS) $(LIBS)
	@echo
	@echo "OBJECTS: $(OBJECTS)"
	@echo

clean:
	rm -f $(OBJECTS)
	rm -f memoapp

