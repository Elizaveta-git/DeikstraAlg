#include "pch.h"
#include "CppUnitTest.h"
#include "../Deikstra.h"
#include "../Deikstra.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DeikstraAlgTests
{
	TEST_CLASS(DeikstraAlgTests)
	{
	public:
		
		TEST_METHOD(Deikstra_test1)
		{
			Deikstra Graph;
			ofstream out;
			out.open("graph.txt");
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
			Graph.ReadFromFile("graph.txt");
			Assert::AreEqual(Graph.Alg("C","F"), 40);
			Assert::AreEqual(Graph.Alg("A", "E"), 18);
			Assert::AreEqual(Graph.Alg("F", "B"), 117);
		}
		TEST_METHOD(Deikstra_test2)
		{
			Deikstra Graph;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
				out << "A;B;N/A;30";
				out << endl;
				out << "A;C;N/A;40";
				out << endl;
			}
			out.close();
			Graph.ReadFromFile("graph.txt");
			Assert::AreEqual(Graph.Alg("B", "A"), 30);
		}
	};
}
