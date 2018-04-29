#pragma once
/*
Построение mst алгоритмом Крускала:
Сортируем все рёбра графа по весу. Считаем отдельные вершины графа отдельными деревьями.
Проходимся по отсортированной последовательности рёбер по возрастанию:
Если ребро соединяет два различных дерева, объединяем деревья этим ребром.
Если ребро соединет вершины одного дерева - создаёт циклы, мы его отбрасываем.
В итоге получаем одно дерево (одно - если граф связный, иначе столько, сколько компонент связности), содержащее все вершины,
и имеющее минимальную сумму рёбер - минимальное остовное дерево.
*/
#include<vector>
#include<set>
#include<algorithm>
#include"graph.h"
#include"DisjointSetsSys.h"
using namespace std;
class MinSpanningTree {
private:
	GraphMatrix1D mx, mstree; // исходный граф и результирующее дерево
	double ostweight; // вес MST
public:
	explicit MinSpanningTree( const GraphMatrix1D &mxcpy );
	explicit MinSpanningTree( const MinSpanningTree& socpy );
	MinSpanningTree( MinSpanningTree&& mov );
	MinSpanningTree& operator=( const MinSpanningTree& socpy );
	const GraphMatrix1D& GetGraph( ) const; // получить исходный граф
	const GraphMatrix1D& GetTree( ) const; // получитьMST
	double GetOstWeight( ) const; // получить суммарный вес MST
	void BuildTree( ); // построение MST
};
