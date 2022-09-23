.PHONY: all clean

CTARGETS := $(basename $(wildcard *.c))
CXXTARGETS := $(basename $(wildcard *.cpp))
RUSTTARGETS := $(basename $(wildcard *.rs))
GOTARGETS := $(basename $(wildcard *.go))

all : $(CTARGETS) $(CXXTARGETS) $(RUSTTARGETS) $(GOTARGETS)

clean :
	rm $(CTARGETS) $(CXXTARGETS) $(RUSTTARGETS) $(GOTARGETS)

CFLAGS := -std=c17
CXXFLAGS := -std=c++17

% :: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

% :: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

% :: %.rs
	rustc --edition 2021 -O $<

% :: %.go
	go build $<
