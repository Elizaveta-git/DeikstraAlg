#include "Deikstra.h"

void Deikstra::ReadFromFile(string FileName)
{
	ifstream in(FileName);
	int weightTo, weightBack;
	string Date;
	if (in.is_open())
	{
		while (getline(in, Date))
		{
			int j = 0;
			string information[4];
			for (int i = 0; i < Date.size(); i++)//getting rid of symbols
			{
				if (Date[i] == ' ' || Date[i] == ';')
				{
					i++;
					j++;
				}
				information[j] += Date[i];
			}
			if (information[2] == "N/A")
			{
				weightTo = INT_MAX;
			}
			else
			{
				weightTo = stoi(information[2]);//converting a string to an integer value
			}
			if (information[3] == "N/A")
			{
				weightBack = INT_MAX;
			}
			else
			{
				weightBack = stoi(information[3]);//converting a string to an integer value
			}
			Ribs.push_back(information[0], information[1], weightTo);
			Ribs.push_back(information[1], information[0], weightBack);
		}
	}
	in.close();
}

int Deikstra::Alg(string Begin, string End)
{
	Rib* MinRibFromVert;
	Node* CurNode;
	NodeList AllNodes;
	AllNodes.push_back(Begin, 0);
	Rib* CurRib = Ribs.MinRibFromVertex(Begin);
	int minDistToVert = CurRib->weight;
	while (CurRib->To != End) //while there are untested vertices
	{
		CurNode = AllNodes.ReturnHead();
		minDistToVert = INT_MAX;
		while (CurNode != NULL)//while there is a vertex with a minimum distance
		{ 
			MinRibFromVert = Ribs.MinRibFromVertex(CurNode->vertex);//finds an unmarked vertex with a minimum distance from the given
			if (MinRibFromVert != NULL)//if there are unchecked vertices from the top
			{
				if ((MinRibFromVert->weight + CurNode->minDistTo) < minDistToVert)
				{
					CurRib = MinRibFromVert;// the shortest path from the vertex found in the previous steps to the new vertex
					minDistToVert = MinRibFromVert->weight + CurNode->minDistTo;  // remember the new minimum distance
				}
			}
			CurNode = CurNode->next;
		}
		Node* previousNode = AllNodes.Find(CurRib->from); // checked vertex from which the minimum distance is found
		AllNodes.push_back(CurRib->To, previousNode->minDistTo + CurRib->weight);
		minDistToVert = previousNode->minDistTo + CurRib->weight;
		Ribs.VertexProcessed(CurRib->To); // mark the vertex as checked
	}
	return minDistToVert;
}
