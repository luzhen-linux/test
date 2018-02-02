SRCS = $(wildcard [0-9]*.cpp)
OBJS = $(patsubst %.cpp,%,$(SRCS))

CXXFLAGS = -g -DTEST -std=gnu++11

all: $(OBJS)

%:%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

#	@for a in $(OBJS); do \
#		echo "g++ -g -std=gnu++11 -o $$a $$a.cpp"; \
#		g++ -g -DTEST -std=gnu++11 -o $$a $$a.cpp; \
#	done

#g++ -g -std=gnu++11 -o 1 1.cpp
#g++ -g -std=gnu++11 -o 719a 719a.cpp
#g++ -g -std=gnu++11 -o 719b 719b.cpp
