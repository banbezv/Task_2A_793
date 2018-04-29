#pragma once
#include<iostream>
#include<vector>
using namespace std;
struct EDGE { // ребро: вес, начальная и конечная вершины
	double w;
	int from, to;
	EDGE( double _w, int _from, int _to );
	bool operator<( const EDGE &cmp ) const; // для поддержки очереди с приоритетом по весу
		// (у рера с меньшим весом приоритет больше) для построения MST
};
class GraphMatrix1D { // граф на матрице смежности
private:
	vector<double> matrix; // матрица смежности
	int n; // кол-во вершин
public:
	GraphMatrix1D( );
	explicit GraphMatrix1D( int _n );
	explicit GraphMatrix1D( const GraphMatrix1D &cpy );
	GraphMatrix1D( GraphMatrix1D &&mov );
	GraphMatrix1D& operator=( const GraphMatrix1D &cpy );
	int Count( ) const; // получить кол-во вершин
	void AddOrientedEdge( int from, int to, double w ); // добавление ориентированного ребра
	void AddEdge( int from, int to, double w ); // добавление неориентированного (двунаправленного) ребра
	double GetWeight( int from, int to ) const; // получение веса ребра
	vector<double> GetOutEdges( int vert ); // получение строки матрицы смедности
	vector<double> GetInEdges( int vert ); // получение столбца матрицы смежности
	friend ostream& operator<<( ostream &os, GraphMatrix1D &graph ); // вывод матрицы смедности в консоль
};
