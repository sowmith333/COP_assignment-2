#include "class_plane.h"
#include <vector>
#include "iostream"
#include <fstream>
#include <string>
#include <stdlib.h>


using namespace std;

const vector<string> explode(const string& s, const char& c)
{
    string buff{""};
    vector<string> v;

    for(auto n:s)
    {
        if(n != c) buff+=n; else
        if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);

    return v;
}

// class class_plane{

// 	int id;
// 	class_point nor;
// 	vector<class_point> point_array ;
// 	vector<class_line> edge_array ;
// 	class_line get_edges_shared(int i){
// 		//GIVEN A POINT CHECKS ITS NEIGHBOURS
// 	}

// }

class_plane::class_plane(double a, double b, double c){
    nor[0] = a;
    nor[1] = b;
    nor[2] = c;
}

void class_plane::set_id(int a){
    id = a;
    return ;
}

void class_plane::class_planeLoader(string filename1, string filename2){
    string line;
    ifstream myfile (filename1);

    if(myfile.is_open()){
        while(getline(myfile, line)){
            std::vector<std::string> splits{explode(line,' ')};

            int id = atoi(splits[0].c_str());
            //cout << id << " = id\n" ;
            double x = atof(splits[1].c_str());
            //cout << x << " = x\n" ;
            double y = atof(splits[2].c_str());
            //cout << y<< " =y\n" ;
            double z = atof(splits[3].c_str());
            //cout << z << " = z\n" ;

            class_point buffer_point(x, y, z);
            buffer_point.set_id(id);
            point_array.push_back(buffer_point);
        }
    }
    else{
        cout << "UNABLE TO READ FILE 1\n" ;
    }

    ifstream myfile2 (filename2);

    if(myfile.is_open()){
        while(getline(myfile2, line)){
            std::vector<std::string> splits{explode(line,' ')};

            int id = edge_array.size();
            //cout << "Here no problem \n" ;
            //cout << "id " << id << "\n";
            int x = atoi(splits[0].c_str());
            //cout << "x " << x << "\n";
            int y = atoi(splits[1].c_str());
            //cout << "y " << y << "\n";

            class_line buffer_edge(x, y);
            buffer_edge.set_id(id);
            edge_array.push_back(buffer_edge);
        }
    }
    else{
        cout << "UNABLE TO READ FILE 2\n" ;
    }

}


void class_plane::set_edges(vector<class_line> v){
    edge_array = v;
    return ;
}

double* class_plane::get_normal(){
    return nor;
}

void class_plane::add_edge(class_line a){
    edge_array.push_back(a);
    return ;
}

void class_plane::add_point(class_point a){
    point_array.push_back(a);
    return ;
}

class_point class_plane::get_ith(int i){
    //RETURNS ith POINT
    point_array[i];
}

void class_plane::printer_points(){

    vector<class_point> buffer = point_array;

    for(auto n:buffer){
        cout << n.get_id() << " " << n.get_X() << n.get_Y() << n.get_Z() << "\n";
    }
}

// void class_plane::set_pointsANDlines




// int main(){

// 	class_plane prob(0.0, 0.0, 1.0);
// 	prob.printer_points();

// 	prob.class_planeLoader("init1.txt","init2.txt");




// }
