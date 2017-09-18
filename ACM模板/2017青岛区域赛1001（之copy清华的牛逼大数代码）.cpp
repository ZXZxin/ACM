#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype> 
#include <numeric>
#include <iomanip>
#include <assert.h>
#include <cstdio>
#include <utility>
#include <cassert>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define RVC(i, c) fot (int i = 0; i < (c).size(); ++i)
#define RED(k, u) for (int k = head[(u)]; k; k = edge[k].next)
#define SQR(k) (k) * (k)
#define lowbit(x) ((x) & (-(x)))
#define CL(x, v) memset(x, v, sizeof x)
#define MP std::make_pair
#define PB push_back
#define FR first
#define SC second
#define rank rankk
#define next nextt
#define link linkk
#define index indexx
#define abs(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;
#define EPS 1e-8
const int maxn = 550;
typedef long long LL;
typedef pair<int, int> PII;

#define MAX_L 2005 

class bign
{
public:
	int len, s[MAX_L];
	bign();
	bign(const char*);
	bign(int);
	bool sign;
	string toStr() const;
	friend istream& operator >> (istream &, bign &);
	friend ostream& operator<<(ostream &, bign &);
	bign operator=(const char*);
	bign operator=(int);
	bign operator=(const string);
	bool operator>(const bign &) const;
	bool operator>=(const bign &) const;
	bool operator<(const bign &) const;
	bool operator<=(const bign &) const;
	bool operator==(const bign &) const;
	bool operator!=(const bign &) const;
	bign operator+(const bign &) const;
	bign operator++();
	bign operator++(int);
	bign operator+=(const bign&);
	bign operator-(const bign &) const;
	bign operator--();
	bign operator--(int);
	bign operator-=(const bign&);
	bign operator*(const bign &)const;
	bign operator*(const int num)const;
	bign operator*=(const bign&);
	bign operator/(const bign&)const;
	bign operator/=(const bign&);
	bign operator%(const bign&)const;
	bign factorial()const;
	bign Sqrt()const;
	bign pow(const bign&)const;
	void clean();
	~bign();
};
#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b

bign::bign()
{
	memset(s, 0, sizeof(s));
	len = 1;
	sign = 1;
}

bign::bign(const char *num)
{
	*this = num;
}

bign::bign(int num)
{
	*this = num;
}

string bign::toStr() const
{
	string res;
	res = "";
	for (int i = 0; i < len; i++)
		res = (char)(s[i] + '0') + res;
	if (res == "")
		res = "0";
	if (!sign&&res != "0")
		res = "-" + res;
	return res;
}

istream &operator >> (istream &in, bign &num)
{
	string str;
	in >> str;
	num = str;
	return in;
}

ostream &operator<<(ostream &out, bign &num)
{
	out << num.toStr();
	return out;
}

bign bign::operator=(const char *num)
{
	memset(s, 0, sizeof(s));
	char a[MAX_L] = "";
	if (num[0] != '-')
		strcpy(a, num);
	else
		for (int i = 1; i < strlen(num); i++)
			a[i - 1] = num[i];
	sign = !(num[0] == '-');
	len = strlen(a);
	for (int i = 0; i < strlen(a); i++)
		s[i] = a[len - i - 1] - 48;
	return *this;
}

bign bign::operator=(int num)
{
	char temp[MAX_L];
	sprintf(temp, "%d", num);
	*this = temp;
	return *this;
}

bign bign::operator=(const string num)
{
	const char *tmp;
	tmp = num.c_str();
	*this = tmp;
	return *this;
}

bool bign::operator<(const bign &num) const
{
	if (sign^num.sign)
		return num.sign;
	if (len != num.len)
		return len < num.len;
	for (int i = len - 1; i >= 0; i--)
		if (s[i] != num.s[i])
			return sign ? (s[i] < num.s[i]) : (!(s[i] < num.s[i]));
	return !sign;
}

bool bign::operator>(const bign&num)const
{
	return num < *this;
}

bool bign::operator<=(const bign&num)const
{
	return !(*this>num);
}

bool bign::operator>=(const bign&num)const
{
	return !(*this<num);
}

bool bign::operator!=(const bign&num)const
{
	return *this > num || *this < num;
}

bool bign::operator==(const bign&num)const
{
	return !(num != *this);
}

bign bign::operator+(const bign &num) const
{
	if (sign^num.sign)
	{
		bign tmp = sign ? num : *this;
		tmp.sign = 1;
		return sign ? *this - tmp : num - tmp;
	}
	bign result;
	result.len = 0;
	int temp = 0;
	for (int i = 0; temp || i < (max(len, num.len)); i++)
	{
		int t = s[i] + num.s[i] + temp;
		result.s[result.len++] = t % 10;
		temp = t / 10;
	}
	result.sign = sign;
	return result;
}

bign bign::operator++()
{
	*this = *this + 1;
	return *this;
}

bign bign::operator++(int)
{
	bign old = *this;
	++(*this);
	return old;
}

bign bign::operator+=(const bign &num)
{
	*this = *this + num;
	return *this;
}

