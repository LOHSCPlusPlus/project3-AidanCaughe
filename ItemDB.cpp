#include "ItemDB.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
//Default Constructor
videoGameDB::videoGameDB(){
  ifstream inFile("videogames.txt");
  readVideoGame(inFile);
}
//Initializing Database
void videoGameDB::readVideoGame(ifstream &inFile){
counter = 0;
  while(inFile.peek()!=EOF && counter<MAX_VG){
    gameList[counter].readVG(inFile);
    counter++;
  }
}
//Print DataBase
void videoGameDB::printDB(){
  for (int i = 0; i < counter; i++){
    gameList[i].printVGData(i);
  }
}
//Printing by the publisher
void videoGameDB::printByPublisher(char userPublisher[]){
  for (int i = 0; i < MAX_VG;i++){
    if (gameList[i].publisherMatches(userPublisher)){
      gameList[i].printVGData(i);
    }
  }
}
//Adding an entry to the database at the end
void videoGameDB::addEntry(){
  //If database full
  bool GameReal = false;
  if (counter <MAX_VG){
  //Checking for valid entry
        cout << "Entering information for Game #" << counter << endl;
  gameList[counter].readFromUser();
  //Setting it to make the game true
  GameReal = true;
    counter++;
    }
  //Checking if gamereal is still false
  if (GameReal == false){
    cout << "The database is full." << endl;
    cout << endl;
  }
  }
//Removing an entry
void videoGameDB::removeEntry(){
  int removeIndex = 0;
  cout << "Remove entry between 0 and 100"<< endl;
  cin >> removeIndex;
  if (removeIndex >= 0 && removeIndex <= counter){
  for (int deleteIndex = removeIndex; deleteIndex < counter; deleteIndex++){
  gameList[deleteIndex] = gameList[deleteIndex + 1];
  }
    //New Size being made
    counter--;
    }
  //Invalid entry
  else {
    cout << "Invalid Entry." << endl;
    cout << endl;
  }
}
//inserting/adding an entry anywhere
void videoGameDB::insert(){
int insertIndex = 0;

  cout << "Insert Entry between 0 and 100" << endl;
  cin >> insertIndex;
  if (insertIndex >=0&&insertIndex<=counter){
    for (int i = counter; i>=insertIndex;i--){
      gameList[i] = gameList[i-1]; 
    }
    gameList[insertIndex].readFromUser();
  }
  counter++;
}
//Reloading from file
void videoGameDB::reloadFile(){
  ifstream gameFile("videogames.txt");
  readVideoGame(gameFile);
  cout << "Database successfully reloaded." << endl;
  cout << endl;
}
//Saving the database to file
void videoGameDB::saveDatabase(const char fileName[]){
 ofstream outFile(fileName);
  //Printing to File
  for (int i = 0; i < counter; i++){
  gameList[i].print(outFile);
  }
  cout << "Database saved.";
  cout << endl; 
}
