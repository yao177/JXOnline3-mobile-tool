#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define repd(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define ni(a) int a; scanf("%d", &a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define sc(a) scanf("%c", &a)
#define scc(a, b) scanf("%c%c", &a, &b)
#define sd(a) scanf("%lf", &a)
#define sdd(a, b) scanf("%lf%lf", &a, &b)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int inf = 2 * INF;
/*<----------------- York ------------------>*/
const int maxn = 1e3 + 3;

vector<string> name;
vector<string> type;
vector<string> hunger;
vector<string> favor;
vector<string> other;
vector<string> remark;
vector< vector<string> > formula;

map<string, int> sear;
vector<int> res;

string Trim( string& str ) {
	str.erase( 0, str.find_first_not_of(" \t\r\n") );
	str.erase( str.find_last_not_of(" \t\r\n") + 1 );
	return str;
}

void print( ) {
	for (int i = 0; i < name.size(); ++i) {
		cout << name[i] << ' ' << type[i] << ' ' << hunger[i] << ' ' << favor[i] << ' ' << other[i] << ' ' << remark[i];
		for ( auto it : formula[i] ) {
			cout << ' ' << it;
		}
		cout << endl;
	}
}

int main() { __
	
	ifstream fin("food.csv");
	string line;
	getline( fin, line );
	int cnt = 0;
	while ( getline( fin, line ) ) {
		istringstream sin(line);
		vector<string> fields;
		string field;
		while ( getline( sin, field, ',' ) ) {
			fields.push_back( field );
		}
		name.push_back( Trim( fields[0] ) );
		sear[ Trim( fields[0] ) ] = cnt++;
		type.push_back( Trim( fields[1] ) );
		hunger.push_back( Trim( fields[2] ) );
		favor.push_back( Trim( fields[3] ) );
		other.push_back( Trim( fields[4] ) );
		remark.push_back( Trim( fields[5] ) );
		vector<string> tmp;
		for (int i = 6; i < fields.size(); ++i) {
			if ( Trim( fields[i] ) != "" ) {
				tmp.push_back( Trim( fields[i] ) );
			}
		}
		formula.push_back( tmp );
	}
	
	string food, tmp;
	set<string> foods;
	cin >> food;
	while ( cin >> tmp ) {
		if ( tmp == "#" )	break;
		foods.insert( tmp );
	}
	if ( sear.find(food) == sear.end() )	exit(1);
	
	cout << endl;
	int f = sear[ food ];
	bool flag = true;
	for ( auto it : formula[f] ) {
		if ( !foods.count(it) ) {
			if ( flag ) {
				flag = false;
				cout << "缺： ";
			}
			cout << it << ',';
		}
	}
	cout << '\b';
	if ( flag ) {
		cout << "不缺！";
	}
	cout << endl << endl;
	
	cout << name[f] << " | " << hunger[f] << " | " << type[f] << " | ";
	for ( int j = 0; j < formula[f].size(); ++j ) {
		if ( j )	cout << ',';
		cout << formula[f][j];
	}
	if ( favor[f] != "" )	cout << " | " << favor[f];
	if ( other[f] != "" )	cout << " | " << other[f];
	if ( remark[f] != "" )	cout << " | " << remark[f];
	
	return 0;
}
