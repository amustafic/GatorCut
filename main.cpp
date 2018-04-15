#include<iostream>
#include<cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include<vector>
#include <sstream>
#include <cmath>
#include <stdlib.h> //needed for atof -> convert string to double
#include "main.h"
using namespace std;

Node::Node(double lon, double lat, string name, vector <Node*> neighbors, vector <double> distances){
	this->lon=lon;
	this->lat=lat;
	this->name = name;
    this->neighbors=neighbors;
    this->distances=distances;
}

string Node::getName(){
	return this->name;
}

double Node::getLon(){
	return this->lon;
}

double Node::getLat(){
	return this->lat;
}

vector <Node*> Node::getNeighbors(){
    return this->neighbors;
}

void Node::pushNeighbors(Node* neighbor){
    this->neighbors.push_back(neighbor);
}

vector <double> Node::getDistances(){
    return this->distances;
}

void Node::pushDistances(double distance){
    this->distances.push_back(distance);
}

vector<string> createTokens(string s){
//    std::cout<<s<<endl;
    vector <string> lineVector;
    string temp="";
    for (int i=0; i<s.length();i++){
        char c = s[i];
 //       std::cout<<c<<" "<<endl;
//        if(c==' '){
//            continue;
//        }
        if(c != ','){
            temp+=c;
           //std::cout<<temp<<endl;
        }
        else{
//            if(temp != " " && !temp.empty()){
//                std::cout<<"THISIS"<<temp<<endl;
               lineVector.push_back(temp);
//            }
            //overload operator
              //I commented out because I think its easier/more efficent without the commas
            /*string jk;
            stringstream ss;
            ss << c;
            ss >> jk;
            lineVector.push_back(jk);*/
            temp = "";
        }
    }
    return lineVector;
}

//checks to see if a string matches the name of a node in the locations vector, changed the value of index to the index where a match is found
bool locationNameExists(string checkCase, vector <Node*> locations, int & index){
    for(int i=0; i<locations.size(); i++){
        if(checkCase==locations[i]->getName())
            index = i;
            return true;
    }
    return false;
}
//checks to see if a string matches the name of a node in the locations vector
bool locationNameExists(string checkCase, vector <Node*> locations){
    for(int i=0; i<locations.size(); i++){
        if(checkCase==locations[i]->getName())
            return true;
    }
    return false;
}

