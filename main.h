#include <string>
#include <math.h>
#define PI 3.14159265

using namespace std;

class Node{

private:
	double lon;
	double lat;
	string name;
	vector <Node*> neighbors;
	vector <double> distances;

public:
	string getName();
	double getLon();
	double getLat();
	vector <Node*> getNeighbors();
	vector <double> getDistances();
	void pushNeighbors(Node* neighbor);
	void pushDistances(double distance);
	Node(int lon, int lat, string name, vector <Node*> neighbors, vector <double> distances);
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

double getDist(double lonOne, double latOne, Node* secondNode){
	double deltaLat = latOne - secondNode->getLat();
  	double deltaLon = lonOne - secondNode->getLon();
  	//haversine formula
  	double a = sin(deltaLat*PI/360)*sin(deltaLat*PI/360) + cos(latOne) * cos(secondNode->getLat()) * sin(deltaLon*PI/360)*sin(deltaLon*PI/360);
  	double c = 2 * atan2(sqrt(a),sqrt(1-a));
  	double d = c * 6371000;
    return d;
}

/*void PrintMenu(*Node [] locations);
void addNodeLocation(string name, int x, int y);
string [] Dijkstra(*Node [] locations);
*/
