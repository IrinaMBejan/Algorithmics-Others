#include <fstream>

using namespace std;
ifstream fin("ruleta2.in");
ofstream fout("ruleta2.out");

int R[10001],u[10001];
int main()
{
    int ok = 0, n, k, i, t, z = 0, gt = 0;
    long r = 0;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> R[i];
        u[i] = i + 1;
    }
    u[n-1] = 0;
    k = n;
    i = 0;
    while(!gt)
    {
        if(u[i]==(i+1)%n)
            if(R[u[i]]>=R[i] && R[i])
            {
                R[u[i]] = R[u[i]] - R[i];
                ok = 1;
                if(R[u[i]]+z==0)
                {
                    k = i;
                    z = 1;
                }
                else if(R[i]<=R[u[i]])
                {
                    u[k]=i;
                    z=0;
                    k=n;
                }
            }
        if(u[i]<i)
        {
            r++;
            if(!ok)gt=1;
            else ok=0;
        }
        i=u[i];
    }
    t=0;
    for(i=0; i<n; i++) t=t+(R[i]>0);
    fout<<r<<' '<<t;
}

