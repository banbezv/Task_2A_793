#pragma once
#include<iostream>
#include<vector>
using namespace std;
struct EDGE { // �����: ���, ��������� � �������� �������
	double w;
	int from, to;
	EDGE( double _w, int _from, int _to );
	bool operator<( const EDGE &cmp ) const; // ��� ��������� ������� � ����������� �� ����
		// (� ���� � ������� ����� ��������� ������) ��� ���������� MST
};
class GraphMatrix1D { // ���� �� ������� ���������
private:
	vector<double> matrix; // ������� ���������
	int n; // ���-�� ������
public:
	GraphMatrix1D( );
	explicit GraphMatrix1D( int _n );
	explicit GraphMatrix1D( const GraphMatrix1D &cpy );
	GraphMatrix1D( GraphMatrix1D &&mov );
	GraphMatrix1D& operator=( const GraphMatrix1D &cpy );
	int Count( ) const; // �������� ���-�� ������
	void AddOrientedEdge( int from, int to, double w ); // ���������� ���������������� �����
	void AddEdge( int from, int to, double w ); // ���������� ������������������ (����������������) �����
	double GetWeight( int from, int to ) const; // ��������� ���� �����
	vector<double> GetOutEdges( int vert ); // ��������� ������ ������� ���������
	vector<double> GetInEdges( int vert ); // ��������� ������� ������� ���������
	friend ostream& operator<<( ostream &os, GraphMatrix1D &graph ); // ����� ������� ��������� � �������
};