int main(){

    vector <Node*> locations;//vector of node locations
    vector <string> temp;
    vector <string> token;
    vector <vector <int> > adjMatrix;
    vector <Node*> neighborsPassToNode;
    vector <double> distancesPassToNode;
    int lines = 0;
    string filename = "map.txt";

    ifstream infile(filename);
	//    infile.open(filename);
    string str;
    while(getline(infile,str)){
        temp = createTokens(str);
        lines++;
        for(int i=0; i<temp.size();i++){
            //if (temp[i] != ","){
                token.push_back(temp[i]);
           // }
    }
    }
    //tests token vector
    /*for(auto p: token){
        std::cout<<p<<endl;
    }*/
    //iterates through the token list and creates a Node for each one specified
    string name;
    double lon;
    double lat;
    int iter = 0;	
    //each line correlates to a new node so each loop creates a node
    for(int i = 1; i <= lines; i++){
    	name = token[iter];
    	iter++;
    	lon = atof(token[iter].c_str()); //converts string to double
    	iter++;
    	lat= atof(token[iter].c_str());
    	if(i!=lines)
    		iter++;
    	locations.push_back(new Node(lat, lon, name, neighborsPassToNode, distancesPassToNode));
    }
    //prints out to test the Node locations vector
    /*for(int i= 0; i<locations.size(); i++){
    	cout<< locations[i]->getlon();
    	cout<< locations[i]->getY();
    	cout<< locations[i]->getName();
    }*/

    string adjacencyFileName = "adj.txt";
    //clears token vector for reuse
    token.clear();
    ifstream afile(adjacencyFileName);
    while(getline(afile,str)){
        temp = createTokens(str);
        for(int i=0; i<temp.size();i++){
            //if (temp[i] != ","){
                token.push_back(temp[i]);
           // }
        }
    }
    vector <int> nodeAdj;
    iter = 0;
    //iterates through the token list, knowing each line should have a number of 1s/0s/-1s equal to the locations.size()
    //which is equal to the number of lines in map.txt
    //pushes the 1D vector that corresponds to a node into the 2D vector that holds adjcacency for all nodes
    for(int i = 1; i <= lines; i++){
        for(int j = 0; j<lines; j++){
            nodeAdj.push_back(atoi(token[iter].c_str()));
            iter++;
        }
        adjMatrix.push_back(nodeAdj);
        nodeAdj.clear();
    }
    //tests adjMatrix
    /*for(int x=0;x<adjMatrix.size();x++)  
    {
        for(int y=0;y<adjMatrix[x].size();y++)  
        {
            cout<<adjMatrix[x][y]; 
        }
    cout<<endl;  
    }*/

for(int i = 0; i < lines; i++){
    
    for(int j = 0; j<lines; j++){
        if(adjMatrix[i][j]==1){
            locations[i]->pushNeighbors(locations[j]);
            locations[i]->pushDistances(getDist(locations[i]->getLat(), locations[i]->getLon(), locations[j]->getLat(), locations[j]->getLon()));
        }

    }

}
//prints neighbors
/*for(int i=0;i<lines;i++)  
    {
        for(int j=0;j<locations[i]->getNeighbors().size();j++)  
        {
            cout<<locations[i]->getNeighbors()[j]->getName(); 
        } 
    }
*/

cout << "\n\n" << getDist(29.64780, -82.34256, 29.65150, -82.34383) << "\n\n\n";



int choice;
while(choice!=6){
cout<<"\n--------------------Choices--------------------\n";
cout<<"                 1. Directions\n";
cout<<"                2. Add Location\n";
cout<<"               3. Print Locations\n";
cout<<"                5. Database test\n";
cout<<"                    6. Exit\n\n";
cin >> choice;
bool fail = cin.fail();
if(choice > 6 || choice < 1)
                fail = true;
            //validates the user input for being both an integer and in the range of valid input
    while(fail){
        cout<<"Invalid input, please input a whole number between 1 and 6.\n";
         cin.clear();
         cin.ignore(10000, '\n');
         cin>>choice;
         fail = cin.fail();
            if (!fail)
            {
                if (choice >6 || choice <1)
                    {
                        fail = true;
                    }
                }
            }

if(choice==1){
    cout<<"Not yet implemented.\n";
}

else if(choice==2){
        cout << fixed << showpoint;
        cout << setprecision(5);
        double lon;
        double lat;
        string newName;
        int neighborChoice;
        string neighName;
        int neighIndex;
        cout << "\nEnter Longtitude.\n";
        cin >> lon;
        while(cin.fail()){
            cout << "Enter a longtitude number.\n";
            cin >>lon;
        }
        cout << "Enter Latitude.\n";
        cin >> lat;
        while(cin.fail()){
            cout << "Enter a latitude number.\n";
            cin >>lat;
        }
        cout << "Enter location name.\n";
        cin >> newName;
        while(locationNameExists(newName, locations)){
            cout << "Location name already exists. Please enter a different name.\n";
            cin >> newName;
        }
        cout << "Enter the number of neighbors.\n";
        cin >> neighborChoice;
        bool fail = cin.fail();
        if(neighborChoice > locations.size())
            fail = true;
        while(fail){
            cout << "Enter a whole number that is less than the number of locations.\n";
            cin >>neighborChoice;
            if(!cin.fail() && neighborChoice < locations.size())
                fail = false;
        }
        while(neighborChoice>0){
            cout << "Enter neighbor name.\n";
            cin >> neighName;
            while(!locationNameExists(neighName, locations, neighIndex)){
                cout << "Neighbor name does not exist, please check spelling and list of neighbors and try again or enter Quit.\n";
                cin >> neighName;    
                if(neighName=="Quit")
                    break;

            }
            //doesnt word really
            neighborsPassToNode.push_back(locations[neighIndex]);
            distancesPassToNode.push_back(getDist(lon, lat, locations[neighIndex]));
            neighborChoice--;
        }
        
        locations.push_back(new Node(lon, lat, newName, neighborsPassToNode, distancesPassToNode));
        bool added = false;
        //vector for the adjacency of the new node, which will be pushed to adjMatrix
        vector <int> newLocationAdjacency;


        for (int i = 0; i < locations.size(); ++i){
              for(int j = 0; j< neighborsPassToNode.size(); j++){
                if (neighborsPassToNode[j]==locations[i])
                {   
                    //pushes 1 to both the vector of the neighbor in adjMatrix and to newLocationAdjaceny if the Nodes match
                    adjMatrix[i].push_back(1);
                    newLocationAdjacency.push_back(1);
                    added = true;
                }
              }
              //pushes -1 if its not a neighbor
              if(!added && i!=locations.size()-1){
                adjMatrix[i].push_back(-1);
                newLocationAdjacency.push_back(-1);
              }
            added = false;
        }
        
        //pushes 0 for self to the vector for the new node
        newLocationAdjacency.push_back(0);
        //pushes the int vector for the new node onto adjMatrix
        adjMatrix.push_back(newLocationAdjacency);

     /*   for(int x=0;x<adjMatrix.size();x++)  
        {
            for(int y=0;y<adjMatrix[x].size();y++)  
            {
                cout<<adjMatrix[x][y]; 
             }
             cout << "\n";
        }
    cout<<endl; */ 
        neighborsPassToNode.clear();
        distancesPassToNode.clear();
        cout<<"\nLocation Added\n\n";



    }
else if(choice==3){
for (int i = 0; i < locations.size(); ++i)
{
    cout<< "\nName: "<< locations[i]->getName() << " Longtitude: " <<locations[i]->getLon() << " Latitude: "<< locations[i]->getLat();
}
}
else if(choice == 5){
    cout << "\nLocations:\n";
    for (int i = 0; i < locations.size(); ++i)
    {
        cout << " -> " << locations[i]->getName();
            for(int j = 0; j< locations[i]->getNeighbors().size(); j++){
                cout << "\n    ->  Neighbor: " << locations[i]->getNeighbors()[j]->getName();
                 cout << fixed << showpoint;
                cout << setprecision(5);
                cout << "\n    ->  Distance: " << locations[i]->getDistances()[j];
            }
            cout << "\n\n";
    }
}
else if(choice == 6){
    return 0;
}
}








    return 0;
}









