#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>


using namespace std;
#define Debug
//************For Debug********
#ifdef Debug
ifstream fin("NYOJ16.txt");
#define in fin

#else
#define in cin
#endif
//******************************
#define MAX_N 1005
int m;
int n;

int G[MAX_N][MAX_N];
int x[MAX_N];
int y[MAX_N];
int d[MAX_N];
bool check(int i,int j)
{
	return (x[i]<x[j]&&y[i]<y[j])||(x[i]<y[j]&&y[i]<x[j]);
}

int dp(int i)
{
	int &ans=d[i];
	if(ans>0)return ans;
	ans=1;
	for(int j=1;j<=n;++j)
		if(G[i][j])ans=max(ans,dp(j)+1);
	return ans;
}
void print_ans(int k)
{
	printf("%d %d\n",x[k],y[k]);
	if(d[k]==1)return;
	for(int i=1;i<=n;++i)
		if(G[k][i]&&d[k]==d[i]+1)
		{
			print_ans(i);
			return;
		}
}
int main()
{
    in>>m;
	for(int i=0;i<m;++i)
	{
		in>>n;
		int xc,yc;
		memset(d,0,sizeof(d));
		memset(G,0,sizeof(G));
		for(int j=1;j<=n;++j)
		{
			in>>x[j]>>y[j];
			//cout<<x[j]<<" "<<y[j]<<endl;
			for(int k=1;k<j;++k)
			{
				if(check(j,k))
				{
					//printf("%d<%d\n",j,k);
					G[j][k]=1;
				}
				if(check(k,j))
				{
					//printf("%d>%d\n",j,k);
					G[k][j]=1;
				}
			}
		}
		int ma=0;
		int k=0;
		for(int i=1;i<=n;++i)
		{
			int c=dp(i);
			if(ma<c)k=i;
			ma=max(ma,c);
		}
		print_ans(k);
		cout<<ma<<endl;
	}
    return 0;
}


