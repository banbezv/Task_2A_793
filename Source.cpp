#include<iostream>
#include<vector>
#include"Estimator.h"
int main( ) {
	for ( int s = 3; s <= 9; s++ ) { // включаем 3 для достижения 1-цы, но не включаем 1 и 2, т.к. лишние 1-цы в результате избыточны
		vector<pair<double,double>> res = EstimateExperiment( 200, s, s );
		cout << "s=" << s << " est=" << res[ 0 ].first << " q=" << res[ 0 ].second << endl; // среднее значение и среднеквадратичное отклонение
	}
	system("pause");
	return 0;
}
