// số cách đổ xúc sắc để được tổng n
#include <iostream>
#define max 1000000
using namespace std;
int f[max];
int main()
{
    int n; cin>>n;
    f[0] = 1;
    for (int s = 1; s <= n; s++)
    {
        for (int j = 1; j<=6; j++)
        {

            if (j<=s)
                f[s] = f[s] + f[s-j];

        }
    }
    cout<<f[n];
}