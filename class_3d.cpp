#include "class_3d.h"

using namespace std;

const vector<string> explode1(const string& s, const char& c)
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

class_3d::class_3d(string filename1, string filename2, string filename3){

    string line;
    ifstream myfile (filename1);

    if(myfile.is_open()){
        while(getline(myfile, line)){
            std::vector<std::string> splits{explode1(line,' ')};

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
    else
        cout << "UNABLE TO READ FILE 1\n" ;

    ifstream myfile2 (filename2);

    if(myfile2.is_open()){
        while(getline(myfile2, line)){
            std::vector<std::string> splits{explode1(line,' ')};

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
    else
        cout << "UNABLE TO READ FILE 2\n" ;


    ifstream myfile3 (filename3);

    if(myfile3.is_open()){
        while(getline(myfile3, line)){
            std::vector<std::string> splits{explode1(line,' ')};

            int id = atoi(splits[0].c_str());
            // face_array.size();
            int iter = 0;
            int found = 0;

            for( iter = 0 ; iter < face_array.size() ; iter++ ){
                if(face_array[iter].get_id() == iter){
                    found = 1;
                    break ;
                }
            }

            if(found == 1){
                int x = atoi(splits[1].c_str());
                face_array[iter].add_edge(x);
            }

            else{
                class_face a(id);
                int x = atoi(splits[1].c_str());
                a.add_edge(x);
                face_array.push_back(a);
            }
        }
    }
    else
        cout << "UNABLE TO READ FILE 3\n" ;
}

    void class_3d::print_pointArray(){
        vector<class_point> a = point_array;
        for(auto n: a)
            cout << n.class_point::get_id() << " " << n.class_point::get_X() << " " << n.class_point::get_Y() << " " << n.class_point::get_Z() << "\n";
    }

    void class_3d::print_edgeArray(){
        vector<class_line> a = edge_array;
        for(auto n: a)
            cout << n.class_line::get_id() << " " << n.class_line::get_init() << " " << n.class_line::get_fin() << "\n" ;

    }

    void class_3d::print_faceArray(){

        vector<class_face> a = face_array;
        for(auto n: a){
            cout << n.get_id() << "\n" ;
            n.printLines();
        }

    }

    vector<class_point> class_3d::get_points(){
        return point_array;
    }

    vector<class_line> class_3d::get_lines(){
        return edge_array;
    }

    vector<class_face> class_3d::get_faces(){
        return face_array;
    }


// int main(){
// 	class_3d a("init1.txt", "init2.txt", "init3.txt");
// 	a.print_pointArray();
// 	a.print_edgeArray();
// 	a.print_faceArray();
// }
