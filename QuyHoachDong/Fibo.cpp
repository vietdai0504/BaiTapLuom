#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
int f[100];
int fibo(int n)
{
    if (n<=2) return 1;
    if (f[n] != -1) return f[n];
    f[n] = fibo(n-1) + fibo(n-2);
    return f[n];
}
// int fibo(int n)
// {
//     if (n<=2) return 1;
//     return fibo(n-1) + fibo(n-2);
// }
int main()
{
    clock_t start, end;
    start = clock();
    memset(f, -1, sizeof f);
    cout<<fibo(47)<<endl;
    end = clock();
    cout<<(double)(end-start)/CLOCKS_PER_SEC;
}