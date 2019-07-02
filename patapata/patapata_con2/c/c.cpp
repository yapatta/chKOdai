#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

char t[10][10];

int getSum(int x,int y, char c)
{
	int sum = 0;
	for(int i=0;i<8;i++)
	{
		int cnt=0;
		int nx=x;
		int ny=y;
		while(true)
		{
			nx+=dx[i];
			ny+=dy[i];
			if(t[nx][ny]=='.')
			{
				cnt = 0;
				break;
			}
			else if(t[nx][ny]==c)
			{
				sum+=cnt;
				break;
			}
			else
				cnt++;
		}
	}
	return sum;
}

void changedResult(int x,int y, char c)
{
	for(int i=0;i<8;i++)
	{
		int cnt=0;
		int nx=x;
		int ny=y;
		while(true)
		{
			nx+=dx[i];
			ny+=dy[i];
			if(t[nx][ny]=='.')
			{
				cnt = 0;
				break;
			}
			else if(t[nx][ny]==c)
			{
				break;
			}
			else
				cnt++;
		}
		if(cnt>0)
		{
			nx = x;
			ny = y;
			while(true)
			{
				nx+=dx[i];
				ny+=dy[i];
				if(t[nx][ny]=='.')
					break;
				else if(t[nx][ny]==c)
				{
					break;
				}
				else
					t[nx][ny] = c;
			}
				
		}
	}
}


int main()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			t[i][j]='.';
	
	for(int i=1;i<=8;i++)
	{
		string s;
		cin >> s;
		for(int j=1;j<=8;j++)
			t[i][j]=s[j-1];
	}
	/*
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			cout << t[i][j];
		cout << endl;
	}
	*/

	char turn='o';
	int pass=0;
	while(true)
	{
		int high=0;
		int nx=0;
		int ny=0;
		if(turn=='o')
		{
			for(int i=1;i<=8;i++)
			for(int j=1;j<=8;j++)
				if(t[i][j]=='.')
				{
					int tmp=getSum(i,j,turn);
					if(tmp>high)
					{
						high=tmp;
						nx=i;
						ny=j;
					}
				}
		}
		else if(turn=='x')
		{
			for(int i=8;i>=1;i--)
			for(int j=8;j>=1;j--)
				if(t[i][j]=='.')
				{
					int tmp=getSum(i,j,turn);
					if(tmp>high)
					{
						high=tmp;
						nx=i;
						ny=j;
					}
				}
		}

		if(high==0)
		{
			pass++;
		}
		else
		{
			changedResult(nx,ny,turn);
			t[nx][ny] = turn;
			pass=0;
		}
		if(turn=='o')turn='x';
		else if(turn=='x')turn='o';
		if(pass>=2)break;
	}
	for(int i=1;i<9;i++)
	{
		for(int j=1;j<9;j++)
			cout << t[i][j];
		cout << endl;
	}

}
