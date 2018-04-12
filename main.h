#include <string>
#include <math.h>
#define PI 3.14159265

using namespace std;

class Node{

private:
	double lon;
	double lat;
	string name;

public:
	string getName();
	double getLon();
	double getLat();
	Node(int lon, int lat, string name);
};

double getDist(Node* firstNode,Node* secondNode){
  
  	double deltaLat = firstNode->getLat() - secondNode->getLat();
  	double deltaLon = firstNode->getLon() - secondNode->getLon();
  	//haversine formula
  	double a = sin(deltaLat*PI/360)*sin(deltaLat*PI/360) + cos(firstNode->getLat()) * cos(secondNode->getLat()) * sin(deltaLon*PI/360)*sin(deltaLon*PI/360);
  	double c = 2 * atan2(sqrt(a),sqrt(1-a));
  	double d = c * 6371000;
    return d;
}
