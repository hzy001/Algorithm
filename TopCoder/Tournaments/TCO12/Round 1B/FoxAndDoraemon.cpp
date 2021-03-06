// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

// BEGIN CUT HERE
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// END CUT HERE

// BEGIN CUT HERE
int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}
// END CUT HERE

class FoxAndDoraemon {
public:
    int minTime(vector <int> workCost, int splitCost) {
        priority_queue<int> que;
        REP(i,workCost.size()) que.push(-workCost[i]);
        while (que.size() > 1) {
            int a = que.top(); que.pop();
            int b = que.top(); que.pop();
            que.push(min(a, b) - splitCost);
        }
        return -que.top();
    }
};
// BEGIN CUT HERE
int main() {
    {
        int workCostARRAY[] = {1,2};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(0, theObject.minTime(workCost, 1000),1002);
    }
    {
        int workCostARRAY[] = {3,6,9,12};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(1, theObject.minTime(workCost, 1000),2012);
    }
    {
        int workCostARRAY[] = {1000,100,10,1};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(2, theObject.minTime(workCost, 1),1001);
    }
    {
        int workCostARRAY[] = {1712,1911,1703,1610,1697,1612};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(3, theObject.minTime(workCost, 100),2012);
    }
    {
        int workCostARRAY[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(4, theObject.minTime(workCost, 3000),15000);
    }
    {
        int workCostARRAY[] = {58};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(5, theObject.minTime(workCost, 3600),58);
    }
    return 0;
}
// END CUT HERE
