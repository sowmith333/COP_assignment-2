#include <iostream>
#include "class_face.h"

using namespace std;

class_face::class_face(int a){
    id = a;
}

void class_face::add_edge(int id_line){
    lines.push_back(id_line);
}

void class_face::printLines(){
    vector<int> a = lines;
    for(auto b:a){ cout << "\t" << b << "\n" ;}

    // cout << a[0];
}

int class_face::get_id(){
    return id;
}

// int main(){
// 	cout<<"hello";
// }
