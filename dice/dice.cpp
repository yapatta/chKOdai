#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int x,y;
int top[205][205];
int height[205][205];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

// TOP = 0, BOTTOM = 1, ...
enum DiceFace { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };

template <class T> class Dice {
  // a <- b <- c <- d
  void Roll(DiceFace a, DiceFace b, DiceFace c, DiceFace d) {
    int tmp = id[a];
    id[a] = id[b];
    id[b] = id[c];
    id[c] = id[d];
    id[d] = tmp;
  }

public:
  int id[6];
  T val[6];
  const int size = 6;
  Dice() {
    id[TOP] = 0;
    id[FRONT] = 1;
    id[LEFT] = 2;
    id[RIGHT] = 3;
    id[BACK] = 4;
    id[BOTTOM] = 5;
  }

  T &operator[](DiceFace f) {
    return val[id[f]];
  }
  const T &operator[](DiceFace f) const {
    return val[id[f]];
  }

  bool operator==(const Dice<T> &y) const {
    const Dice<T> &x = *this;
    return x[TOP] == y[TOP] and x[FRONT] == y[FRONT] and x[BOTTOM] == y[BOTTOM]
           and x[BACK] == y[BACK] and x[LEFT] == y[LEFT]
           and x[RIGHT] == y[RIGHT];
  }

  // Roll like right hand screw
  // Front <- Top <- Back
  void RollX() {
    Roll(TOP, BACK, BOTTOM, FRONT);
  }
  void RollRetX() {
    Roll(FRONT, BOTTOM, BACK, TOP);
  }
  // Right <- Top <- Left
  void RollY() {
    Roll(RIGHT, TOP, LEFT, BOTTOM);
  }
  void RollRetY() {
    Roll(BOTTOM, LEFT, TOP, RIGHT);
  }
  // Right <- Front <- Left
  void RollZ() {
    Roll(RIGHT, FRONT, LEFT, BACK);
  }
  void RollRetZ() {
    Roll(BACK, LEFT, FRONT, RIGHT);
  }

  DiceFace Find(const T &data) const {
    const Dice<T> &x = *this;
    DiceFace retval;
    for (DiceFace e : {TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT}) {
      if (x[e] == data) {
        retval = e;
      }
    }
    return retval;
  }

  int Adjust(T t, T f) {
    int cnt = 0;
    const Dice<T> &x = *this;
    while (x[TOP] != t and cnt < 4) {
      RollX();
      ++cnt;
    }
    cnt = 0;
    while (x[TOP] != t and cnt < 4) {
      RollY();
      ++cnt;
    }
    cnt = 0;
    while (x[FRONT] != f and cnt < 4) {
      RollZ();
      ++cnt;
    }
    if (x[TOP] == t and x[FRONT] == f) {
      return 0;
    } else {
      return -1;
    }
  }
};

void printSum()
{
  int ans[6];
  for(int i=0;i<6;i++)
    ans[i] = 0;

  for(int i=0;i<200;i++)
    for(int j=0;j<200;j++)
      if(top[i][j]!=-1)
        ans[top[i][j]-1]++;
  for(int i=0;i<6;i++)
  {
    if(i!=0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return;
}

void changePlace(Dice<int> d, int x, int y)
{
    for(int key=6;key>=4;key--)
    {
      for(int i=0;i<4;i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];

        //FRONT, BACK, LEFT, RIGHTを見たいから
        if(d.Find(key)==i+2)
        {
          if(height[x][y] > height[nx][ny])
          {
            if(i+2 == FRONT)
            {
              d.RollX();
              changePlace(d,nx,ny);
            }else if(i+2 == BACK)
            {
              d.RollRetX();
              changePlace(d,nx,ny);
            }else if(i+2 == LEFT)
            {
              d.RollRetY();
              changePlace(d,nx,ny);
            }else if(i+2 == RIGHT)
            {
              d.RollY();
              changePlace(d,nx,ny);
            }
            return;
          }
        }
      }
    }
    top[x][y] = d[TOP];
    height[x][y]++;
    return;
}

int main() {
  while(cin >> n)
  {
    if(n==0) break;

    for(int i=0;i<200;i++)
    {
      for(int j=0;j<200;j++)
      {
        top[i][j] = -1;
        height[i][j] = 0;
      }
    }

    for(int i=0;i<n;i++)
    {
      Dice<int> d;
     int t,f;
     cin >> t >> f;
     d[TOP] = 1;
     d[BOTTOM] = 6;
     d[FRONT] = 3;
     d[BACK] = 4;
     d[RIGHT] = 5;
     d[LEFT] = 2;
     d.Adjust(t, f);
     changePlace(d, 100,100);
    }
    printSum();
  }
}
