#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define NMAX 10005
using namespace std;

FILE* fin = fopen("flood.in","r");
FILE* fout = fopen("flood.out","w");
struct Muchie
{
    int x,y;
    int c;
    friend bool operator <(const Muchie& a,const Muchie& b);
};

bool operator <(const Muchie& a,const Muchie& b)
{
    return a.c > b.c;
}


int n, m, tata[NMAX],h[NMAX];
vector<Muchie> apm;
priority_queue<Muchie> H,H1;
int Find(int x);
void Union(int x, int y);
void Citire();

int k,ct;
int main()
{
    int nrsel = 0;
    Citire();
    Muchie crt;
    int rx,ry;
    int cmin = 0;
    while( nrsel<n-1)
    {
        crt = H.top();
        H.pop();
        rx = Find(crt.x);
        ry = Find(crt.y);
        if(rx!=ry)
            {
                Union(rx,ry);
                cmin += crt.c;
                if(crt.c != 0)
                apm.push_back(crt);
                nrsel++;
            }
    }

    int i;
    fprintf(fout,"%d\n",cmin);
    fprintf(fout,"%d\n",apm.size());
    for(i= 0; i<apm.size(); i++)
        fprintf(fout,"%d %d %d\n",apm[i].x, apm[i].y,apm[i].c);

}

void Union (int x, int y)
{
    int rx,ry;
    rx = Find(x);
    ry = Find(y);
    if(h[rx]>h[ry])
        tata[ry] = rx;
    else if(h[rx]<h[ry])
        tata[rx] = ry;
    else if(h[rx] == h[ry])
    {
        tata[ry] = rx;
        h[rx]++;
    }
}

void Citire()
{
    int i,p;
    Muchie crt;
    fscanf(fin,"%d %d",&n,&m);
    for(i =0; i<m;i++)
    {
        fscanf(fin,"%d %d",&crt.x,&crt.y);
        crt.c = 0;
        H.push(crt);
    }
    fscanf(fin,"%d",&p);
    for(i = 0; i<p;i++)
    {
        fscanf(fin,"%d%d%d",&crt.x,&crt.y,&crt.c);
        H.push(crt);
    }

}

int Find(int x)
{
    int rx = x,y;
    while(tata[rx])
        rx = tata[rx];

    while(x!=rx)
    {
        y = tata[x];
        tata[x] = rx;
        x = y;
    }
    return rx;
}