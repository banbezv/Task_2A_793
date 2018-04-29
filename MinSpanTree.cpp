#include"MinSpanTree.h"
MinSpanningTree::MinSpanningTree( const GraphMatrix1D &mxcpy ) : ostweight( 0 ) {
	mx = mxcpy;
}
MinSpanningTree::MinSpanningTree( const MinSpanningTree& socpy ) {
	mx = socpy.GetGraph( );
	mstree = socpy.mstree;
	ostweight = socpy.ostweight;
}
MinSpanningTree::MinSpanningTree( MinSpanningTree&& mov ) {
	mx = mov.mx;
	mstree = mov.mstree;
	ostweight = mov.ostweight;
	mov.mx = GraphMatrix1D( );
	mov.mstree = GraphMatrix1D( );
	mov.ostweight = 0;
}
MinSpanningTree& MinSpanningTree::operator=( const MinSpanningTree& socpy ) {
	mx = socpy.mx;
	mstree = socpy.mstree;
	ostweight = socpy.ostweight;
	return *this;
}
const GraphMatrix1D& MinSpanningTree::GetGraph( ) const {
	return mx;
}
const GraphMatrix1D& MinSpanningTree::GetTree( ) const {
	return mstree;
}
double MinSpanningTree::GetOstWeight( ) const {
	return ostweight;
}
void MinSpanningTree::BuildTree( ) {
	int n = mx.Count( );
	mstree = GraphMatrix1D( n );
	SNM trees( n ); // отдельные деревья
	set<EDGE> U; // множество рёбер, отсортированное по весу
	for ( int i = 0; i < n; i++ ) { // создание очереди (с приоритетом по весу ребра) рёбер
		vector<double> next = mx.GetOutEdges( i );
		for ( int j = 0; j < n; j++ ) if ( i < j ) U.insert( EDGE( next[ j ], min( i, j ), max( i, j ) ) );
	}
	ostweight = 0;
	while ( !U.empty( ) ) { // пока не просмотрим все рёбра
		EDGE de = *U.begin( ); // извлекаем ребро минимального веса
		U.erase( de );
		int a, b;
		double w;
		w = de.w;
		a = de.from;
		b = de.to;
		if ( trees.Get( a ) != trees.Get( b ) ) { // ребро соединяет различные деревья
			mstree.AddEdge( a, b, w ); // добавление ребра к MST
			ostweight += w; // подсчёт суммы рёбер остовного дерева с добавленным ребром
			trees.Union( a, b ); // объединение деревьев
		}
	}
}
