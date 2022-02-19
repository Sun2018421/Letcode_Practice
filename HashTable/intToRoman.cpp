using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
class Solution{
    public:
    // V_1
    string intToRoman(int num){
        string ans = "";
        int Mnum = num / 1000;
        while(Mnum--)   ans.append("M");

        num = num % 1000;
        if(num >= 900){
            ans.append("CM");
            num -= 900;
        }
        else{
            int Dnum = num / 500;
            num -= Dnum * 500;
            while(Dnum --) ans.append("D");
     
        }

        if(num >=400){
            ans.append("CD");
            num -= 400;
        }else{
            int Cnum = num / 100;
            num -= Cnum * 100;
            while(Cnum-- ) ans.append("C");
        }


        if(num >= 90){
            ans.append("XC");
            num -= 90;
        }
        else{
            int Lnum = num / 50;
            num -= Lnum * 50;            
            while(Lnum --) ans.append("L");
        }

        if(num >=40){
            ans.append("XL");
            num -= 40;
        }else{
            int Xnum = num / 10;
            num -= Xnum * 10;            
            while(Xnum-- ) ans.append("X");
        }


        if(num >= 9){
            ans.append("IX");
            num -= 9;
        }
        else{
            int Vnum = num / 5;
            num -= Vnum * 5;
            while(Vnum --) ans.append("V");
        }

        if(num >=4){
            ans.append("IV");
            num -= 4;
        }else{
            int Inum = num / 1;
            num -= Inum * 1;            
            while(Inum-- ) ans.append("I");
        }

        return ans;
    }
    // V_2 模拟
    string intToRoman_V2(int num){
        const pair<int ,string > valueSymbols[]= {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},
            {90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},
            {4,"IV"},{1,"I"},
        };
        string roman;
        for(const auto &[value, symbol] : valueSymbols){
            while(num >= value){
                num -= value ;
                roman += symbol;
            }
            if (num == 0)
                break;
        }
        return roman;
    }
    // V_3 硬解码
    string intToRoman_V3(int num){
    const string thousands[] = {"", "M", "MM", "MMM"};
    const string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};

    }
};

int main(){
    Solution solution;
    cout << solution.intToRoman(1994)<<endl;
    return 0 ;
}