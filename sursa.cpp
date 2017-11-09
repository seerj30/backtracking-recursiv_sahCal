#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int lin=1,col=1,dx[]={-1,1,1,-1,-2,2,2,-2},dy[]={2,2,-2,-2,1,1,-1,-1},st[100][2],n,a[50][50];

void back(int k, int lin, int col)
{
	int i,j,l,c,b[50][50];
	if(k==n*n)
	{
		for(i=1;i<k;i++)
			b[st[i][0]][st[i][1]]=i;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				cout<<b[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		exit(1);
	}
	else
	{
		st[k][0]=lin;
		st[k][1]=col;
		for(i=0;i<=7;i++)
		{
			l=lin+dx[i];
			c=col+dy[i];
			if(l>=1 && l<=n && c>=1 && c<=n && a[l][c]==0)
			{
				a[l][c]=1;
				back(k+1,l,c);
				a[l][c]=0;
			}
		}
	}
}

int main()
{
	cout<<"n=";cin>>n;
	back(1,lin,col);
	return 0;
}
