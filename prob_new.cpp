//#include <iostream>
//#include <vector>
//#include "class_3d.h"
//#include "class_2d.h"

//using namespace std;

//void project(){
//    // vector<class_face> face_array;


//    class_3d a("init1.txt","init2.txt","init3.txt");

//    vector <class_point> z = a.get_points();
//    vector <class_point> proj_pointsXY;
//    vector <class_point> proj_pointsYZ;
//    vector <class_point> proj_pointsZX;
//    vector <class_line> v  = a.get_lines();
//    vector <class_face> f  = a.get_faces();


//    //>>>>>>>>>>>>>>>> XY PROJECTION >>>>>>>>>>>>>>>>>>>>
//    class_point n1(0.0, 0.0, 1.0);
//    n1.set_id(0);

//    // First UNIT vector
//    class_point n2(0.0, 0.0, 1.0);
//    n2 = n2.first_unitVec(n1);
//    n2.set_id(1);

//    // Second UNIT vector
//    class_point n3(0.0, 0.0, 1.0);
//    n3 = n3.second_unitVec(n1);
//    n3.set_id(2);

//    //get_ref(class_point r,class_point u, class_point v);

//    //class_point project_point(class_point r, class_point n)

//    for(auto b:z){
//        // Convert point to its projected form
//        // store it back into the array

//        class_point killer(0.0, 0.0, 0.0);
//        killer = b.project_point(b, n1);

//        //PRINTS POINT <<<< CHECKER >>>>
//        //cout << killer.get_id() << "   " << killer.get_X()<< " " << killer.get_Y() << " " << killer.get_Z() << "\n";

//        class_point inserter(0.0, 0.0, 0.0);
//        inserter = inserter.get_ref(killer, n2, n3);
//        inserter.set_id(b.get_id());

//        proj_pointsXY.push_back(inserter);


//    }

//    //>>>>>>>>>>>>>>>> YZ PROJECTION >>>>>>>>>>>>>>>>>>>>
//    class_point n4(1.0, 0.0, 0.0);
//    n4.set_id(0);

//    // First UNIT vector n5
//    class_point n5(0.0, 0.0, 1.0);
//    n5 = n5.first_unitVec(n4);
//    n2.set_id(1);

//    // Second UNIT vector n6
//    class_point n6(0.0, 0.0, 1.0);
//    n6 = n6.second_unitVec(n4);
//    n6.set_id(2);


//    for(auto b:z){
//        // Convert point to its projected form
//        // store it back into the array

//        class_point killer(0.0, 0.0, 0.0);
//        killer = b.project_point(b, n5);

//        class_point inserter(0.0, 0.0, 0.0);
//        inserter = inserter.get_ref(killer, n5, n6);
//        inserter.set_id(b.get_id());

//        proj_pointsYZ.push_back(inserter);

//    }

//    //>>>>>>>>>>>>>>>> ZX PROJECTION >>>>>>>>>>>>>>>>>>>>
//    class_point n7(0.0, 1.0, 0.0);
//    n7.set_id(0);

//    // First UNIT vector n2
//    class_point n8(0.0, 0.0, 1.0);
//    n8 = n8.first_unitVec(n1);
//    n8.set_id(1);

//    // Second UNIT vector n3
//    class_point n9(0.0, 0.0, 1.0);
//    n9 = n9.second_unitVec(n1);
//    n9.set_id(2);

//    for(auto b:z){
//        // Convert point to its projected form
//        // store it back into the array

//        class_point killer(0.0, 0.0, 0.0);
//        killer = b.project_point(b, n7);

//        class_point inserter(0.0, 0.0, 0.0);
//        inserter = inserter.get_ref(killer, n8, n9);
//        inserter.set_id(b.get_id());

//        proj_pointsZX.push_back(inserter);

//    }

//    // >>>>>>>>>>>>>> PRINT AND CHECK >>>>>>>>>>>>>>>>>>

//}

//void get_3d(){
//    // class_2d obj("xy_points.txt","xy_lines.txt","yz_points.txt","yz_lines.txt","zx_points.txt","zx_lines.txt");

