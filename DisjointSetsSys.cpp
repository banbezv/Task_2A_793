#include"DisjointSetsSys.h"
SNM::SNM( ) : n( 0 ) { }
SNM::SNM( int _n ) {
	n = _n;
	parents.resize( n );
	rang.resize( n );
	for ( int i = 0; i < n; i ++ ) {
		parents[ i ] = i;
		rang[ i ] = 0;
	}
}
SNM::SNM( const SNM& cpy ) {
	n = cpy.n;
	rang = cpy.rang;
	parents = cpy.parents;
}
SNM::SNM( SNM&& mov ) {
	n = mov.n;
	rang = mov.rang;
	parents = mov.parents;
	mov.n = 0;
	mov.rang = vector<int>( );
	mov.parents = vector<int>( );
}
SNM& SNM::operator=( const SNM& cpy ) {
	n = cpy.n;
	parents = cpy.parents;
	rang = cpy.rang;
	return *this;
}
int SNM::Get( int x ) {
	if ( parents[ x ] != x ) parents[ x ] = Get( parents[ x ] );
	return parents[ x ];
}
void SNM::Union( int x, int y ) {
	if ( ( x = Get( x ) ) == ( y = Get( y ) ) ) return;
	if ( rang[ x ] == rang[ y ] ) rang[ x ]++;
	if ( rang[ x ] > rang[ y ] ) parents[ y ] = x;
	else parents[ x ] = y;
}
