CC := g++
CFLAGS := -g

SRCDIR := src
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

INCDIR := src/includes

OBJDIR := obj
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

TARGET := bin/freud

$(TARGET): $(OBJECTS)
	@echo "  Linking $(TARGET)..."
	@mkdir -p $(dir $(TARGET))
	@echo "    $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "  Compiling $<..."
	@mkdir -p $(dir $(OBJECTS))
	@echo "    $(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $<"; $(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $<

clean:
	@echo "  Cleaning..."; 
	@echo "    $(RM) -r $(OBJDIR) $(TARGET)"; $(RM) -r $(OBJDIR) $(TARGET)
