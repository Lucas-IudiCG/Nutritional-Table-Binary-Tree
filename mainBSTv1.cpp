// mainBST.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include "BST.h"
using namespace std;

void PrintNode(NodeBST* node)
{
	if (node == nullptr) return;
  
	std::cout << "Nome:" << node->GetFood()
		<< node->GetData().PrintTabela() << '\n';
  
}

void Insert(BST* bst, std::string food, Alimento *data)
{
	
	NodeBST* node = bst->Insert(food, *data);
	/*if (node)
	{
		std::cout << "\n\nNode inserted:\n\n";
	}
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";*/
}

void Read(BST* bst){
  
  ifstream inFile;
  
  string food, calories, caloriesfromfat, totalfatg,totalfatdv,sodium,sodiumdv,potassiumg,potassiumdv,carbohydrateg,carbohydratedv, fiberg,fiberdv, sugarsg, proteing, vitadv, vitcdv, calciumdv,irondv, saturatedfatdv,saturatedfatmg, cholesteroldv, cholesterolmg, foodtype;
  
  inFile.open("NutritionalFacts_Fruit_Vegetables_Seafood.csv");
  
  while (!inFile.eof())
    {
      getline (inFile, food, ';');
      getline (inFile, calories, ';');
      getline (inFile, caloriesfromfat, ';');
      getline (inFile, totalfatdv, ';');
      getline (inFile, sodium, ';');
      getline (inFile, sodiumdv, ';');
      getline (inFile, potassiumg, ';');
      getline (inFile, potassiumdv, ';');
      getline (inFile, carbohydrateg, ';');
      getline (inFile, carbohydratedv, ';');
      getline (inFile, fiberg, ';');
      getline (inFile, fiberdv, ';');
      getline (inFile, sugarsg, ';');
      getline (inFile, proteing, ';');
      getline (inFile, potassiumdv, ';');
      getline (inFile, vitcdv, ';');
      getline (inFile, vitadv, ';');
      getline (inFile, calciumdv, ';');
      getline (inFile, irondv, ';');
      getline (inFile, saturatedfatdv, ';');
      getline (inFile, saturatedfatmg, ';');
      getline (inFile, cholesteroldv, ';');
      getline (inFile, cholesterolmg, ';');
      getline (inFile, foodtype, ',');
      //inFile >> foodtype;
      cout << foodtype;
      /*
      int icalories = stoi(calories);
      int icaloriesfromfat = stoi(caloriesfromfat);
      float itotalfatg = stof(totalfatg);
      int itotalfatdv = stoi(totalfatdv);
      int isodiumg = stoi(sodium);
      int isodiumdv = stoi(sodiumdv);
      int ipotassiumg = stoi(potassiumg);
      int ipotassiumdv = stoi(potassiumdv);
      int icarbohydrateg = stoi(carbohydrateg);
      int icarbohydratedv = stoi(carbohydratedv);
      int ifiberg = stoi(fiberg);
      int ifiberdv = stoi(fiberdv);
      int isugarsg = stoi(sugarsg);
      int iproteing = stoi(proteing);
      int ivitadv = stoi(vitadv);
      int ivitcdv = stoi(vitcdv);
      int icalciumdv = stoi(calciumdv);
      int iirondv = stoi(irondv);
      float isaturatedfatdv = stof(saturatedfatdv);
      int isaturatedfatmg = stoi(saturatedfatmg);
      int icholesteroldv = stoi(cholesteroldv);
      int icholesterolmg = stoi(cholesterolmg);*/
        
      Alimento* data = new Alimento(stoi(calories), stoi(caloriesfromfat), stof(totalfatg), stoi(totalfatdv), stoi(sodium), stoi(sodiumdv), stoi(potassiumg), stoi(potassiumdv), stoi(carbohydrateg), stoi(carbohydratedv), stoi(fiberg), stoi(fiberdv), stoi(sugarsg), stoi(proteing), stoi(vitadv), stoi(vitcdv), stoi(calciumdv), stoi(irondv), stof(saturatedfatdv), stoi(saturatedfatmg), stoi(cholesteroldv), stoi(cholesterolmg), foodtype);

      Insert(bst,food, data);
  }
  inFile.close();
}

/*

void Remove(BST* bst)
{
	int num;
	std::cout << "Remove number: ";
	std::cin >> num;
	bst->Remove(num);
}

void Search(BST* bst)
{
	int num;
	std::cout << "Search number: ";
	std::cin >> num;
	NodeBST* node = bst->Search(num);
	if (node)
	{
		std::cout << "Node found:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}
*/
void TraverseInOrder(BST* bst)
{
	std::cout << bst->TraverseInOrder() << '\n';
}
/*
void TraversePreOrder(BST* bst)
{
	std::cout << bst->TraversePreOrder() << '\n';
}

void TraversePostOrder(BST* bst)
{
	std::cout << bst->TraversePostOrder() << '\n';
}
*/

int main()
{
	 
	BST* bst = new BST();
  Read(bst);
  //TraverseInOrder(bst);
	/*
	int option = 0;
	do
	{
		std::cout << "*** BST Tree ***\n"
			<< "[1] Insert\n"
			<< "[2] Remove\n"
			<< "[3] Search\n"
			<< "[4] Traverse in-order\n"
			<< "[5] Traverse pre-order\n"
			<< "[6] Traverse post-order\n"
			<< "[7] Clear\n"
			<< "[0] Exit\nOption: ";
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		case 1: Insert(bst); break;
		case 2: Remove(bst); break;
		case 3: Search(bst); break;
		case 4: TraverseInOrder(bst); break;
		case 5: TraversePreOrder(bst); break;
		case 6: TraversePostOrder(bst); break;
		case 7: bst->Clear(); break;
		}
		std::cout << '\n';
	} while (option != 0);
  */
	delete bst;
	return 0;
}

