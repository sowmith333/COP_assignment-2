CXX=g++ -std=c++11
LFLAGS        = -m64
CXXFLAGS      = -m64 -pipe -O2 -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LIBS          = -L/usr/lib/x86_64-linux-gnu/ -lm -lQtGui
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB
OBJECTS       = prob.o
# TARGET        = prob


# prob: $(OBJS)
# 	g++ -o prob prob.o class_2d.o class_3d.o
prob: prob.cpp 
	# $(CXX) -c $< $(CXXFLAGS) $(INCPATH)
	g++ -std=c++11 prob.cpp class_line.cpp class_point.cpp class_2d.cpp class_3d.cpp class_face.cpp class_plane.cpp
# class_point.o: class_point.cpp class_point.h
# 	$(CXX) -c $< $(CXXFLAGS) $(INCPATH)
# class_plane.o: class_plane.cpp class_plane.h class_line.h class_point.h
# 	$(CXX) -c $< $(CXXFLAGS) $(INCPATH)
# class_line.o: class_line.cpp class_line.h
# 	$(CXX) -c $< $(CXXFLAGS) $(INCPATH)
# class_face.o: class_face.cpp class_face.h
# 	$(CXX) -c $< $(CXXFLAGS) $(INCPATH)
# class_3d.o: class_3d.cpp class_3d.h class_plane.h class_point.h class_face.h
# 	$(CXX) -c $< $(CXXFLAGS) $(INCPATH)
# class_2d.o: class_2d.cpp class_2d.h class_plane.h
# 	$(CXX) -c $< $(CXXFLAGS) $(INCPATH)
# prob.o:prob.cpp class_2d.h class_3d.h
$(TARGET):  $(OBJECTS)  
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean

clean: 
	rm -f *.o $(TARGET)
 # g++ -std=c++11 prob.cpp class_line.cpp class_point.cpp class_2d.cpp class_3d.cpp class_face.cpp class_plane.cpp