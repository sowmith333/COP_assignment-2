#include "class_plane.h"
#include <vector>
#include "iostream"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDebug>

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
}/*
void class_plane::class_planeLoader(string filename1, string filename2){
}*/
void class_plane::class_planeLoader(QString filename1, QString filename2){

//    std::string str = filename1;
//    QString qstr = QString::fromStdString(str);
//    QFile file(qstr);


    QFile file1(filename1);
    QStringList strings;
    QString s;
    if (file1.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        cout << "hello world 1 \n";
        QTextStream in(&file1);
        //in.seek(0);
         do {
            s= in.readLine();
            cout << "hello \n";
            cout << s.toStdString() << "bitch" << "\n";
            strings = s.split(";");
//             strings += in.readLine();
//             qdebug(strings[0].toStdString());
             std::cout << strings[0].toStdString() << strings[0].toStdString().c_str()<< "hi " << std::endl;
            //QString qs;
            // do things
           // std::cout << qs.toStdString() << std::endl;
            cout << "came in \n";
            int id = atoi(strings[0].toStdString().c_str());
            cout << id << " = id\n" ;
//            double x = atof(strings[1].toStdString().c_str());
//            cout << x << " = x\n" ;
//            double y = atof(strings[2].toStdString().c_str());
//            cout << y<< " =y\n" ;
//            double z = atof(strings[3].toStdString().c_str());
//            cout << z << " = z\n" ;

//            class_point buffer_point(x, y, z);
//            buffer_point.set_id(id);
//            point_array.push_back(buffer_point);
        }while(!s.isNull());
    }
    else {
        cout << "UNABLE TO READ FILE 1 QT\n";
    }
    file1.close();



//    std::string str1 = filename2;
//    QString qstr1 = QString::fromStdString(str1);
//    QFile file(qstr);


    QFile file2(filename2);
    QStringList strings1;
    if (file2.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        cout << "hello world 2\n";
        QTextStream in(&file2);
        while (!in.atEnd()) {
            strings1 += in.readLine().split(";");
            //QString qs;
            // do things
           // std::cout << qs.toStdString() << std::endl;
            int id = atoi(strings1[0].toStdString().c_str());
//            cout << id << " = id\n" ;
            double x = atof(strings1[1].toStdString().c_str());
//            cout << x << " = x\n" ;
            double y = atof(strings1[2].toStdString().c_str());
//            cout << y<< " =y\n" ;
            double z = atof(strings1[3].toStdString().c_str());
//            coust << z << " = z\n" ;

            class_point buffer_point(x, y, z);
            buffer_point.set_id(id);
            point_array.push_back(buffer_point);
        }
    }
    else {
        cout << "UNABLE TO READ FILE 2 QT\n";
    }
file2.close();

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
