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
	SNM trees( n ); // ��������� �������
	set<EDGE> U; // ��������� ����, ��������������� �� ����
	for ( int i = 0; i < n; i++ ) { // �������� ������� (� ����������� �� ���� �����) ����
		vector<double> next = mx.GetOutEdges( i );
		for ( int j = 0; j < n; j++ ) if ( i < j ) U.insert( EDGE( next[ j ], min( i, j ), max( i, j ) ) );
	}
	ostweight = 0;
	while ( !U.empty( ) ) { // ���� �� ���������� ��� ����
		EDGE de = *U.begin( ); // ��������� ����� ������������ ����
		U.erase( de );
		int a, b;
		double w;
		w = de.w;
		a = de.from;
		b = de.to;
		if ( trees.Get( a ) != trees.Get( b ) ) { // ����� ��������� ��������� �������
			mstree.AddEdge( a, b, w ); // ���������� ����� � MST
			ostweight += w; // ������� ����� ���� ��������� ������ � ����������� ������
			trees.Union( a, b ); // ����������� ��������
		}
	}
}