//    // vector<class_point> xy= obj.XY.point_array;
//    // vector<class_point> yz= obj.YZ.point_array;
//    // vector<class_point> zx= obj.ZX.point_array;
//    // vector<class_line> xy_lines=obj.XY.edge_array;
//    // vector<class_line> yz_lines=obj.YZ.edge_array;
//    // vector<class_line> zx_lines=obj.ZX.edge_array;

//    // vector<class_point> d_points;
//    // vector<class_line> d_lines;


//    // for(int i=0;i<xy.size();i++){
//    // 	int p=xy[i].get_id();
//    // 	for(int j=0;j<yz.size();j++){
//    // 		class_point new_point(0.0, 0.0, 0.0);

//    // 		if(p==yz[j].get_id()){

//    // 			new_point.x=xy[i].get_X();
//    // 			new_point.y=xy[i].get_Y();
//    // 			new_point.z=yz[j].get_Z();
//    // 			new_point.id=p;
//    // 			d_points.push_back(new_point);


//    // 		}
//    // 	}
//    // }

//    // for(int i=0;i<xy_lines.size();i++){
//    // 		class_line new_line(0.0, 0.0);
//    // 			new_line.init=xy_lines[i].get_init();
//    // 			new_line.fin=xy_lines[i].get_fin();
//    // 			new_line.id=d_lines.size()+1;
//    // 			d_lines.push_back(new_line);
//    // }
//    // for(int i=0;i<yz_lines.size();i++){
//    // 		class_line new_line(0.0, 0.0);
//    // 			new_line.init=yz_lines[i].get_init();
//    // 			new_line.fin=yz_lines[i].get_fin();
//    // 			new_line.id=d_lines.size()+1;
//    // 			d_lines.push_back(new_line);
//    // }

//    // for (auto n:d_lines){
//    // 	// cout << n.id << " " << n.init << " " << n.fin <<" \n" ;
//    // 	//find the init and fin in isomeric view and draw line between them
//    // }
//    // for(auto n:d_points){
//    // 	//draw these 3d points in the plane of isomeric view
//    // }



//}

//int main(){
//    // project();
//    // get_3d();
//    class_2d obj("xy_points.txt","xy_lines.txt","yz_points.txt","yz_lines.txt","zx_points.txt","zx_lines.txt");

//    vector<class_point> xy= obj.XY.point_array;
//    vector<class_point> yz= obj.YZ.point_array;
//    vector<class_point> zx= obj.ZX.point_array;
//    vector<class_line> xy_lines=obj.XY.edge_array;
//    vector<class_line> yz_lines=obj.YZ.edge_array;
//    vector<class_line> zx_lines=obj.ZX.edge_array;

//    vector<class_point> d_points;
//    vector<class_line> d_lines;


//    for(int i=0;i<xy.size();i++){
//        int p=xy[i].get_id();
//        for(int j=0;j<yz.size();j++){
//            class_point new_point(0.0, 0.0, 0.0);

//            if(p==yz[j].get_id()){

//                new_point.x=xy[i].get_X();
//                new_point.y=xy[i].get_Y();
//                new_point.z=yz[j].get_Z();
//                new_point.id=p;
//                d_points.push_back(new_point);


//            }
//        }
//    }

//    for(int i=0;i<xy_lines.size();i++){
//            class_line new_line(0.0, 0.0);
//                new_line.init=xy_lines[i].get_init();
//                new_line.fin=xy_lines[i].get_fin();
//                new_line.id=d_lines.size()+1;
//                d_lines.push_back(new_line);
//    }
//    for(int i=0;i<yz_lines.size();i++){
//            class_line new_line(0.0, 0.0);
//                new_line.init=yz_lines[i].get_init();
//                new_line.fin=yz_lines[i].get_fin();
//                new_line.id=d_lines.size()+1;
//                d_lines.push_back(new_line);
//    }

//    for (auto n:d_lines){
//        cout << n.id << " " << n.init << " " << n.fin <<" \n" ;
//        //find the init and fin in isomeric view and draw line between them
//    }
//    for(auto n:d_points){
//        //draw these 3d points in the plane of isomeric view
//    }

//}
