#include <iostream>
#include <vector>
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

class diophantine
{
private:
    /* data */
public:
    // ax + by = c
    int a;
    int b;
    int c;
    int d;
    gcd the_gcd;

    //特解
    int x_particular;
    int y_particular;

    //通解

    //建構式
    diophantine(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
        the_gcd.num1 = _a;
        the_gcd.num2 = _b;
    };

    //求出方程式特解
    void particular(void)
    {
        gcd answer = gcd_iterator(the_gcd);
        d = answer.num1;
        
        x_particular = (c / d) * answer.s1;
        y_particular = (c / d) * answer.t1;

        cout <<"d " <<d <<endl;
        cout << "最大公因數是:" << answer.num1 << " "
             << "s:" << answer.s1 << " "
             << "t:" << answer.t1 << " " << endl;
        cout << "x_0:" << x_particular << " y_0:" << y_particular << endl;
    };
    //求出方程式通解
    vector<vector<int> > general(int _k_min, int _k_max)
    {
        particular(); //先計算出特解
        vector<vector<int> >general_vector;
        
        for (int  i= _k_min; i <= _k_max; i++)
        {
            //宣告一個row 
            vector<int> row;
            int x_general = x_particular + i*(b/d);
            int y_general = y_particular + i*(a/d);
            
            cout << i <<" : "<< x_general << " "<<y_general <<endl;
            row.push_back(x_general);
            row.push_back(y_general);
            general_vector.push_back(row);
        }
        return general_vector;
            
    }
    
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

//模數運算
//尋找乘法反元素
int multiplicative(int target,int mod_number) {
    gcd check_gcd;
    check_gcd.num1 = target;
    check_gcd.num2 = mod_number;
    gcd answer = gcd_iterator(check_gcd);
    if (answer.num1 == 1){
        cout << target << "和" << mod_number << "乘法反元素"<<endl;
        return answer.num1;
    }
    else
    {
        cout << target << "和" << mod_number << "沒有乘法反元素" << endl;
        return answer.num1;
    }
    

}
int main()
{
    int a, b, c;
    cout << "輸入三個數字" << endl;
    cin >> a >> b >> c;
    diophantine the_diophantine(a,b,c);
    vector<vector<int> > general_list = the_diophantine.general(-1,5);
    cout<< "---" <<endl;
    for (auto row : general_list)
    {
        for (auto val : row)
        {
            printf("%d ", val);
        }
        printf("\n");
    }

    return 0;
}