#define D(a) cout << #a "=[" << a <<"] at line ["<<__LINE__<<"]" <<endl;
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
  string fuck="I wanna go home! Take off this uniform and leave the show!";
  D(fuck);
  D(fuck.size());
  D(fuck.length());
  D(fuck.capacity());
  fuck.reserve(500);
  D(fuck.capacity());
  //assert(s==source);
}
