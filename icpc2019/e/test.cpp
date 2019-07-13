#include<bits/stdc++.h>

using namespace std;

vector<vector<vector<int> > > pa(6); 
int n;

bool allok()
{


	return ;
}

int main()
{
	while(cin >> n)
	{
		if(n==0)
			break;
		bool cant=false;
		for(int i=0;i<6;i++)
			for(int j=0;j<n;j++)
			{
				string tmp;
				cin >> tmp;
				for(int k=0;k<n;k++)
					pa[i][j][k]=(tmp[k]=='#' ? 1:0);
				if(j!=0 and j!=n-1)
					for(int k=1;k<n-1;k++)
						if(pa[i][j][k]==0)
							cant=true;
			}

		if(cant)
		{
			cout << "No" << endl;
			continue;
		}

		bool flag=false;
		for(int )
		{
			vector<pair<int,int> > input;
			if(allok(input))
			{
				cout << "Yes" << endl;
				flag=true;
				break;
			}
	
		}
		if(!flag)cout << "No" << endl;

	}
	
	
}
