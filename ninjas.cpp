#include <iostream>
#include <string>

using namespace std;

const string NINJA = "&";
const string TILE = "_";

void printNinjasPositions(int size)
{
  if(size < 5)
  {
    cout << "Too small!" << endl;
    return;
  }

  for(int i = 1; i < size - 1; i++) //for each combination 
  {
    string floor = (size, TILE);
    floor[i] = NINJA;

    for(int j = i + 2; j < size -1; j++) //for every 2nd ninja
    {
      floor[j] = NINJA;
      cout << floor << endl;
    }
  }

}

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    cerr << "Usage: " + argv[0] + " floor size";
    exit(1);
  }

  int floorSize = stoi(argv[1]);

  printNinjasPositions(floorSize);

  return 0;


}
