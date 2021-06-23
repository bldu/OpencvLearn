LEVEL = 3

OPENCV_DIR = /Users/dbl/MyRepo/oopencv/opencv_install

CXX      = c++
CXXFLAGS = -O$(LEVEL) -g -std=c++11 -I$(OPENCV_DIR)/include/opencv4

LD       = c++
LDFLAGS  =
LIBS     = -L$(OPENCV_DIR)/lib -lopencv_core 



SRCS =  mat.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
EXEC = $(patsubst %.cpp,%,$(SRCS))



target: $(OBJS) $(EXEC)

%: %.o
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)



.PHONY:  clean


clean:
	rm -f *.o  $(EXEC)

