ANTLR := java -jar /usr/local/lib/antlr-4.7.1-complete.jar
CC := g++
CFLAGS := -g -Wall -std=c++11

LIBRARIES_DIR := lib
OBJECTS_DIR := obj
SOURCES_DIR := src
INCLUDES_DIR := $(SOURCES_DIR)/includes
GRAMMARS_DIR := $(SOURCES_DIR)/grammar
ANTLR_RUNTIME_DIR := $(INCLUDES_DIR)/antlr-runtime

HEADER_EXT := h
SOURCE_EXT := cpp
GRAMMAR_EXT := g4

ANTLR_LIBRARY := $(LIBRARIES_DIR)/libantlr4-runtime.a
GRAMMARS := $(shell find $(SOURCES_DIR) -type f -name *.$(GRAMMAR_EXT))
SOURCES := $(shell find $(SOURCES_DIR) -type f -name *.$(SOURCE_EXT))
OBJECTS := $(patsubst $(SOURCES_DIR)/%,$(OBJECTS_DIR)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

TARGET := bin/freud

$(TARGET): $(OBJECTS)
	$(MAKE) grammar
	@echo "  Linking $(TARGET)..."
	@mkdir -p $(dir $(TARGET))
	@echo "    $(CC) $^ $(ANTLR_LIBRARY) -o $(TARGET)"; $(CC) $^ $(ANTLR_LIBRARY) -o $(TARGET)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.$(SOURCE_EXT)
	@echo "  Compiling $<..."
	@mkdir -p $(dir $(OBJECTS))
	@echo "    $(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(ANTLR_RUNTIME_DIR) -c -o $@ $<"; $(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(ANTLR_RUNTIME_DIR) -c -o $@ $<

grammar: $(GRAMMARS)
	@echo "  Generating grammar"
	@echo "    $(ANTLR) -Dlanguage=Cpp $^"; $(ANTLR) -Dlanguage=Cpp $^
	@echo "    mv $(GRAMMARS_DIR)/*.$(HEADER_EXT) $(INCLUDES_DIR)"; mv $(GRAMMARS_DIR)/*.$(HEADER_EXT) $(INCLUDES_DIR)
	@echo "    $(RM) $(GRAMMARS_DIR)/*.tokens"; $(RM) $(GRAMMARS_DIR)/*.tokens
	@echo "    $(RM) $(GRAMMARS_DIR)/*.interp"; $(RM) $(GRAMMARS_DIR)/*.interp

clean:
	@echo "  Cleaning...";
	@echo "    $(RM) -r $(OBJECTS_DIR) $(TARGET)"; $(RM) -r $(OBJECTS_DIR) $(TARGET)
