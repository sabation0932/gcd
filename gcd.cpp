#include <iostream>
using namespace std;
struct gcd
{
    int num1; //第一個數字
    int num2; //第二個數字
    int r;    //餘數
    // s*num1 + t*num2 = gcd(num1,num2) //最大公因數
    int s1 = 1;     
    int s2 = 0;
    int s;
    int t1 = 0;
    int t2 = 1;
    int t;
};
//歐幾里得延伸演算法 
gcd gcd_iterator(gcd _gcd)
{
    if (_gcd.num2 == 0)
    {
        return _gcd;
    }
    int q = _gcd.num1 / _gcd.num2;
    _gcd.r = _gcd.num1 % _gcd.num2;
    _gcd.s = _gcd.s1 - (_gcd.s2 *q);
    _gcd.t = _gcd.t1 - (_gcd.t2 *q);
    cout << "q: " << q << " "<< "r: " << _gcd.r << " "<<"s: "<<_gcd.s <<" "<< "t: "<< _gcd.t<<endl;
    
    gcd gcd_next;
    gcd_next.num1 = _gcd.num2;
    gcd_next.num2 = _gcd.r;
    gcd_next.s1 = _gcd.s2;
    gcd_next.s2 = _gcd.s;
    gcd_next.t1 = _gcd.t2;
    gcd_next.t2 = _gcd.t;
    return gcd_iterator(gcd_next);

}
int main()
{
    int r1, r2;
    cout << "輸入兩個數字" << endl;
    gcd _first_gcd;
    cin >> _first_gcd.num1 >> _first_gcd.num2;
    gcd anser = gcd_iterator(_first_gcd);
    cout << "最大公因數是:" << anser.num1 <<" "<<"s:" << anser.s1<<" "<<"t:"<< anser.t1<<" "<<endl;


    return 0;
}