bign bign::operator-(const bign &num) const
{
	bign b = num, a = *this;
	if (!num.sign && !sign)
	{
		b.sign = 1;
		a.sign = 1;
		return b - a;
	}
	if (!b.sign)
	{
		b.sign = 1;
		return a + b;
	}
	if (!a.sign)
	{
		a.sign = 1;
		b = bign(0) - (a + b);
		return b;
	}
	if (a<b)
	{
		bign c = (b - a);
		c.sign = false;
		return c;
	}
	bign result;
	result.len = 0;
	for (int i = 0, g = 0; i < a.len; i++)
	{
		int x = a.s[i] - g;
		if (i < b.len) x -= b.s[i];
		if (x >= 0) g = 0;
		else
		{
			g = 1;
			x += 10;
		}
		result.s[result.len++] = x;
	}
	result.clean();
	return result;
}

bign bign::operator * (const bign &num)const
{
	bign result;
	result.len = len + num.len;

	for (int i = 0; i < len; i++)
		for (int j = 0; j < num.len; j++)
			result.s[i + j] += s[i] * num.s[j];

	for (int i = 0; i < result.len; i++)
	{
		result.s[i + 1] += result.s[i] / 10;
		result.s[i] %= 10;
	}
	result.clean();
	result.sign = !(sign^num.sign);
	return result;
}

bign bign::operator*(const int num)const
{
	bign x = num;
	bign z = *this;
	return x*z;
}
bign bign::operator*=(const bign&num)
{
	*this = *this * num;
	return *this;
}

bign bign::operator /(const bign&num)const
{
	bign ans;
	ans.len = len - num.len + 1;
	if (ans.len < 0)
	{
		ans.len = 1;
		return ans;
	}

	bign divisor = *this, divid = num;
	divisor.sign = divid.sign = 1;
	int k = ans.len - 1;
	int j = len - 1;
	while (k >= 0)
	{
		while (divisor.s[j] == 0) j--;
		if (k > j) k = j;
		char z[MAX_L];
		memset(z, 0, sizeof(z));
		for (int i = j; i >= k; i--)
			z[j - i] = divisor.s[i] + '0';
		bign dividend = z;
		if (dividend < divid) { k--; continue; }
		int key = 0;
		while (divid*key <= dividend) key++;
		key--;
		ans.s[k] = key;
		bign temp = divid*key;
		for (int i = 0; i < k; i++)
			temp = temp * 10;
		divisor = divisor - temp;
		k--;
	}
	ans.clean();
	ans.sign = !(sign^num.sign);
	return ans;
}

bign bign::operator/=(const bign&num)
{
	*this = *this / num;
	return *this;
}

bign bign::operator%(const bign& num)const
{
	bign a = *this, b = num;
	a.sign = b.sign = 1;
	bign result, temp = a / b*b;
	result = a - temp;
	result.sign = sign;
	return result;
}

bign bign::pow(const bign& num)const
{
	bign result = 1;
	for (bign i = 0; i < num; i++)
		result = result*(*this);
	return result;
}

bign bign::factorial()const
{
	bign result = 1;
	for (bign i = 1; i <= *this; i++)
		result *= i;
	return result;
}

void bign::clean()
{
	if (len == 0) len++;
	while (len > 1 && s[len - 1] == '\0')
		len--;
}

bign bign::Sqrt()const
{
	if (*this<0)return -1;
	if (*this <= 1)return *this;
	bign l = 0, r = *this, mid;
	while (r - l>1)
	{
		mid = (l + r) / 2;
		if (mid*mid>*this)
			r = mid;
		else
			l = mid;
	}
	return l;
}
bign::~bign()
{
}
struct point {
	bign x, y;
};
bign get_distance(point &a, point &b)
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
/*
point get_circle_center(const point a, const point b, const point c)
{
point center;
bign a1 = b.x - a.x;
bign b1 = b.y - a.y;
bign c1 = (a1 * a1 + b1 * b1) / 2.0;
bign a2 = c.x - a.x;
bign b2 = c.y - a.y;
bign c2 = (a2 * a2 + b2 * b2) / 2.0;
bign d = a1 * b2 - a2 * b1;
center.x = a.x + (c1 * b2 - c2 * b1) / d;
center.y = a.y + (a1 * c2 - a2 * c1) / d;
return center;
}
*/
bign D;
point get_circle_center(point a, point b, point c)
{
	point center;
	bign a1 = b.x - a.x;
	bign b1 = b.y - a.y;
	bign c1 = (a1 * a1 + b1 * b1);
	bign a2 = c.x - a.x;
	bign b2 = c.y - a.y;
	bign c2 = (a2 * a2 + b2 * b2);
	bign d = a1 * b2 - a2 * b1;
	D = d * 2;
	center.x = a.x * 2 * d + (c1 * b2 - c2 * b1);
	center.y = a.y * 2 * d + (a1 * c2 - a2 * c1);
	return center;
}
void solve()
{
	point a, b, c, d;
	//scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	/*
	int ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
	a.x = ax + 1000000000;
	a.y = ay + 1000000000;
	b.x = bx + 1000000000;
	b.y = by + 1000000000;
	c.x = cx + 1000000000;
	c.y = cy + 1000000000;
	d.x = dx + 1000000000;
	d.y = dy + 1000000000;
	*/
	point o = get_circle_center(a, b, c);
	a.x = a.x * D, a.y = a.y * D, d.x = d.x * D, d.y = d.y * D;
	//cout << get_distance(o, a).toStr() << " " << get_distance(o, d).toStr() << endl;
	if (get_distance(o, a) < get_distance(o, d))
		puts("Accepted");
	else
		puts("Rejected");
}
int main()
{
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; ++i)
		solve();
	return 0;
}