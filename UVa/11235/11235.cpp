#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
//#include<sstream>

using namespace std;
#define Debug
//************For Debug********
#ifdef Debug
ifstream fin("11235.txt");
#define in fin

#else
#define in cin
#endif
//******************************
#define  MZ(a) memset(a,0,sizeof(a));
#define  MF(a) memset(a,-1,sizeof(a));
#define  MAX_N 100010
int value[MAX_N];
int cot[MAX_N];
int num[MAX_N];
int lef[MAX_N];
int rig[MAX_N];
int cnt=0;
int n;
int q;
int d[MAX_N][32];
void RMQ_init()
{
	for(int i=1;i<=cnt;++i)
		d[i][0]=cot[i];
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int RMQ(int l,int r)
{
	int k=0;
	while(1<<(k+1)<=r-l+1)k++;//如果2^k+1<=R-L+1 ,k++
	return max(d[l][k],d[r-(1<<k)+1][k]);
}
int RM(int l, int r)
{
	if(r==l)return 1;
	int ln=rig[l]-l+1;
	int rn=r-lef[r]+1;
	int ml=num[l]+1;
	int mr=num[r]-1;
	int m=0;
	if(ml<=mr)m=RMQ(ml,mr);
//	printf("lr:%d,%d\n",ml,mr);
//	printf("lmr:%d,%d,%d\n",ln,m,rn);
	int c[3]={ln,rn,m};
	sort(c,c+3);
	return c[2];
}

int main()
{
	in>>n>>q;
	int t;
	int v;
	int numm=1;
	in>>v;
	for(int i=2;i<=n+1;++i)
	{
		if(i!=n+1)in>>t;
		if(v==t&&i!=n+1)numm++;
		if(v!=t||i==n+1)
		{
			cnt++;
			value[cnt]=v;
			cot[cnt]=numm;
			for(int j=i-numm;j<i;++j)
			{
				num[j]=cnt;
				lef[j]=i-numm;
				rig[j]=i-1;
			}
			v=t;
			numm=1;
		}
	}
	int l,r;
	RMQ_init();
	for(int i=1;i<=q;++i)
	{
		in>>l>>r;
		cout<<RM(l,r)<<endl;
	}
    return 0;
}


