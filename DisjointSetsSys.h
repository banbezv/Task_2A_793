#pragma once
#include<vector>
using namespace std;
class SNM { // система непересекающихся множеств
private:
	int n;
	vector<int> parents;
	vector<int> rang;
public:
	SNM( );
	explicit SNM( int _n );
	explicit SNM( const SNM& cpy );
	SNM( SNM&& mov );
	SNM& operator=( const SNM& cpy );
	int Get( int x );
	void Union( int x, int y );
};
