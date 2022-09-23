#include <iostream>
using namespace std;
struct gcd
{
    int num1; //第一個數字
    int num2; //第二個數字
    int r;    //餘數
};
int gcd_iterator(gcd _gcd)
{
    int q = _gcd.num1 / _gcd.num2;
    cout << "q: " << q << " ";
    _gcd.r = _gcd.num1 % _gcd.num2;
    cout << "r: " << _gcd.r << endl;
    if (_gcd.r == 0)
    {
        return _gcd.num2;
    }
    gcd gcd_next;
    gcd_next.num1 = _gcd.num2;
    gcd_next.num2 = _gcd.r;
    return gcd_iterator(gcd_next);
    ;
}
int main()
{
    int r1, r2;
    cout << "輸入兩個數字" << endl;
    gcd _first_gcd;
    cin >> _first_gcd.num1 >> _first_gcd.num2;
    int anser = gcd_iterator(_first_gcd);
    cout << "最大公因數是:" << anser << endl;

    return 0;
}
