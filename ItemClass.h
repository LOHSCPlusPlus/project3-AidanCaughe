#include <fstream>
using namespace std;
class videoGame
{
  public:
  videoGame();
  void readVG(ifstream &inFile);
  void readFromUser();
  void printVGData(int entrynum);
  bool publisherMatches(const char user[]);
  int readInt(const char prompt[]);
  void print(ostream &out);
  private:
  enum {MAX_CHAR_LEN = 100};
  char name[MAX_CHAR_LEN];
  int sales;
  char platform[MAX_CHAR_LEN];
  char release[MAX_CHAR_LEN];
  char developer[MAX_CHAR_LEN];
  char publisher[MAX_CHAR_LEN];
};