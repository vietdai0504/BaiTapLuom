//dãy con tăng dài nhất không cần liên tiếp nhau
#include <iostream>
#include <ctime>
#define maxN 1000000
using namespace std;
int f[maxN],a[maxN];
int max(int a, int b)
{
    if (a>=b) return a;
    return b;
}
int main()
{
    int n; cin>>n;
    clock_t start, end;
    
    
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    start = clock();

    int ans = 0;

    for (int i = 1;i<=n;i++)
    {
        f[i] = 1;
        for (int j = 1;j<i;j++)
        {
            if (a[j] < a[i])
            {
                f[i] = max(f[i],f[j]+1);
            }
        }
        ans = max(ans,f[i]);
    }

    cout<<ans<<endl;

    end = clock();
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<" s";
}