#include "class_line.h"
//#include "class_point.h"
//#include "class_planes.h"
#include <vector>
#include "iostream"
using namespace std;


// class class_line{

// 	int init;
// 	int fin;
// 	vector<class_point> points; //!< list of all points on this line
// 	vector<class_plane> planes; //!< list of all planes containing this line
// }

class_line::class_line(int a, int b){
    //RETURNS A LINE GIVEN TWO POINTS
    init = a;
    fin = b;
}

bool class_line::check_line(int a, int b){
    //GIVEN A LINE CHECKS IF THE LINE EXISTS IN THE DATABASE
    return ((a==init)&&(b==fin)) || ((a==fin)&&(b==init));
}

void class_line::set_id(int a){
    id = a;
}

int class_line::get_id(){
    return id;
}

int class_line::get_init(){
    return init;
}

int class_line::get_fin(){
    return fin;
}

// int main(){
// 	cout<<"hello";
// }
