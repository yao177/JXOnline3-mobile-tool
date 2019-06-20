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

string Trim( string& str ) {
//	删除字符串中空格，制表符tab等无效字符
	str.erase( 0, str.find_first_not_of(" \t\r\n") );
	str.erase( str.find_last_not_of(" \t\r\n") + 1 );
	return str;
}

vector<string> places;
vector<string> region;
vector< set<string> > things;

vector< vector<int> > results;

bool cmp1( const vector<int> a, const vector<int> b ) {
	if ( a[1] != b[1] )	return a[1] > b[1];
	return a[0] < b[0];
}

bool cmp2( const vector<int> a, const vector<int> b ) {
	for ( int i = 2; i < a.size(); ++i ) {
		if ( a[i] != b[i] )	return a[i] > b[i];
	}
	return a[0] < b[0];
}

void print() {
	for ( int i = 0; i < places.size(); ++i ) {
		cout << region[i] << " | " << places[i];
		for ( auto it : things[i] ) {
			cout << " | " << it;
		}
		cout << endl;
	}
}


int main() { __
	
//	读入 csv 文件
	ifstream fin("resource.csv");
	string line;
	getline( fin, line );
	while ( getline( fin, line ) ) {
//		cout << "pre:" << line << endl;
		istringstream sin(line);
		vector<string> fields;
		string field;
		while ( getline( sin, field, ',' ) ) {
//			cout << field << '\t';
			fields.push_back( Trim( field ) );
		}
		places.push_back( fields[0] );
		region.push_back( fields[1] );
		set<string> tmp;
		for ( int i = 2; i < fields.size(); ++i ) {
			if ( fields[i] != "" ) {
				tmp.insert( fields[i] );
			}
		}
		things.push_back( tmp );
		
	}
	
//	print();
	
	string resource;
	vector<string> resources;
	while ( cin >> resource ) {
		if ( resource.size() == 1 ) {
			break;
		}
		resources.push_back( resource );
	}
	
	/**
	int type = 1;
	if ( resource == "2" ) {
		type = 2;
	}
	*/
	
	for ( int i = 0; i < places.size(); ++i ) {
		vector<int> result;
		result.push_back( i );
//		cout << result[0] << endl;
		result.push_back( 0 );
		for ( int j = 0; j < resources.size(); ++j ) {
			if ( things[i].count( resources[j] ) ) {
				result.push_back( 1 );
				++result[1];
			} else result.push_back( 0 );
		}
//		result.push_back( cnt );
		if ( result[1] )	results.push_back( result );
	}
	
	if ( resource == "2" ) {
		sort( results.begin(), results.end(), cmp2 );
	} else sort( results.begin(), results.end(), cmp1 );
	for ( int i = 0; i < results.size(); ++i ) {
		int num = results[i][0];
//		cout << num << endl;
		cout << endl;
		cout << results[i][1] << " | " << region[num] << " | " << places[num];
		for ( auto it : things[num] ) {
			cout << " | " << it;
		}
//		cout << endl;
	}
	return 0;
}
