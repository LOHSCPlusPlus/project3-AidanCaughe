#include <iostream>
#include "ItemDB.h"
using namespace std;

int main() {
ifstream GameFile("videogames.txt");
  //Setting counter/size 
  videoGameDB gameData;

  int choice = 0;
  //Menu
  while (choice!=8){
    cout << "Welcome to the Videogame Database" << endl;
    cout << "Please enter an input (1-7): " << endl;
    cout << "1. Reload the database from file" << endl;
    cout << "2. Print database" << endl;
    cout << "3. Add new entry" << endl;
    cout << "4. Remove entry" << endl;
    cout << "5. Print all videogames by publisher" << endl;
    cout << "6. Save database to file" << endl;
    cout << "7. Insert and Add" << endl;
    cout << "8. Quit" << endl;
    //Hard Reset
    cin >> choice;
    cout << endl;
    //Reload from file
    if (choice==1){
      gameData.reloadFile();
    }
    //Print Videogame
    else if (choice==2){
    gameData.printDB();
    }
    //adding game
    else if (choice==3){
      gameData.addEntry();
      //adding one more to the possible list in the database
    }
    //Removing entry
    else if (choice==4){
      gameData.removeEntry();
    }
    //Publisher printer
    else if (choice==5){
      char userPublisher[100];
      cout << "Enter a publisher (Examples: Nintendo, Rockstar Games, Activision): ";
        cin >> userPublisher;
      gameData.printByPublisher(userPublisher);
    }
    //Saving to file
    else if (choice==6){
      gameData.saveDatabase("videogames.txt");
    }
    else if (choice==7){
      gameData.insert();
    }
  }
}

