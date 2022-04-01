#include "ItemClass.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//Default Constructor
videoGame::videoGame(){
  for (int i = 0; i < MAX_CHAR_LEN; i++){
  name[i] = '\0';
  platform[i] = '\0';
  release[i] = '\0';
  developer[i] = '\0';
  publisher[i] = '\0';
  }
  sales = 0;
}
//Print to File
void videoGame::print(ostream &out){
  out << name << ";" << sales << ";" << platform << ";" << release << ";" << developer << ";" << publisher << endl;
}
//Reading from file
void videoGame::readVG(ifstream &inFile){
    inFile.get(name, videoGame::MAX_CHAR_LEN,';');
    inFile.ignore(100,';');
    inFile >> sales;
    inFile.ignore(100,';');
    inFile.get(platform, videoGame::MAX_CHAR_LEN,';');
    inFile.ignore(100,';');
    inFile.get(release, videoGame::MAX_CHAR_LEN,';');
    inFile.ignore(100,';');
    inFile.get(developer, videoGame::MAX_CHAR_LEN,';');
    inFile.ignore(100,';');
    inFile.get(publisher, videoGame::MAX_CHAR_LEN);
    inFile.ignore(100,'\n');
  }
//Print out data to screen
void videoGame::printVGData(int entrynum){
  cout << "Game Number " << entrynum << endl;
  cout << "Name: " << name << endl;
  cout << "Sales: " << sales << endl;
  cout << "Platform: " << platform << endl;
  cout << "Release Date: " << release << endl;
  cout << "Developer: " << developer << endl;
  cout << "Publisher: " << publisher << endl;
  cout << endl;
}
//Checking if the publisher matches
bool videoGame::publisherMatches(const char user[]){
  if (strcmp(publisher,user) == 0){
    return true;
  }
  return false;
}
//Adding an entry to the database
void videoGame::readFromUser(){
  cout << "Enter Name: ";
  cin.ignore(100,'\n');
  cin.getline(name, videoGame::MAX_CHAR_LEN);
  //Int Checker
  sales = readInt("Enter sales: ");
  cout << "Enter Platforms (if multiple, type Multi-platform): ";
  cin.ignore(100,'\n');
  cin.getline(platform, videoGame::MAX_CHAR_LEN);
  cout << "Enter Release Date in this format (example: January 1, 2005): ";
  cin.getline(release, videoGame::MAX_CHAR_LEN);
  cout << "Enter Developer: ";
  cin.getline(developer, videoGame::MAX_CHAR_LEN);
  cout << "Enter Publisher: ";
  cin.getline(publisher, videoGame::MAX_CHAR_LEN);
  cout << endl;
  }
//Integer Check
int videoGame::readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

