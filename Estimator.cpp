#include"Estimator.h"
bool BruteForce( vector<int>& seq ) {
	int N = seq.size( ), i = N - 2;
	while ( i >= 0 && seq[ i ] >= seq[ i + 1 ] ) i --; // �������� ������� i � 0 �� ��������������
	if ( i == 0 ) return false; // ���� �� 1-� ������� �������� �� ���������� ���������� ������� ����������
	int l = i + 1; // ������ ������������ ����� �� ��������� �� i-� ������ ������� i-�� ����� ������
	for ( int j = i + 1; j < N; j++ ) if ( seq[ j ] < seq[ l ] && seq[ j ] > seq[ i ] ) l = j;
	swap( seq[ i ], seq[ l ] ); // ������ ��� ����� ������� � ������������� ��������� (����� i-��) � ������� �� �����������
	sort( seq.begin( ) + i + 1, seq.end( ) );
	return true;
}
void BoxMullerConverting( vector<pair<double,double>>& points ) { // �������������� �����-�������
	int n = points.size( );
	double r, f;
	for ( int i = 0; i < n; i ++ ) {
		r = points[ i ].first;
		f = points[ i ].second;
		points[ i ].first = ( -2 * log( r ) ) * cos( 2 * M_PI * f );
		points[ i ].second = ( -2 * log( r ) ) * sin( 2 * M_PI * f );
	}
}
double EstimateApproximation( int N ) { // �������� ����������� ����� ����� ��������������� ���������� � ������ �����������
	// ���� ������ ��������������� ������������ ���� ������������ ������� ������� ��������
	static bool first_call = true;
	if ( first_call ) { // ����������� �������������� ������������ ��� ��������� ������� (��� ���������� �����������)
		srand( time( 0 ) + clock( ) );
		first_call = false;
	}
	vector<pair<double,double>> points( N ); // ��������� ���� ������� �� ������������� (0;1]
	const int base = 100;
	set<pair<double,double>> st;
	// ��������� N ��������� ��������� ����� �� ��������� (0;1]
	for ( int i = 0; i < N; i++ ) for ( ; ; ) {
		points[ i ].first = double( rand( ) % base + 1 ) / base;
		points[ i ].second = double( rand( ) % base + 1 ) / base;
		if ( st.find( points[ i ] ) == st.end( ) ) {
			st.insert( points[ i ] );
			break;
		}
	}
	// �������� ������ �����, ��������� ������������� �� ��������� � ���������� 1.
	BoxMullerConverting( points );
	// ���������� ������� ����� ������������ ��� ����� �� ��������� (��� ����� - ���������� ����� �������)
	GraphMatrix1D graph( N );
	for ( int i = 0; i < N;i ++ )
		for ( int j = 0; j < N; j++ )
			graph.AddEdge( i, j, sqrt( pow( points[ i ].first - points[ j ].first, 2 ) + pow( points[ i ].second - points[ j ].second, 2 ) ) );
	TravelingSalesman komi( graph ); // �������� ��� ���� ����������� ����������
	komi.BuildCircleGraph( );
	// ����� ����������� ����
	vector<int> seq( N ); // ����� ����� �� 0 �� N ��� ������� �������� � ������� ��������������� �������� ����� ������������ ����� ������������
	for ( int i = 0; i < N; i++ ) seq[ i ] = i;
	double min_length = komi.GetLength( );
	do {
		double length = graph.GetWeight( seq[ N - 1 ], seq[ 0 ] );
		for ( int i = 1; i < N; i++ ) length += graph.GetWeight( seq[ i - 1 ], seq[ i ] );
		if ( min_length > length ) min_length = length;
	} while ( BruteForce( seq ) );
	return komi.GetLength( ) / min_length;
}
vector<pair<double,double>> EstimateExperiment( int K, int LEFT, int RIGHT ) {
	vector<pair<double,double>> res( RIGHT - LEFT + 1 );
	vector<double> vec( K );
	for ( int s = LEFT; s <= RIGHT; s++ ) {
		double sum = 0, est, q; // est - ������� ��������, q - ������������������ ����������
		for ( int i = 0; i < K; i++ ) {
			vec[i] = EstimateApproximation( s );
			sum += vec[ i ];
		}
		est = sum / K;
		q = 0.0;
		for ( int i = 0; i < K; i++ ) q += pow( vec[ i ] - est, 2 );
		q = sqrt( q / K );
		res[ s - LEFT ].first = est;
		res[ s - LEFT ].second = q;
	}
	return res; // ������� �������� � ������������������ ���������� ��� ���������������� s �� LEFT �� RIGHT � ������� ����������� s
}
