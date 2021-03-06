#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = 999999999;
const int MAXN = 60;
int dp[MAXN][MAXN];

class CasketOfStar {
public:
    int get_ans(int left, int right, vector<int> weight){
        if(dp[left][right]!=-1)return dp[left][right];
        if(left + 1 == right || left==right){
            cout<<left<<" "<<right<<" "<<0<<endl;
            return 0;
        }

        int tmp_max = -INF;
        for(int i=left+1; i<right; i++){
            int left_val = get_ans(left, i, weight);
            int right_val = get_ans(i, right, weight);
            int add = weight[left]*weight[right] + left_val + right_val;
            tmp_max = max(add, tmp_max);
            //cout<<"at "<<left<<" "<<right<<" look "<<i<<" = "<<tmp_max<<" "<<left*right<<endl;
        }
        dp[left][right] = tmp_max;
        cout<<left<<" "<<right<<" "<<tmp_max<<endl;
        return tmp_max;
    }
    
    int maxEnergy(vector <int> weight) {
        int sz = weight.size();
        memset(dp, -1, sizeof(dp));
        int ans = get_ans(0, sz-1, weight);
        return ans;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    CasketOfStar *obj;
    int answer;
    obj = new CasketOfStar();
    clock_t startTime = clock();
    answer = obj->maxEnergy(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;
    
    vector <int> p0;
    int p1;
    
    {
    // ----- test 0 -----
    int t0[] = {1,2,3,4};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 12;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
    }
    {
    // ----- test 1 -----
    int t0[] = {100,2,1,3,100};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 10400;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
    }
    
    {
    // ----- test 2 -----
    int t0[] = {2,2,7,6,90,5,9};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 1818;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
    }
    
    {
    // ----- test 3 -----
    int t0[] = {477,744,474,777,447,747,777,474};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 2937051;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
    }
    
    {
    // ----- test 4 -----
    int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 13;
    all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
    // ------------------
    }
    
    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
