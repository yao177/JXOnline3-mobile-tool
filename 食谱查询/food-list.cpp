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

string Trim( string& str ) {
//	删除字符串中空格，制表符tab等无效字符
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
//		cout << formula[i].size();
	}
}

int main() { __
	
//	读入 csv 文件
	ifstream fin("food.csv");
	string line;
	getline( fin, line );
	while ( getline( fin, line ) ) {
//		cout << "pre:" << line << endl;
		istringstream sin(line);
		vector<string> fields;
		string field;
		while ( getline( sin, field, ',' ) ) {
//			cout << field << '\t';
			fields.push_back( field );
		}
//		cout << endl;
		name.push_back( Trim( fields[0] ) );
		type.push_back( Trim( fields[1] ) );
		hunger.push_back( Trim( fields[2] ) );
//		if ( Trim( fields[3] ) != "" ) {
			favor.push_back( Trim( fields[3] ) );
//		} else favor.push_back( "0" );
		other.push_back( Trim( fields[4] ) );
		remark.push_back( Trim( fields[5] ) );
		vector<string> tmp;
		for (int i = 6; i < fields.size(); ++i) {
			if ( Trim( fields[i] ) != "" ) {
				tmp.push_back( Trim( fields[i] ) );
			}
		}
//		cout << tmp[tmp.size() - 1] << "what" << endl;
		formula.push_back( tmp );
	}
	
//	print();
	
	set<string> foods;
	for ( auto it : formula ) {
		for ( auto food : it ) {
			foods.insert( food );
		}
	}
	
	for ( auto it : foods ) {
		cout << it << endl;
	}
	return 0;
}
