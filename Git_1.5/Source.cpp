/*������ 9(G)
������� ��������� �������. ������ �����: �����������_�������� ��������.
�������� �������� (������ � ���, ������ � ������, ������ � ������)*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include "math.h"   

using namespace std;
void checkValue(string a, string b, float c, float &q);
void writeFile(float &q);
int main()
{
	setlocale(LC_ALL, "Russian");
	
	string a, b;
	float c;
	float q = 0;
	cout << "��������� ��(grad/h, grad/min, rad/min):";
	cin >> a;
	cout << "�(grad/h, grad/min, rad/min):";
	cin >> b;
	cout << "�������� = ";
	cin >> c;
	checkValue(a, b, c, q);
	writeFile(q);

	getchar();
	getchar();
	return 0;
}
void checkValue(string a, string b, float c, float &q){
	if (a == "grad/h" & b == "grad/min")
		q = c / 60;
	if (a == "grad/h" & b == "rad/min")
		q = M_PI / (180 * 60 * c);
	if (a == "grad/min" & b == "grad/h")
		q = c * 60;
	if (a == "grad/min" & b == "rad/min")
		q = M_PI / (180 * 60 * 60 * c);
	if (a == "rad/min" & b == "grad/h")
		q = (180 * 60 * c) / M_PI;
	if (a == "rad/min" & b == "grad/min")
		q = (180 * 60 * c) / (M_PI * 60);
	if (q == 0)            //��� ������ �� ��, ��� �� �� ����� �������������� 0 ����-�� �� ���-��
		cout << "Error \n";
	if (q != 0)
		cout << fixed << setprecision(6) << q << endl;
	}
void writeFile(float &q) {
	ofstream f("Results.txt");
	f << fixed << setprecision(6) << q;
	f.close();

}