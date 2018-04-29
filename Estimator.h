#pragma once
#include<vector>
#include<set>
#include<time.h>
#include"graph.h"
#include"TravelingSalesman.h"
#define M_PI 3.14159265358979323846
using namespace std;
bool BruteForce( vector<int>& seq ); // полный перебор всех перестановок набора чисел от 0 до seq.size()-1
	// на самом деле не всех, первым всегда стоит 0, т.к. нам не интересны циклические сдвиги набора. Перебор наборов
	// осуществляется только с целью перебора всех циклов в графе. (*такой перебоор всё ещё не эффективен, но на <=9 достаточен).
void BoxMullerConverting( vector<pair<double,double>>& points ); // преобразование набора точек с координатами в полуинтервале (0;1]
	// (первый его вариант) Бокса-Мюллера
double EstimateApproximation( int N ); // оценка приближения на случайном наборе из n нормально распределённых на плоскости с дисперсией 1 точек
vector<pair<double,double>> EstimateExperiment( int K, int LEFT, int RIGHT ); // получение среднего значения и
	// среднеквадратичного отклонения приближения на случайных наборах точек в количестве от LEFT границы до RIGHT границы
	// для каждого кол-ва точек s (на отрезке [LEFT;RIGHT]) проихводится K случаный экспериментов
