/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-26 10:44:20
 */

typedef long long ll;
ll fastPow(ll a, ll b, ll m)
{
    ll r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = (r * a) % m;
        }
        b >>= 1;
        a = (a * a) % m;
    }
    return r;
}