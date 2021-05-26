#include "Deikstra.h"
using namespace std;

int main()
{
	Deikstra Graph;
	string Begin, End;
	string file="graph.txt";
	cout << "Enter the city of departure: ";
	cin >> Begin;
	cout << "Enter the city of arrival: ";
	cin >> End;
	ofstream out;
	out.open(file);
	if (out.is_open())
	{
		out << "A;B;15;30";
		out << endl;
		out << "A;C;N/A;40";
		out << endl;
		out << "B;C;17;N/A";
		out << endl;
		out << "A;D;1;N/A";
		out << endl;
		out << "C;E;30;50";
		out << endl;
		out << "C;F;40;N/A";
		out << endl;
		out << "D;F;5;10";
		out << endl;
		out << "E;F;N/A;12";
	}
	out.close();
	Graph.ReadFromFile(file);
	int result = Graph.Alg(Begin, End);
	cout << "Least cost: " << result << endl;
	return 0;

}