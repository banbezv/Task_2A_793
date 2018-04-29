#include"graph.h"
EDGE::EDGE( double _w, int _from, int _to ) : w( _w ), from( _from ), to( _to ) { }
bool EDGE::operator<( const EDGE &cmp ) const {
	if ( w < cmp.w ) return true;
	if ( w == cmp.w && from < cmp.from ) return true;
	if ( w == cmp.w && from == cmp.from && to < cmp.to ) return true;
	return false;
}
GraphMatrix1D::GraphMatrix1D( ) : n( 0 ) { }
GraphMatrix1D::GraphMatrix1D( int _n ) {
	n = _n;
	matrix.resize( n * n );
	matrix.assign( n * n, 0 );
}
GraphMatrix1D::GraphMatrix1D( const GraphMatrix1D &cpy ) {
	n = cpy.n;
	matrix = cpy.matrix;
}
GraphMatrix1D::GraphMatrix1D( GraphMatrix1D &&mov ) {
	n = mov.n;
	matrix = mov.matrix;
	mov.n = 0;
	mov.matrix = vector<double>();
}
GraphMatrix1D& GraphMatrix1D::operator=( const GraphMatrix1D &cpy ) {
	n = cpy.n;
	matrix = cpy.matrix;
	return *this;
}
int GraphMatrix1D::Count( ) const {
	return n;
}
void GraphMatrix1D::AddOrientedEdge( int from, int to, double w ) {
	matrix[ from * n + to ] += w;
}
void GraphMatrix1D::AddEdge( int from, int to, double w ) {
	matrix[ from * n + to ] += w;
	matrix[ to * n + from ] += w;
}
double GraphMatrix1D::GetWeight( int from, int to ) const {
	return matrix[ from * n + to ];
}
vector<double> GraphMatrix1D::GetOutEdges( int vert ) {
	return vector<double>( matrix.begin( ) + vert*n, matrix.begin( ) + ( vert + 1 ) * n ); // строка матрицы - исходящие рёбра
}
vector<double> GraphMatrix1D::GetInEdges( int vert ) {
	vector<double> res( n );
	for ( int i = 0; i < n; i ++ ) res[ i ] = matrix[ i * n + vert ]; // столбец матрицы - входящие рёбра
	return res;
}
ostream& operator<<( ostream &os, GraphMatrix1D &graph ) {
	int n = graph.Count( );
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) cout << graph.GetWeight( i, j ) << " ";
		cout << endl;
	}
	return os;
}
