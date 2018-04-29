#pragma once
#include<vector>
#include<set>
#include<time.h>
#include"graph.h"
#include"TravelingSalesman.h"
#define M_PI 3.14159265358979323846
using namespace std;
bool BruteForce( vector<int>& seq ); // ������ ������� ���� ������������ ������ ����� �� 0 �� seq.size()-1
	// �� ����� ���� �� ����, ������ ������ ����� 0, �.�. ��� �� ��������� ����������� ������ ������. ������� �������
	// �������������� ������ � ����� �������� ���� ������ � �����. (*����� �������� �� ��� �� ����������, �� �� <=9 ����������).
void BoxMullerConverting( vector<pair<double,double>>& points ); // �������������� ������ ����� � ������������ � ������������� (0;1]
	// (������ ��� �������) �����-�������
double EstimateApproximation( int N ); // ������ ����������� �� ��������� ������ �� n ��������� ������������� �� ��������� � ���������� 1 �����
vector<pair<double,double>> EstimateExperiment( int K, int LEFT, int RIGHT ); // ��������� �������� �������� �
	// ������������������� ���������� ����������� �� ��������� ������� ����� � ���������� �� LEFT ������� �� RIGHT �������
	// ��� ������� ���-�� ����� s (�� ������� [LEFT;RIGHT]) ������������ K �������� �������������
