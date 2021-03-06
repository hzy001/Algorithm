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

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

inline int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

#define INF 1000000000

class AllButOneDivisor {
public:
    int getMinimum(vector <int> div) {
        int n = div.size();
        int res = INF;
        REP(i,n) {
            int t = 1;
            REP(j,n) {
                if (j == i) continue;
                t = lcm(t, div[j]);
            }
            if ((t % div[i]) != 0) {
                res = min(res, t);
            }
        }
        if (res == INF) res = -1;
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int divisorsARRAY[] = {2,3,5};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(0, theObject.getMinimum(divisors),6);
    }
    {
        int divisorsARRAY[] = {2,4,3,9};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(1, theObject.getMinimum(divisors),12);
    }
    {
        int divisorsARRAY[] = {3,2,6};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(2, theObject.getMinimum(divisors),-1);
    }
    {
        int divisorsARRAY[] = {6,7,8,9,10};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(3, theObject.getMinimum(divisors),360);
    }
    {
        int divisorsARRAY[] = {10,6,15};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(4, theObject.getMinimum(divisors),-1);
    }
    return 0;
}
// END CUT HERE
