LEVEL = 3

OPENCV_DIR = /Users/dbl/NewEra/NoobToy/OpencvLearn/3rdparty/opencv

CXX      = c++
CXXFLAGS = -O$(LEVEL) -g -std=c++11 -I$(OPENCV_DIR)/include/opencv4
		   

LD       = c++
LDFLAGS  = 
LIBS     = -L$(OPENCV_DIR)/lib -lopencv_world



SRCS =  read_img.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
EXEC = $(patsubst %.cpp,%,$(SRCS))



target: $(OBJS) $(EXEC)

%: %.o
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)



.PHONY:  clean test


test:
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:$(OPENCV_DIR)/lib ./$(EXEC) opencv_read_img.jpg
	#./$(EXEC) opencv_read_img.jpg


clean:
	rm -f *.o  $(EXEC)

