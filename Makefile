CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: main

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo
	@echo "SOURCES: $(SOURCES)"
	@echo

main: $(OBJECTS)
	$(CC) -o $(@F) $(OBJECTS) $(LIBS)
	@echo
	@echo "OBJECTS: $(OBJECTS)"
	@echo

clean:
	rm -f $(OBJECTS)
	rm -f main

