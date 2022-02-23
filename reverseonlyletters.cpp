using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))&& i<s.size())
            {
                i++;
            } // find i
            while (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')) && j>0)
            {
                j--;
            }
            if (i<j)
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        return s;
    }
    string reverseOnlyLetters_V2(string s){
        int n = s.size();
        int left = 0 , right = n-1;
        while(true){
            while(left < right && !isalpha(s[left])){
                left ++;
            }
            while(right > left && !isalpha(s[right])){
                right --;
            }
            if(left >= right){
                break;
            }
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }

};

int main()
{
    Solution solution;
    string s = "Test1ng-Leet=code-Q!";
    cout << solution.reverseOnlyLetters(s) << endl;
    return 0;
}