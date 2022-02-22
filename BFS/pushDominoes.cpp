using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
class Solution
{
public:
    //V_1 : 字符串模拟
    string pushDominoes(string domines)
    {
        const pair<string, int> type[] = {{"L", -1},
                                          {"R", 1},
                                          {".", 0}};
        int n = domines.length();
        int flag = 1;
        string temp = domines;
        while (n--)
        {
            temp = domines;
            flag = 1;
            for (int i = 0; i < domines.length(); i++)
            {
                if (domines[i] == '.')
                {
                    if (i == 0)
                    {
                        if (domines[i + 1] == 'L')
                        {
                            temp[i] = 'L';
                            flag = 0;
                        }
                    }
                    else if (i == domines.length() - 1)
                    {
                        if (domines[i - 1] == 'R')
                        {
                            temp[i] = 'R';
                            flag = 0;
                        }
                    }
                    else
                    {
                        if ((domines[i - 1] == 'L' && domines[i + 1] == 'R') ||
                            (domines[i - 1] == 'R' && domines[i + 1] == 'L'))
                        {
                        }
                        else if (domines[i + 1] == 'L')
                        {
                            temp[i] = 'L';
                            flag = 0;
                        }
                        else if (domines[i - 1] == 'R')
                        {
                            temp[i] = 'R';
                            flag = 0;
                        }
                    }
                }
            }
            domines = temp;
            if (flag == 1)
                break;
        }
        return domines;
    }

    // V_2: BFS
    string pushDominoes_V2(string domines){
        int n = domines.size();
        queue<int> q ;
        vector<int> time(n,-1);
        vector<string> force(n);
        for(int i = 0 ; i< n ; i++){
            if(domines[i] != '.'){
                q.emplace(i);
                time[i] = 0 ;
                force[i].push_back(domines[i]);
            }
        }
        string res(n,'.');
        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(force[i].size()==1){
                char f = force[i][0];
                res[i] = f;
                int ni = (f=='L')?(i-1):(i+1);
                if( ni>=0 and ni < n){
                    int t = time[i];
                    if (time[ni] == -1){
                        q.emplace(ni);
                        time[ni] = t+1;
                        force[ni].push_back(f);
                    }else if(time [ni] ==t+1){
                        force[ni].push_back(f);
                    }
                }
            }
        }
        return res;
    }

    // V_3:  模拟
    string pushDominoes_V3(string domines){
        int n = domines.size(),i = 0;
        char left = 'L';
        while( i <n ){
            int j = i ;
            while( j < n && domines[j]=='.'){
                j++;
            }
            char right = j <n ?domines[j] : 'R';
            if(left == right){
                while(i<j){
                    domines[i++] = right;
                }
            }
            else if(left == 'R' and right =='L'){
                int k = j -1;
                while(i < k){
                    domines[i++] = 'R';
                    domines[k--] = 'L';
                }
            }
            left = right;
            i = j+1;
        }
        return domines;
    }
};

int main()
{
    Solution solution;
    string dominoes = ".L.R...LR..L..";
    cout << solution.pushDominoes_V2(dominoes) << endl;
    return 0;
}