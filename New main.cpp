#include <iostream>
#include "MovieTree.h"
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    MovieTree MT;
    ifstream inFile;
    string data;
    inFile.open(argv[1]);
    while (getline(inFile,data))
    {
        stringstream ss(data);
        string word;
        getline(ss,word,',');
        int ranking;
        istringstream(word)>>ranking;
        getline(ss,word,',');
        string title=word;
        getline(ss,word,',');
        int releaseYear;
        istringstream(word)>>releaseYear;
        getline(ss,word,',');
        int quantity;
        istringstream(word)>>quantity;
        MT.addMovieNode(ranking,title,releaseYear,quantity);
    }
    MT.menu();
    int selection;
    cin>>selection;
    while (selection!=4)
    {
        if (selection==1)
        {
            string title;
            cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin,title);
            MT.findMovie(title);
            MT.menu();
            cin>>selection;
        }
        else if (selection==2)
        {
            string title;
            cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin,title);
            MT.rentMovie(title);
            MT.menu();
            cin>>selection;
        }
        else if (selection==3)
        {
            MT.printMovieInventory();
            MT.menu();
            cin>>selection;
        }
        else{
            cout << "Command not recognized, please try again" << endl;
            cin.ignore();
            MT.menu();
            cin>>selection;
        }
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}
