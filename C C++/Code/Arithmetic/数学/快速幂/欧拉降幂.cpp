/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-26 10:47:14
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 1000100;

//快速幂
ll fast_pow(ll a, ll b, ll mod)
{
	ll ans = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
		{
			ans = (ans * a) % mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
}

//求出x的欧拉函数值
ll euler_fun(ll x)
{
	ll num = x;
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			num = num / i * (i - 1);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	if (x > 1)
	{
		num = num / x * (x - 1);
	}
	return num;
}

//降幂函数,因为幂方的值可能巨大,故用char数组储存
ll drop_pow(ll a, string b, ll c)
{
	//求出c的欧拉函数值
	ll num = euler_fun(c);
	//存储降了之后的幂值
	ll des_pow = 0;
	for (ll i = 0, len = b.size(); i < len; ++i)
	{
		des_pow = (des_pow * 10 + b[i] - '0') % num;
	}
	//即b mod &(c) + &(c)
	des_pow += num;
	//使用快速幂
	return fast_pow(a, des_pow, c);
}

int main()
{
	cout << 12302135942453 / 234 - (1031 / 234);
	return 0;
}
