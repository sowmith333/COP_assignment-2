#ifndef CLASS_2D_H
#define CLASS_2D_H

//#include "class_line.h"
#include "class_plane.h"
#include <string>
#include <fstream>
#include <iostream>
#include<vector>

using namespace std ;

//!< class representing a 2d_body
class class_2d{

//private:

public:

    class_plane XY, YZ, ZX;
    vector<class_point> point_array_xy,point_array_yz,point_array_xz;
    vector<class_line>  edge_array_xy,edge_array_yz,edge_array_xz;
//vector<string> explode2(string& s,char& c);

    class_2d(string a, string b, string c, string d, string e, string f):
        XY(0.0, 0.0, 1.0), YZ(1.0, 0.0, 0.0), ZX(0.0, 1.0, 0.0)
{
                loadxyPlane(a, b);
                loadyzPlane(c, d);
                loadzxPlane(e, f);
        }

    //void initializer();
    vector<string> explode2(string& s,char& c);
    bool check_consistency() ; 								//!< check whether the given projection is valid or not

    bool reconstructable() ;								//!< checking whether reconstruction is possible or not

//	class_3d reconstruct() ;								//!< if reconstructable, reconstructing the object


vector<class_point> get_xy_points(string a,string b);
vector<class_point> get_yz_points();
vector<class_point> get_xz_points();
vector<class_line> get_xy_lines();
vector<class_line> get_yz_lines();
vector<class_line> get_xz_lines();

    void loadxyPlane(string file1, string file2) ;			// Loader of plane xy

    void loadyzPlane(string file1, string file2) ;			// Loader of plane yz

    void loadzxPlane(string file1, string file2) ;
    //void a(string a, string b, string c, string d, string e, string f);		// Loader of plane zx
};

#endif
