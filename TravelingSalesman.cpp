#include"TravelingSalesman.h"
TravelingSalesman::TravelingSalesman( const GraphMatrix1D &mxcpy ) {
	length = 0;
	graph = mxcpy;
}
TravelingSalesman::TravelingSalesman( const TravelingSalesman& socpy ) {
	graph = socpy.graph;
	circle = socpy.circle;
	length = socpy.length;
}
TravelingSalesman::TravelingSalesman( TravelingSalesman&& mov ) {
	graph = mov.graph;
	circle = mov.circle;
	length = mov.length;
	mov.graph = GraphMatrix1D( );
	mov.circle = GraphMatrix1D( );
	mov.length = 0;
}
TravelingSalesman& TravelingSalesman::operator=( const TravelingSalesman& socpy ) {
	graph = socpy.graph;
	circle = socpy.circle;
	length = socpy.length;
	return *this;
}
const GraphMatrix1D& TravelingSalesman::GetGraph( ) const {
	return graph;
}
const GraphMatrix1D& TravelingSalesman::GetCircleGraph( ) const {
	return circle;
}
double TravelingSalesman::GetLength( ) const {
	return length;
}
void TravelingSalesman::BuildCircleGraph( ) {
	MinSpanningTree MST( graph );
	MST.BuildTree( ); // получаем MST для построоения искомого цикла
	GraphMatrix1D mstree( MST.GetTree( ) );
	int n = graph.Count( );
	circle = GraphMatrix1D( n );
	vector<bool> visited( n );
	visited.assign( n, false );
	visited[ 0 ] = true;
	int last = 0;
	stack<int> st;
	st.push( 0 );
	int current;
	while ( !st.empty( ) ) { // строим цикл обходом dfs
		current = st.top( );
		st.pop( );
		if ( !visited[ current ] ) {
			circle.AddEdge( last, current, graph.GetWeight( last, current ) ); // добавление ребра в цикл
			length += graph.GetWeight( last, current ); // пресчёт длины цикла
			last = current; // теперь текущая вершина считается last
		}
		visited[ current ] = true;
		for ( int i = 0; i < n; i++ ) if ( mstree.GetWeight( current, i ) > 0 && !visited[ i ] ) st.push( i ); // по условию гарантируется w>0
	}
}
