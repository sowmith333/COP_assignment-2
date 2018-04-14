#include "class_point.h"
#include "math.h"
//#include <class_line.h>
#include <vector>
#include "iostream"
using namespace std;

// class class_point{

// public:
// 	int id;
// 	// CLASS USED TO GENERATE UNIT VECTORS FOR A GIVEN NORMAL OF A PLANE. THE x, y, z CO-ORDINATES ARE
// 	// THE DIRECTION COSINES OF A VECTOR IF ANY.
// 	double x;
// 	double y;
// 	double z;
// 	//UNCOMMENT THIS
// 	//vector<class_line> edges
// };


class_point::class_point(double a, double b, double c){
        //GENERATES A NEW POINT, GIVEN X, Y, Z co-ordinates
        x = a; y = b; z = c;
}

double class_point::get_X(){return x;}

double class_point::get_Y(){return y;}

double class_point::get_Z(){return z;}

void class_point::set_id(int id1){
    id = id1 ;
    return ;
}

int class_point::get_id(){
    return id;
}

class_point class_point::cross_product(class_point x, class_point y){
    // RETURNS THE CROSS PRODUCT VECTOR

    double x_co = x.get_Y()*y.get_Z() - x.get_Z()*y.get_Y() ;
    double y_co = x.get_Z()*y.get_X() - x.get_X()*y.get_Z() ;
    double z_co = x.get_X()*y.get_Y() - x.get_Y()*y.get_X() ;

    class_point ret(x_co, y_co, z_co) ;
    ret.set_id(0);
    ret.normalize();
    return ret ;
}

class_point class_point::normalize(){
    // RETURNS A UNIT VECTOR OF A GIVEN VECTOR
    double len = sqrt(x*x + y*y + z*z) ;
    double tempx = x/len ;
    double tempy = y/len ;
    double tempz = z/len ;

    class_point boom(tempx, tempy, tempz);
    boom.set_id(0);
    return boom;
}

class_point class_point::get_ref(class_point r,class_point u, class_point v){
    // RETURNS THE CO_ORDINATES (a1,a2) OF A GIVEN POINT IN A PLANE.
    if(u.x*v.y - v.x*u.y != 0.0){
        double a2 = (v.y*r.x - v.x*r.y) / (u.x*v.y - v.x*u.y) ;
        double a1 = (u.y*r.x - u.x*r.y) / (v.x*u.y - u.x*v.y) ;
        class_point boom(a1,a2,0);
        return boom;
    }
    else{
        double a1 = (v.z*r.y - v.y*r.z) / (u.y*v.z - v.y*u.z) ;
        double a2 = (u.z*r.y - u.y*r.z) / (v.y*u.z - u.y*v.z) ;
        class_point boom(a1,a2,0);
        return boom;
    }
}

class_point class_point::project_point(class_point r, class_point n){
    // GIVEN A POINT, PROJECTS IT ON TO A PLANE, WHOSE NORMAL IS n
    double Lambda = dotProduct(r,n) ;
    double X = r.x - Lambda*n.x ;
    double Y = r.y - Lambda*n.y ;
    double Z = r.z - Lambda*n.z ;

    // cout << r.x - Lambda*n.x << "\n";
    // cout << r.y - Lambda*n.y << "\n";
    // cout << r.z - Lambda*n.z << "\n";

    class_point ret(X, Y, Z);
    ret.set_id(r.get_id());

    return ret ;
}

class_point class_point::addVec(class_point a, class_point b){
    // VECTOR ADDITION
    double xx;
    double yy;
    double zz;
    xx = a.x + b.x ;
    yy = a.y + b.y ;
    zz = a.x + b.z ;

    class_point c(xx, yy, zz);
    c.set_id(0);
    return c;
}

double class_point::dotProduct(class_point a, class_point b){
    // DOT PRODUCT
    return (a.get_X()*b.get_X() + a.get_Y()*b.get_Y() + a.get_Z()*b.get_Z()) ;
}

class_point class_point::first_unitVec(class_point n){

    if(n.get_X()!= 1.0 && n.get_Y()!=0.0 && n.get_Z()!=0.0){
        class_point a(1.0, 0.0, 0.0) ;
        class_point b(0.0, 0.0, 0.0) ;
        b.set_id(0) ;

        b = b.cross_product(n,a);
        b = b.normalize();
        return b;
    }
    else{
        class_point a(0.0, 1.0, 0.0);

        class_point b(0.0, 0.0, 0.0) ;
        b.set_id(0) ;

        b = b.cross_product(n,a);
        b = b.normalize();
        return b;
    }
}
void class_point::print_point(){
    cout << id << "  " << x << " " << y << " " << z << "\n";
}

class_point class_point::second_unitVec(class_point n){
    class_point n1(0.0, 0.0, 0.0);
    n1.set_id(0);
    n1 = n1.first_unitVec(n);
    class_point n2(0.0, 0.0, 0.0);
    n2.set_id(6);
    n2 = n2.cross_product(n1, n);
    n2 = n2.normalize();

    return n2;
}

// int main(){
// 	class_point a(5.0, 6.0, 3.0);
// 	a.set_id(1);

// 	class_point n(1.0, 0.0, 0.0);
// 	n.set_id(2);

// 	cout << "UNIT VECTOR 1  ";
// 	class_point n2 = a.first_unitVec(n);
// 	n2.print_point();

// 	cout << "UNIT VECTOR 2  ";
// 	class_point n3 = a.second_unitVec(n);
// 	n3.print_point();

// 	cout << "PROJCECTED POINT 2  ";
// 	class_point killer = a.project_point(a, n);
// 	killer.print_point();

// 	a.print_point();

// 	class_point r_1 = a.get_ref(a, n2, n3);
// 	r_1.print_point();
// }
