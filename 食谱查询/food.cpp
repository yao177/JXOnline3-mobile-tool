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

vector< pair<int, pair<int, int> > > res;
bool cmp( const pair<int, pair<int, int> > a, const pair<int, pair<int, int> > b ) {
	if ( a.second.first == b.second.first ) {
		return a.second.second > b.second.second;
	}
	return a.second.first > b.second.first;
}

/** 在比较时转换不好
vector< pair<int, string> > res;
bool cmp( const pair<int, string> a, const pair<int, string> b ) {
	int aa = atoi( a.second.c_str() );
	int bb = atoi( b.second.c_str() );
	return aa > bb;
}
*/

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
	
	
	string food;
	set<string> foods;
	/** 输入个数
	int num;
	cin >> num;
	while ( num-- ) {
		cin >> food;
		foods.insert( food );
	}
	*/
	
	while ( cin >> food ) {
		if ( food.size() == 1 )	break;
		foods.insert( food );
	}
	
	for ( int i = 0; i < name.size(); ++i ) {
		bool flag = true;
		for ( int j = 0; j < formula[i].size(); ++j ) {
			if ( foods.count( formula[i][j] ) == 0 ) {
				flag = false;
				break;
			}
		}
		/** 打印 - 1
		if ( flag ) {
			cout << name[i] << ',' << type[i] << ',';
			for ( int j = 0; j < formula[i].size(); ++j ) {
				cout << formula[i][j] << ',';
			}
			cout << hunger[i] << ',' << favor[i] << ',' << other[i] << ',' << remark[i] << endl;
		}
		*/
		
		/** 打印 - 2
		if ( flag ) {

		}
		*/
		
		if ( flag ) {
			
			res.push_back( make_pair( i, make_pair( atoi( hunger[i].c_str() ), atoi( favor[i].c_str() ) ) ) );
			
			/** 打印 - 1
			cout << name[i] << ',' << type[i] << ',';
			for ( int j = 0; j < formula[i].size(); ++j ) {
				cout << formula[i][j] << ',';
			}
			cout << hunger[i] << ',' << favor[i] << ',' << other[i] << ',' << remark[i] << endl;
			*/
			
			/** 打印 - 2
			cout << "菜名： " << name[i] << endl;
			cout << "类型： " << type[i] << endl;
			cout << "配方： ";
			for ( int j = 0; j < formula[i].size(); ++j ) {
				if ( j )	cout << ',';
				cout << formula[i][j];
			}
			cout << endl;
			cout << "饥饿： " << hunger[i] << endl;
			if ( favor[i] != "" )	cout << "好感： " << favor[i] << endl;
			if ( other[i] != "" )	cout << "效果： " << other[i] << endl;
			if ( remark[i] != "" )	cout << "备注： " << remark[i] << endl;
			cout << endl;
			*/
			
			/** 打印 - 3
			cout << name[i] << " | " << hunger[i] << " | " << type[i] << " | ";
			for ( int j = 0; j < formula[i].size(); ++j ) {
				if ( j )	cout << ',';
				cout << formula[i][j];
			}
			if ( favor[i] != "" )	cout << " | " << favor[i];
			if ( other[i] != "" )	cout << " | " << other[i];
			if ( remark[i] != "" )	cout << " | " << remark[i];
			cout << endl;
			*/
		}
//		cout << endl;
	}
	cout << endl;
	
	sort( res.begin(), res.end(), cmp );
//	for ( auto it : res )	cout << it.first << '|' << it.second << endl;
//	倒序打印
	for ( auto it : res ) {
		int i = it.first;
		cout << name[i] << " | " << hunger[i] << " | " << type[i] << " | ";
		for ( int j = 0; j < formula[i].size(); ++j ) {
			if ( j )	cout << ',';
			cout << formula[i][j];
		}
		if ( favor[i] != "" )	cout << " | " << favor[i];
		if ( other[i] != "" )	cout << " | " << other[i];
		if ( remark[i] != "" )	cout << " | " << remark[i];
		cout << endl;
	}
	
	return 0;
}
