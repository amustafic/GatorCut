class Node{

private:
	int x;
	int y;
	string name;

public:
	string getName();
	int getX();
	int getY();
}

void PrintMenu(*Node [] locations);
void addNodeLocation(string name, int x, int y);
string [] Dijkstra(*Node [] locations);
