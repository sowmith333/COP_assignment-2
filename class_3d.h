#ifndef CLASS_3D_H
#define CLASS_3D_H

#include "class_face.h"
#include "class_plane.h"
#include "class_point.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;
//!< class representing a 3d_body
class class_3d{

public:
    int id; 																		//!< id of the object
    vector<class_point> point_array;												//!< list of all points of the 3d body
    vector<class_line> edge_array;													//!< list of all edges
    vector<class_face> face_array;													//!< list of all faces

    class_3d(string a, string b, string c);											// READS POINTS, LINES, SOLID SURFACES

    void print_pointArray();														// Point array printer

    void print_edgeArray();															// Edge array printer

    void print_faceArray();															// Face array printer

    vector<class_point> get_points();												// Return Get Points

    vector<class_line> get_lines();													// Return Get Lines

    vector<class_face> get_faces();													// Return Get Faces
};

#endif
