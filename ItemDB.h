#include "ItemClass.h"
#include <fstream>
class videoGameDB{
public:
void readVideoGame(ifstream &inFile);
void printByPublisher(char userPublisher[]);
void addEntry();
void removeEntry();
void reloadFile();
void saveDatabase(const char fileName[]);
void printDB();
void insert();
videoGameDB();
private:
enum {MAX_VG=100};
videoGame gameList[MAX_VG];
int counter;
};