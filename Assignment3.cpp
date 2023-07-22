#include <iostream>
using namespace std;

void ref(int r, int & s)
{
  r++;
  s++;
}

int main() {
  int i=1,x=5,y=9;
  while(i<=y)
  {
    int j;
    for (j=1;j<=y-x;j++)
    cout <<'a';
    ref(y,x);
    cout<<endl;
    i=i+1;

  }

return 0;

}
