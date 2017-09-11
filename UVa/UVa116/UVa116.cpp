#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>

using namespace std;
#define Debug
//************For Debug********
#ifdef Debug
ifstream fin("UVa116.txt");
#define in fin

#else
#define in cin
#endif
//******************************
#define MAX_N 105
#define MAX_M 12
int m;
int n;
unsigned int G[MAX_M][MAX_N];
unsigned int d[MAX_M][MAX_N];//当前最小花费
int dir[MAX_M][MAX_N];//存储上一点的位置
int main()
{
	string line;
	while(getline(in,line))
	{
		stringstream sin(line);
		sin>>m>>n;
		for(int i=1;i<=m;++i)
		{
			getline(in,line);
			stringstream sin(line);
			for(int j=1;j<=n;++j)
			{
				sin>>G[i][j];
				//cout<<G[i][j]<<" ";
			}
			//cout<<endl;
		}
		memset(d,-1,sizeof(d));
		memset(dir,0,sizeof(dir));
		//设置第一列
		for(int i=1;i<=m;++i)
			d[i][1]=G[i][1];
		d[0][1]=G[m][1];
		d[m+1][1]=G[0][1];
		for(int j=2;j<=n;++j)
		{
			for(int i=1;i<=m;++i)
			{
				int c[3]={i-1,i,i+1};
				if(i==1)c[0]=m;
				if(i==m)c[2]=1;
				sort(c,c+3);
				for(int k=0;k<3;k++)
				{
					//printf("test %d\n",c[k]);
					int tmp=d[c[k]][j-1]+G[i][j];
					if(tmp<d[i][j])
					{
						d[i][j]=tmp;
						dir[i][j]=c[k];
						//printf("set d %d,%d :%d\n",i,j,tmp);
						//printf("set dir:%d\n",c[k]);
					}
				}
			}
		}
		unsigned mi=-1;
		int index=0;
		for(int r=1;r<=m;++r)
		{
			if(mi>d[r][n])
			{
				mi=d[r][n];
				index=r;
			}
		}
		int c=index;
		for(int i=n;i>=1;i--)
		{
			cout<<c<<" ";
			c=dir[c][i];
		}
		cout<<endl;
		/*
		for(int i=1;i<n;++i)
			cout<<a[i]<<" ";
		cout<<a[n]<<endl;*/
		cout<<mi<<endl;
	}
    return 0;
}








