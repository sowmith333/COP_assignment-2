#ifndef CLASS_2D_CPP
#define CLASS_2D_CPP

#include "class_2d.h"
#include <iostream>
#include <string>

using namespace std;

// class class_2d{
// 	int id;
// 	class_plane projectionXY;
// 	class_plane projectionYZ;
// 	class_plane projectionZX;

// /**

// * @file LOAD 2D OBJECT
// */



// 	}

// 	bool check_consistency(){
// *

// * @file LOAD 2D OBJECT hellooooo


// //CHECK THE CORRESPONDANCE'S VALIDITY
// 	}

// 	bool reconstructable(){
// 		//CHECKS IF RECONSTRUCTION IS POSSIBLE
// 	}

// 	class_3d reconstruct(){
// 		//RECONSTRUCTS THE OBJECT GIVEN ITS ORTHO- PROJECTIONS
// 	}

// 	void setplanes(class_plane a, class_plane b, class_plane c){
// 		this.projectionXY = a;
// 		this.projectionYZ = b;
// 		this.projectionZX = c;
// 	}
// }

void class_2d::loadxyPlane(string r, string t){
    XY.class_plane::class_planeLoader(r, t);
    //XY.class_plane::printer_points();

}

void class_2d::loadyzPlane(string r, string t){
    YZ.class_plane::class_planeLoader(r, t);
    //YZ.class_plane::printer_points();
}

void class_2d::loadzxPlane(string r, string t){
    ZX.class_plane::class_planeLoader(r, t);
    //ZX.class_plane::printer_points();
}

// void class_2d::a(string a, string b, string c, string d, string e, string f){

// 	loadxyPlane(a, b);
// 	loadyzPlane(c, d);
// 	loadzxPlane(e, f);
// }

// int main(){
// 	// class_2d a("init1.txt","init2.txt","init1.txt","init2.txt","init1.txt","init2.txt");
// 	cout << " hello";

// }
#endif // CLASS_2D_CPP

