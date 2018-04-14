#ifndef CLASS_POINT_H
#define CLASS_POINT_H

#include <vector>


//!< Class represents a point
class class_point{
    //private:

public:
    int id ;						//!< id of this point
    double x ;						//!< x_coordinate of this point
    double y ;						//!< y_coordinate of this point
    double z ;						//!< z_coordinate of this point
    //std::vector<class_line> edges ;	//!< linked list storing the edges connecting at this point


    class_point(double a, double b, double c) ;								//!< Constructor

    class_point cross_product(class_point x, class_point y) ;				//!< returns the cross product

    class_point normalize(); 												//!< returns the unit vector of the given vector

    class_point get_ref(class_point r,class_point u, class_point v) ;		//!< returns the coordinates of the given point in a plane

    class_point project_point(class_point r, class_point n) ;				//!< projects the point onto the plane whose normal is n

    class_point addVec(class_point a, class_point b) ;						//!< vector addition

    class_point second_unitVec(class_point n);

    class_point first_unitVec(class_point n);

    double dotProduct(class_point a, class_point b) ;						//!< Dot product

    double get_X() ;														//!< returns the x_coordinate

    double get_Y() ;														//!< returns the y_coordinate

    double get_Z() ;														//!< returns the z_coordinate

    void set_id(int id) ;													//!< sets the id of the point

    int get_id() ;														//!< returns the id of the point

    void print_point();
};

#endif
