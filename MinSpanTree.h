#pragma once
/*
���������� mst ���������� ��������:
��������� ��� ���� ����� �� ����. ������� ��������� ������� ����� ���������� ���������.
���������� �� ��������������� ������������������ ���� �� �����������:
���� ����� ��������� ��� ��������� ������, ���������� ������� ���� ������.
���� ����� �������� ������� ������ ������ - ������ �����, �� ��� �����������.
� ����� �������� ���� ������ (���� - ���� ���� �������, ����� �������, ������� ��������� ���������), ���������� ��� �������,
� ������� ����������� ����� ���� - ����������� �������� ������.
*/
#include<vector>
#include<set>
#include<algorithm>
#include"graph.h"
#include"DisjointSetsSys.h"
using namespace std;
class MinSpanningTree {
private:
	GraphMatrix1D mx, mstree; // �������� ���� � �������������� ������
	double ostweight; // ��� MST
public:
	explicit MinSpanningTree( const GraphMatrix1D &mxcpy );
	explicit MinSpanningTree( const MinSpanningTree& socpy );
	MinSpanningTree( MinSpanningTree&& mov );
	MinSpanningTree& operator=( const MinSpanningTree& socpy );
	const GraphMatrix1D& GetGraph( ) const; // �������� �������� ����
	const GraphMatrix1D& GetTree( ) const; // ��������MST
	double GetOstWeight( ) const; // �������� ��������� ��� MST
	void BuildTree( ); // ���������� MST
};
