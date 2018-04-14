#include <math.h>
#include <QtCore>
#include <QtGui>
#include <iostream>
#include <vector>
#include "class_3d.h"
#include "class_2d.h"
#include <QString>

using namespace std;


#define PI 3.1415926536
#define SIZE 200
#define FACTOR 100

//const float STEP = 2*PI/SIZE;

using namespace Qt;
void get_3d(){
//	class_2d obj("xy_points.txt","xy_lines.txt","yz_points.txt","yz_lines.txt","zx_points.txt","zx_lines.txt");

//	vector<class_point> xy= obj.XY.point_array;
//	vector<class_point> yz= obj.YZ.point_array;
//	vector<class_point> zx= obj.ZX.point_array;
//	vector<class_line> xy_lines=obj.XY.edge_array;
//	vector<class_line> yz_lines=obj.YZ.edge_array;
//	vector<class_line> zx_lines=obj.ZX.edge_array;

//	vector<class_point> d_points;
//	vector<class_line> d_lines;


//	for(int i=0;i<xy.size();i++){
//		int p=xy[i].get_id();
//		for(int j=0;j<yz.size();j++){
//			class_point new_point(0.0, 0.0, 0.0);

//			if(p==yz[j].get_id()){

//				new_point.x=xy[i].get_X();
//				new_point.y=xy[i].get_Y();
//				new_point.z=yz[j].get_Z();
//				new_point.id=p;
//				d_points.push_back(new_point);


//			}
//		}
//	}

//	for(int i=0;i<xy_lines.size();i++){
//			class_line new_line(0.0, 0.0);
//				new_line.init=xy_lines[i].get_init();
//				new_line.fin=xy_lines[i].get_fin();
//				new_line.id=d_lines.size()+1;
//				d_lines.push_back(new_line);
//	}
//	for(int i=0;i<yz_lines.size();i++){
//			class_line new_line(0.0, 0.0);
//				new_line.init=yz_lines[i].get_init();
//				new_line.fin=yz_lines[i].get_fin();
//				new_line.id=d_lines.size()+1;
//				d_lines.push_back(new_line);
//	}

//	for (auto n:d_lines){
//		// cout << n.id << " " << n.init << " " << n.fin <<" \n" ;
//		//find the init and fin in isomeric view and draw line between them
//	}
//	for(auto n:d_points){
//		//draw these 3d points in the plane of isomeric view
//	}



}

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   QLabel l;
   QPicture pi;
   QPainter p(&pi);

   p.setRenderHint(QPainter::Antialiasing);
   p.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
//   p.drawLine(0, 0, 200, 200);
QString a1="xy_points.txt";
QString b="xy_lines.txt";
QString a2="yz_points.txt";
QString b1="yz_lines.txt";
QString a3="zx_points.txt";
QString b2="zx_lines.txt";


class_2d obj(a1,b,a2,b1,a3,b2);

   vector<class_point> xy= obj.XY.point_array;
   vector<class_point> yz= obj.YZ.point_array;
   vector<class_point> zx= obj.ZX.point_array;
   vector<class_line> xy_lines=obj.XY.edge_array;
   vector<class_line> yz_lines=obj.YZ.edge_array;
   vector<class_line> zx_lines=obj.ZX.edge_array;

   vector<class_point> d_points;
   vector<class_line> d_lines;
   class_point new_point(3.0,4.0,5.0);
   new_point.print_point();
d_points[0]=new_point;
xy[0].print_point();
   for(int i=0;i<xy.size();i++){
       int p=xy[i].get_id();
       for(int j=0;j<yz.size();j++){
           class_point new_point(0.0, 0.0, 0.0);

           if(p==yz[j].get_id()){

               new_point.x=xy[i].get_X();
               new_point.y=xy[i].get_Y();
               new_point.z=yz[j].get_Z();
               new_point.id=p;
               d_points.push_back(new_point);


           }
       }
   }

   for(int i=0;i<xy_lines.size();i++){
           class_line new_line(0.0, 0.0);
               new_line.init=xy_lines[i].get_init();
               new_line.fin=xy_lines[i].get_fin();
               new_line.id=d_lines.size()+1;
               d_lines.push_back(new_line);
   }
   for(int i=0;i<yz_lines.size();i++){
           class_line new_line(0.0, 0.0);
               new_line.init=yz_lines[i].get_init();
               new_line.fin=yz_lines[i].get_fin();
               new_line.id=d_lines.size()+1;
               d_lines.push_back(new_line);
   }

   for (auto n:d_lines){
//       // cout << n.id << " " << n.init << " " << n.fin <<" \n" ;
//       //find the init and fin in isomeric view and draw line between them
   }
   for(auto n:d_points){
//       //draw these 3d points in the plane of isomeric view
   }
//class_point n=d_points[0];
//        class_point n1=d_points[1];

    p.drawLine(0,0,100,100);

   p.end(); // Don't forget this line!

   l.setPicture(pi);
   l.show();
   return a.exec();
}
