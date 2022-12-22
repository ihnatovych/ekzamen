#include <bits/stdc++.h>
#define maxn 5005
using namespace std;
char s[maxn];
int f[maxn][maxn];
int sum;
int n;
int trc;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = n; i >= 1; --i)
    {
        if (s[i] == '=')
        {
            for (int j = i + 1; j <= n; ++j)
            {
                sum = sum * 10 + (s[j] - '0');
            }

            n = i - 1;
            break;
        }
    }

    cout << sum << endl; //вводимо потрібне нам число справа
    f[0][0] = 1;
    int d = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp = 0;
        int base = 1;
        if (s[i] == '0')
        {
            ++d;
        }
        else
        {
            d = 0;
            trc = i;
        }

        if (d >= 2)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (f[trc][j])
                {
                    f[i][j] = f[trc][j] + 1;
                }
            }
        }

        for (int k = 1; k <= 4; ++k)
        {
            if (i - k < 0)
            {
                break;
            }

            tmp = (s[i - k + 1] - '0') * base + tmp;
            base *= 10;
            for (int j = sum - tmp; j >= 0; --j)
            {
                if (f[i - k][j])
                {
                    if (f[i][j + tmp])
                    {
                        f[i][j + tmp] = min(f[i][j + tmp], f[i - k][j] + 1);
                    }
                    else
                    {
                        f[i][j + tmp] = f[i - k][j] + 1;
                    }
                }
            }
        }
    }

    cout << f[n][sum] - 2; //розрахунок найменшого числа операцій
    return 0;
}