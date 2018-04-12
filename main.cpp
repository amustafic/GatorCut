#include<iostream>
#include<cmath>
#include <string>
#include <fstream>
#include<vector>
#include <sstream>
#include <cmath>
#include <stdlib.h> //needed for atof -> convert string to double
#include "main.h"
using namespace std;

Node::Node(int lon, int lat, string name){
	this->lon=lon;
	this->lat=lat;
	this->name = name;
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

int main(){
    vector <Node*> locations;//vector of node locations
    vector <string> temp;
    vector <string> token;
    vector <vector <int> > adjMatrix;
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
    	locations.push_back(new Node(lon, lat, name));
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
int choice;
while(choice!=4){
cout<<"\n--------------------Choices--------------------\n";
cout<<"1. Directions\n";
cout<<"2. Add Location\n";
cout<<"3. Print Locations\n";
cout<<"4. Exit\n";
cin >> choice;
bool fail = cin.fail();
if(choice > 4 || choice < 1)
                fail = true;
            //validates the user input for being both an integer and in the range of valid input
    while(fail){
        cout<<"Invalid input, please input a whole number between 1 and 2.\n";
         cin.clear();
         cin.ignore(10000, '\n');
         cin>>choice;
         fail = cin.fail();
            if (!fail)
            {
                if (choice >4 || choice <1)
                    {
                        fail = true;
                    }
                }
            }
if(choice==1){
    cout<<"Not yet implemented.\n";
}
else if(choice==2){
        //creates a new node
        double lon;
        double lat;
        string newName;
        cout << "Enter Longtitude.\n";
        cin >> lon;
        cout << "Enter Latitude.\n";
        cin >> lat;
        cout << "Enter location name.\n";
        cin >> newName;
        locations.push_back(new Node(lon, lat, newName));
        cout<<"\nLocation Added\n\n";

    }
else if(choice==3){
//prints locations
for (int i = 0; i < locations.size(); ++i)
{
    cout<< "\nName: "<< locations[i]->getName() << " Longtitude: " <<locations[i]->getLon() << " Latitude: "<< locations[i]->getLat();
}
}
else if(choice == 4){
    return 0;
}
}








    return 0;
}









