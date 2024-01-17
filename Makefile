AR = ar
CXX = g++
CXXFLAGS = -std=c++2a -Wall -O2 -march=x86-64 -fno-rtti
LDFLAGS = -s -static -ladvapi32

SRC = Fnv.cpp Fxms.cpp Rand.cpp Rc4.cpp Shuffler.cpp
OBJ = $(SRC:.cpp=.o)
DEST = Fxms.a
TEST_SRC = FxmsTest.cpp
TEST_DEST = FxmsTest.exe

build: $(OBJ)
	$(AR) r -o $(DEST) $^

build-test: build
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(DEST) -o $(TEST_DEST) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(DEST) $(TEST_DEST)
