using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
class Solution{
    public:
    // V_1 27ms
    int findContentChildern(vector<int>&g, vector<int>&s){
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        unsigned int count = 0 ;
        unsigned int gpoint = 0, spoint = 0;
        unsigned int gsize = g.size() , ssize = s.size();
        while(gpoint < gsize && spoint<ssize){
            if(g[gpoint] <= s[spoint]){
                count++;
                gpoint++;
                spoint++;
            }else{
                spoint++;
            }
        }
        // cout<< count<<endl;
        return count ;
    }

    // V_2 47ms
    int findContentChildern_V2(vector<int>&g, vector<int>&s){
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        unsigned int count = 0 ;
        unsigned int gpoint = 0, spoint = 0;
        unsigned int gsize = g.size() , ssize = s.size();
        for(auto &v:s){
          if (v >= g[gpoint]){
            count++;
            gpoint++;
            if(gpoint == gsize)
            break;
          }
        }
        // cout<< count<<endl;
        return count ;
    }


};

int main(){
    Solution solution;
    vector<int> g = {10,9,8,7};
    vector<int> s = {10,9,8,7};
    cout<< solution.findContentChildern_V2(g,s)<<endl;
    return 0 ;
}