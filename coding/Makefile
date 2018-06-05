CC = g++-8
CC_FLAGS = -Wall -std=c++11 -O2 -lm

all: template.cc $(run) $(shell echo $(run) | sed 's/\([a-z0-9]*\).*/\1/')
ifneq ($(run),)
	time ./$(shell echo $(run) | sed 's/\([a-z0-9]*\).*/\1/') < $(run)
else ifneq ($(new),)
	cp template.cc $(new).cc
	touch $(new).in
endif

%: %.cc
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	find . -not -iname "Makefile" -not -iname "*.cc" -delete

clean-all:
	find . -not -iname "Makefile" -not -iname "template.cc" -delete
