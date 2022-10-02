#include <iostream>
using namespace std;
struct gcd
{
    int num1; //第一個數字 經過迭代後是最大公因數
    int num2; //第二個數字
    int r;    //餘數
    // s*num1 + t*num2 = gcd(num1,num2) //最大公因數
    int s1 = 1; //  經過迭代後是s
    int s2 = 0;
    int s;
    int t1 = 0; // 經過迭代後是t
    int t2 = 1;
    int t;
};


gcd gcd_iterator(gcd _gcd)
{
    if (_gcd.num2 == 0)
    {
        return _gcd;
    }
    int q = _gcd.num1 / _gcd.num2;
    _gcd.r = _gcd.num1 % _gcd.num2;
    _gcd.s = _gcd.s1 - (_gcd.s2 * q);
    _gcd.t = _gcd.t1 - (_gcd.t2 * q);
    cout << "q: " << q << " "
         << "r: " << _gcd.r << " "
         << "s: " << _gcd.s << " "
         << "t: " << _gcd.t << endl;

    gcd gcd_next;
    gcd_next.num1 = _gcd.num2;
    gcd_next.num2 = _gcd.r;
    gcd_next.s1 = _gcd.s2;
    gcd_next.s2 = _gcd.s;
    gcd_next.t1 = _gcd.t2;
    gcd_next.t2 = _gcd.t;
    return gcd_iterator(gcd_next);
};
void new_gcd() //執行一個最大公因數運算
{
    int r1, r2;
    cout << "輸入兩個數字" << endl;
    gcd _first_gcd;
    cin >> _first_gcd.num1 >> _first_gcd.num2;
    gcd answer = gcd_iterator(_first_gcd);
    cout << "最大公因數是:" << answer.num1 << " "
         << "s:" << answer.s1 << " "
         << "t:" << answer.t1 << " " << endl;
}
//求出方程式特解和通解
void diophantine(int _a, int _b, int _c)
{ // ax + by = c
    gcd this_gcd;
    this_gcd.num1 = _a;
    this_gcd.num2 = _b;

    //求特解 Particular solution
    gcd answer = gcd_iterator(this_gcd);

    int x_particular = (_c / answer.num1) * answer.s1;
    int y_particular = (_c / answer.num1) * answer.t1;
    cout << "x_0:" << x_particular << " y_0:" << y_particular <<endl;

    //求通解 且職
}

int main()
{
    int a,b,c;
    cout << "輸入三個數字" << endl;
    cin >> a >> b >> c;
    diophantine(a,b,c);

    return 0;

}
