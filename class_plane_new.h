#ifndef CLASS_PLANE_H
#define CLASS_PLANE_H

#include "class_line.h"
#include "class_point.h"
#include "string"
#include <vector>
#include <QString>
using namespace std;

//!< Class to represent a plane
class class_plane{
//private:
public:
    int id; 													//!< id of this plane
    double nor [3];												//<! a 3 array to represent the normal to the plane
    vector<class_point> point_array ; 							//<! list of point in the plane
    vector<class_line> edge_array ; 							//<! list of edges in the plane

    class_plane(double a, double b, double v) ;

    void set_id(int a) ;

    void class_planeLoader(QString filename1, QString filename2) ;

    void set_edges(vector<class_line> a) ;

    double* get_normal();

    void add_edge(class_line);

    void add_point(class_point);

    class_point get_ith(int i) ;

    void printer_points();

    vector<class_line> get_edges_shared(int i) ; //<! gives the lines containing this point in the plane

};


#endif
