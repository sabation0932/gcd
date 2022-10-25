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
        gcd gcd_final;
        gcd_final.num1 = _gcd.num1;
        gcd_final.num2 = _gcd.num2;
        gcd_final.r = int(NULL);
        gcd_final.s1 = _gcd.s1;
        gcd_final.s2 = _gcd.s2;
        gcd_final.s = int(NULL);
        gcd_final.t1 = _gcd.t1;
        gcd_final.t2 = _gcd.t2;
        gcd_final.t = int(NULL);

        cout << "q:"
             << " X "
             << " "
             << "r1:" << gcd_final.num1 << " "
             << "r2:" << gcd_final.num2 << " "
             << "r :" << gcd_final.r << " "
             << "r: "
             << " X "
             << " "
             << "s1:" << gcd_final.s1 << " "
             << "s2:" << gcd_final.s2 << " "
             << "s: "
             << " X "
             << " "
             << "t1:" << gcd_final.t1 << " "
             << "t2:" << gcd_final.t2 << " "
             << "t: "
             << " X " << endl;

        return gcd_final;
    }
    int q = _gcd.num1 / _gcd.num2;
    _gcd.r = _gcd.num1 % _gcd.num2;
    _gcd.s = _gcd.s1 - (_gcd.s2 * q);
    _gcd.t = _gcd.t1 - (_gcd.t2 * q);

    cout << "q: " << q << " "
         << "r1: " << _gcd.num1 << " "
         << "r2: " << _gcd.num2 << " "
         << "r: " << _gcd.r << " "
         << "s1: " << _gcd.s1 << " "
         << "s2: " << _gcd.s2 << " "
         << "s: " << _gcd.s << " "
         << "t1: " << _gcd.t1 << " "
         << "t2: " << _gcd.t2 << " "
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

        cout << "d " << d << endl;
        cout << "最大公因數是:" << answer.num1 << " "
             << "s:" << answer.s1 << " "
             << "t:" << answer.t1 << " " << endl;
        cout << "x_0:" << x_particular << " y_0:" << y_particular << endl;
    };
    //求出方程式通解
    vector<vector<int> > general(int _k_min, int _k_max)
    {
        particular(); //先計算出特解
        vector<vector<int> > general_vector;

        for (int i = _k_min; i <= _k_max; i++)
        {
            //宣告一個row
            vector<int> row;
            int x_general = x_particular + i * (b / d);
            int y_general = y_particular + i * (a / d);

            cout << i << " : " << x_general << " " << y_general << endl;
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
//列舉乘法反元素
vector<vector<int> > multiplicative(int _mod_number)
{
    vector<vector<int> > z_n;
    for (int i = 1; i < _mod_number; i++)
    {
        gcd check_gcd;
        int _target = i;
        check_gcd.num1 = _mod_number;
        check_gcd.num2 = _target;
        vector<int> find_tuple;
        gcd answer = gcd_iterator(check_gcd);
        if (answer.num1 == 1)
        {
            // 如果乘法反元素是負數 再加上模數
            if (answer.t1 < 0)
            {
                answer.t1 = answer.t1 + _mod_number;
            }
            cout << _target << "和" << _mod_number << "有乘法反元素" << answer.t1 << endl;
            find_tuple.push_back(_target);
            find_tuple.push_back(answer.t1);
            z_n.push_back(find_tuple);
            cout << endl;
        }
        else
        {
            cout << _target << "和" << _mod_number << "沒有乘法反元素 因為gcd =" << answer.num1 << endl;
            cout << endl;
        }
    }
    return z_n;
}
int main()
{
    /*最大公因數*/
    // new_gcd();

    /*通解 特解*/
    // int a, b, c;
    // cout << "輸入三個數字" << endl;
    // cin >> a >> b >> c;
    // diophantine the_diophantine(a,b,c);
    // vector<vector<int> > general_list = the_diophantine.general(-1,5);
    // cout<< "---" <<endl;
    // for (auto row : general_list)
    // {
    //     for (auto val : row)
    //     {
    //         printf("%d ", val);
    //     }
    //     printf("\n");
    // }

    /* 計算乘法反元素 */
    int z_n_mod; // 模數為 n 的集合
    int target;  // 目標數
    cout << "請輸入模數 與 目標數" << endl;
    cin >> z_n_mod >> target;

    vector<vector<int> > inverse_list = multiplicative(z_n_mod);
    int target_inverse;
    bool flag_target = true;
    bool flag_target_inverse = false;
    for (auto row : inverse_list)
    {
        for (auto val : row)
        {
            printf("%d ", val);
            if (flag_target_inverse == true && flag_target == false)
            {
                target_inverse = val;
                flag_target_inverse = false;
                flag_target_inverse = false;
            }
            if (val == target && flag_target == true)
            {
                flag_target = false;
                flag_target_inverse = true;
            }
        }
        cout << endl;
    }
    for (int i = 1; i < 10000; i++)
    {
        int n ;
        n = i*22;
        if (n % 19 == 1)
        {
            cout << n <<" " <<i<<endl;
            break;
        }
        
    }
    

    //問題在Z_n 中 尋找 n的乘法反余數。

    return 0;
}