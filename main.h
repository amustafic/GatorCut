#include <string>
using namespace std;
class Node{

private:
	double x;
	double y;
	string name;

public:
	string getName();
	double getX();
	double getY();
	Node(int x, int y, string name);
};

double getDist(Node* c,Node* d){
    double x1= c->getX();
    double x2=d->getX();
    double y1=c->getY();
    double y2=d->getY();

    double xDiff = x1-x2;
    double yDiff = y1-y2;
    double dist= sqrt(pow(xDiff,2)+pow(yDiff,2));
    return dist;
}

/*void PrintMenu(*Node [] locations);
void addNodeLocation(string name, int x, int y);
string [] Dijkstra(*Node [] locations);
*/