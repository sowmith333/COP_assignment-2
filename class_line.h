#ifndef CLASS_LINE_H
#define CLASS_LINE_H

//#include "class_planes.h"
#include "vector"
//!< Class represents a line(between two points)
class class_line{
//private:
public:

    int id; 										//!< id for this line
    int init; 										//!< endpoint1
    int fin; 										//!< endpoint2
    std::vector<int> points; 						//!< list of all points on this line
    std::vector<int> planes; 						//!< list of all planes containing this line



    class_line(int a, int b) ;						//!< Constructor

    bool check_line(int a, int b) ;					//!< checks whether this line exists or not

    void set_id(int a) ;							// Set id func

    int get_id();									// Get id func

    int get_init();									// Return init

    int get_fin();									// Return fin

};

#endif
