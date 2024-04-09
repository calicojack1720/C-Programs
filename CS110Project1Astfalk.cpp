/* Michael Astfalk
*  CS 110-02
*  Programming project 1
*  Due October 15, 2021
*  Objective: Select a restaraunt that meets specified dietary restrictions
*/

#include<iostream>
#include<string>
using namespace std;

int main(void) {
	//boolean variables for restaraunt requirements
	bool vegetarian, vegan, glutenFree, dairyFree;		

	//constant strings of the restaraunt names
	const string BOBS = "Bob's Burger Shack";
	const string ANGELOS = "Angelo's Awesome Pizzas";
	const string DINOS = "Dino's Diner";
	const string CASABLANCA = "Casablanca Mediterranean Cafe";
	const string SURF = "Surf Shack Tacos";
	const string ASIAN = "Asian Fusion";

	//string variable to hold the user's input
	string userIn;

	//check if restaurant should be vegetarian
	do
	{
		cout << "Is anyone in your group vegetarian?(Enter 'yes' or 'no')\n";
		cin >> userIn;

		//convert user input to lower case
		for (int i = 0; i < userIn.size(); ++i)
			userIn.at(i) = tolower(userIn.at(i));

		//check to see if user input is correct and output an error message if it is not
		if (userIn != "yes" && userIn != "no")
			cout << "\nERROR: Please enter either 'yes' or 'no'\n\n";
	} while (userIn != "yes" && userIn != "no");

	if (userIn == "yes")
		vegetarian = true;
	else
		vegetarian = false;

	//check if restaurant should be vegan
	do
	{
		cout << "\nIs anyone in your group vegan?(Enter 'yes' or 'no')\n";
		cin >> userIn;

		//convert user input to lower case
		for (int i = 0; i < userIn.size(); ++i)
			userIn.at(i) = tolower(userIn.at(i));

		//check to see if user input is correct and output an error message if it is not
		if (userIn != "yes" && userIn != "no")
			cout << "\nERROR: Please enter either 'yes' or 'no'\n\n";
	} while (userIn != "yes" && userIn != "no");

	if (userIn == "yes")
		vegan = true;
	else
		vegan = false;

	//check if restaurant should be gluten-free
	do
	{
		cout << "\nIs anyone in your group gluten-free?(Enter 'yes' or 'no')\n";
		cin >> userIn;

		//convert user input to lower case
		for (int i = 0; i < userIn.size(); ++i)
			userIn.at(i) = tolower(userIn.at(i));

		//check to see if user input is correct and output an error message if it is not
		if (userIn != "yes" && userIn != "no")
			cout << "\nERROR: Please enter either 'yes' or 'no'\n\n";
	} while (userIn != "yes" && userIn != "no");

	if (userIn == "yes")
		glutenFree = true;
	else
		glutenFree = false;

	//check if restaurant should be dairy-free
	do
	{
		cout << "\nIs anyone in your group dairy-free?(Enter 'yes' or 'no')\n";
		cin >> userIn;

		//convert user input to lower case
		for (int i = 0; i < userIn.size(); ++i)
			userIn.at(i) = tolower(userIn.at(i));

		//check to see if user input is correct and output an error message if it is not
		if (userIn != "yes" && userIn != "no")
			cout << "\nERROR: Please enter either 'yes' or 'no'\n\n";
	} while (userIn != "yes" && userIn != "no");

	if (userIn == "yes")
		dairyFree = true;
	else
		dairyFree = false;

	//Output available restaraunts
	//(all restaurants have vegetarian options so vegetarian is not checked)
	//(Dino's is always output because it accomodates all options)
	cout << "\nHere are your restaurant choices:\n" << "\t" << DINOS << endl;
	if (vegan == true)
	{
		if (glutenFree == false && dairyFree == false)
			cout << "\t" << SURF << endl;
	}
	else if (glutenFree == true)
	{
		cout << "\t" << BOBS << endl << "\t" << ASIAN << endl;
		if (dairyFree == false)
			cout << "\t" << CASABLANCA << endl;
	}
	else if (dairyFree == true)
		cout << "\t" << BOBS << endl;
	else
		cout << "\t" << BOBS << endl << "\t" << ANGELOS << endl << "\t" << CASABLANCA << endl << "\t" << SURF << endl << "\t" << ASIAN << endl;
	
	return 0;
}