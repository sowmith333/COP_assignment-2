#ifndef CLASS_FACE_H
#define CLASS_FACE_H

#include <vector>

using namespace std;

/*!<  class representing Faces*/
class class_face
{
public:
    int id; 								/*!< id for the face*/
    vector<int> lines;  					/*!< vector containing the edges of the face*/

    class_face(int a);						// Class constructor

    void add_edge(int a);					// Adding edges to a face

    void printLines();						// Print all lines

    int get_id();
};

#endif
