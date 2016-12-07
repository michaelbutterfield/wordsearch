//MICHAEL BUTTERFIELD
//			G20683057
//CO1401 Puzzle Assignment

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------Global Variables------------------------------------------------//
//Array sizes
const int wordsearchLines = 4;
const int wordsearchSize = 14;			//Make the sizes global variables so they don't have to be passed through all the functions- Saves a lot of headache
const int wordphraseSize = 48;			//Make the sizes global variables so they don't have to be passed through all the functions- Saves a lot of headache
										//Arrays
char wordSearch[wordsearchLines][wordsearchSize];		//Make the arrays global variables so they aren't determind by scope, meaning I'd have to create multiple arrays and read the file into multiple arrays
char searchPhrase[wordphraseSize];		//Make the arrays global variables so they aren't determind by scope, meaning I'd have to create multiple arrays and read the file into multiple arrays
int arr[wordphraseSize]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

//STRINGS
//Wordsearch Title
string wordsearchtitleOne = "-----WORDSEARCH PUZZLE------\n";	//Above the wordsearch to indicate such to the user
string wordsearchtitleTwo = "----------------------------\n";	//Buffer to make console look prettier
																//Wordsearch phrases title
string wordsearchphrasestitleOne = "-----WORDSEARCH PHRASES-----\n";	//Above the wordsearch phrases to show user what has been found in the wordsearch
string wordsearchphrasestitleTwo = "----------------------------\n";	//Buffer to make the console look prettier
																		//Found strings
string foundLine = " Found - Line ";	//These are used within the found statement when a word
string location = " Location ";			//has been located by the algorithm, it indicates the word that has been found,
string notFound = " Not Found...";		//the location and line it is on so you can trace the location
										//Space
string space = " ";
//Trademark strings
string trademarklineOne = "--CO1401 Puzzle Assignment--\n";		//"trademark" - showing who made the program and peronsal information
string trademarklineTwo = "-----Michael Butterfield----\n";
string trademarklineThree = "----------G20683057---------\n";
//Wordsearch INfile
string WordsearchInfile = "text2D.txt";		//string holding the name of the wordsearch text file, used to indicate which file has the information in to retrieve - char by char
string wordphrasesInfile = "search2D.txt";	//string holding the name of the wordsearch phrases text file, used to indicate which file has the information in to retrieve - char by char
string error = "ERROR: ";					//When the file can't be found, indicate it to the user
string cantOpen = "Can't open input file\n";//File not found, display problem
											//CHAR
char speechMark = '"';						//Used around the word found

											//NULL
int null = 0;	//0

				//NUMBERS
int one = 1;	//To plus one to the wordsearch algorith to check the next/previous character in the same row or next/previous line
int two = 2;	//To plus one to the wordsearch algorith to check the next/previous character in the same row or next/previous line

				//Structure to hold the characters
struct animal {
	char one;
	char two;
	char three;
};

//Trademark Program
void Trademark();
//Function to create space to make program look better
void SingleLineGap();
//Simple function to create space between viewable lines in the command window
void DoubleGapSpace();
//Pulls the wordsearch itself out of the text file and puts it into the global array wordSearch
void WordsearchFile();
//Pulls the phrases from the file as one long char string
void WordsearchPhrases();
//Wordsearch Title
void WordsearchTitle();
//Wordsearch Phrases Title
void WordsearchPhrasesTitle();

//Searches wordsearch for animals
void ExistsInArray(char charOne, char charTwo, char charThree);

//-----------------------------------------------Main Program-----------------------------------------------//
int main()
{
	Trademark();		//Display personal information of whose program it is

	SingleLineGap();	//Gap in console

	WordsearchFile();	//Functions to obtain both the word search and phrases
	WordsearchPhrases();

	WordsearchTitle();	//Display the title showing the user that this is the wordsearch being run through by the algorithm

						//Display the wordsearch	
	for (int j = null; j < wordsearchLines; j++)	//-- Double nested for loop for displaying the 2D array
	{												// Run through each row 0-3
		SingleLineGap();
		for (int i = null; i < wordsearchSize; i++)	// Run through each column of each row 0-14
		{
			cout << wordSearch[j][i] << space;		// Write out each character with a space inbetween (make it look better)
		}
	}

	DoubleGapSpace();								//Gap in console (make it look prettier and more viewable)

													//------PURELY FOR TESTING------
													//This displays the phrases by themselves without running the algorithm, read in character by character
													/*for (int i = null; i < wordphraseSize; i++)
													{
													cout << searchPhrase[i];
													}*/

													//Animal Structures										//I've put all the animals into structures in order to be able to search character by character
	animal Dog = {											//And partition each of the search phrases singularly
		{ searchPhrase[arr[0]] },		//-D
		{ searchPhrase[arr[1]] },		//-O				//I used structures and functions as it allows expandability- More words to add to the wordsearch? -- SHOULD HAVE USED VECTORS
		{ searchPhrase[arr[2]] },		//-G				//Just create a new structure for the word and call the function underneath the rest
	};

	animal Pig = {
		{ searchPhrase[arr[3]] },		//-P
		{ searchPhrase[arr[4]] },		//-I
		{ searchPhrase[arr[5]] },		//-G
	};

	animal Cat = {
		{ searchPhrase[arr[6]] },		//-C
		{ searchPhrase[arr[7]] },		//-A
		{ searchPhrase[arr[8]] },		//-T
	};

	animal Rat = {
		{ searchPhrase[arr[9]] },		//-R
		{ searchPhrase[arr[10]] },		//-A
		{ searchPhrase[arr[11]] },		//-T
	};

	animal Fox = {
		{ searchPhrase[arr[12]] },		//-F
		{ searchPhrase[arr[13]] },		//-O
		{ searchPhrase[arr[14]] },		//-X
	};

	animal Cow = {
		{ searchPhrase[arr[15]] },		//-C
		{ searchPhrase[arr[16]] },		//-O
		{ searchPhrase[arr[17]] },		//-W
	};

	animal Eel = {
		{ searchPhrase[arr[18]] },		//-E
		{ searchPhrase[arr[19]] },		//-E
		{ searchPhrase[arr[20]] },		//-L
	};

	animal Bee = {
		{ searchPhrase[arr[21]] },		//-B
		{ searchPhrase[arr[22]] },		//-E
		{ searchPhrase[arr[23]] },		//-E
	};

	animal Owl = {
		{ searchPhrase[arr[24]] },		//-O
		{ searchPhrase[arr[25]] },		//-W
		{ searchPhrase[arr[26]] },		//-L
	};

	animal Bat = {
		{ searchPhrase[arr[27]] },		//-B
		{ searchPhrase[arr[28]] },		//-A
		{ searchPhrase[arr[29]] },		//-T
	};

	animal Ant = {
		{ searchPhrase[arr[30]] },		//-A
		{ searchPhrase[arr[31]] },		//-N
		{ searchPhrase[arr[32]] },		//-T
	};

	animal Ape = {
		{ searchPhrase[arr[33]] },		//-A
		{ searchPhrase[arr[34]] },		//-P
		{ searchPhrase[arr[35]] },		//-E
	};

	animal Elk = {
		{ searchPhrase[arr[36]] },		//-E
		{ searchPhrase[arr[37]] },		//-L
		{ searchPhrase[arr[38]] },		//-K
	};

	animal Nit = {
		{ searchPhrase[arr[39]] },		//-N
		{ searchPhrase[arr[40]] },		//-I
		{ searchPhrase[arr[41]] },		//-T
	};

	animal Hen = {
		{ searchPhrase[arr[42]] },		//-H
		{ searchPhrase[arr[43]] },		//-E
		{ searchPhrase[arr[44]] },		//-N
	};

	animal Koi = {
		{ searchPhrase[arr[45]] },		//-K
		{ searchPhrase[arr[46]] },		//-O
		{ searchPhrase[arr[47]] },		//-I
	};

	WordsearchPhrasesTitle();			// Display the title showing the user that these are the phrases run through by the algorithm - showing which ones have been found and which ones were not

	SingleLineGap();					// Small gap in console- make the console look prettier


										//Call the functions to search the wordsearch
	ExistsInArray(Dog.one, Dog.two, Dog.three);		//Search for Dog- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Pig.one, Pig.two, Pig.three);		//Search for Pig- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Cat.one, Cat.two, Cat.three);		//Search for Cat- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Rat.one, Rat.two, Rat.three);		//Search for Rat- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Fox.one, Fox.two, Fox.three);		//Search for Fox- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Cow.one, Cow.two, Cow.three);		//Search for Cow- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Eel.one, Eel.two, Eel.three);		//Search for Eel- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Bee.one, Bee.two, Bee.three);		//Search for Bee- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Owl.one, Owl.two, Owl.three);		//Search for Owl- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Bat.one, Bat.two, Bat.three);		//Search for Bat- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Ant.one, Ant.two, Ant.three);		//Search for Ant- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Ape.one, Ape.two, Ape.three);		//Search for Ape- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Elk.one, Elk.two, Elk.three);		//Search for Elk- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Nit.one, Nit.two, Nit.three);		//Search for Nit- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Hen.one, Hen.two, Hen.three);		//Search for Hen- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word
	ExistsInArray(Koi.one, Koi.two, Koi.three);		//Search for Koi- Passes through the wordsearch needed and each of the characters in order to verify it is infact the word

	SingleLineGap();								//Create space between results and continue message
	system("pause");								//Allow the user to view the results
}
//---------------------END OF MAIN----------------------//


//Trademark Program
void Trademark()									//"trademark" - showing who made the program and peronsal information
{
	cout << trademarklineOne;						// Use the strings declared and initialised at the top of the program
	cout << trademarklineTwo;						// in order to display the personal information in the program
	cout << trademarklineThree;
}

//Simple function to create space between viewable lines in the command window
void SingleLineGap()
{
	cout << endl;
}

//Simple function to create space between viewable lines in the command window
void DoubleGapSpace()
{
	cout << endl << endl;
}

//----------------------------------------Word Search Itself--------------------------------------------//
//Pulls the wordsearch itself out of the text file and puts it into the global array wordSearch
void WordsearchFile()
{
	ifstream infile(WordsearchInfile);
	//infile.open("C:\\Users\\Michael\\Desktop\\WS V2.0\\text1.txt");
	if (!infile)			//If it can't open the infile
	{
		cout << error;		//Display these messages giving the user a visual response
		cout << cantOpen;
	}
	while (!infile.eof())	//While not the end of the file
	{
		for (int j = null; j < wordsearchLines; j++)	//Go through all the rows -0-3
		{
			for (int i = null; i < wordsearchSize; i++)	//Go through all the colums -0-14
			{
				infile >> wordSearch[j][i];				//Place each character from the infile into a char array- skipping the white space
			}
		}
	}
	infile.close();
}

//-----------------------------------------Word Search Phrases------------------------------------------//
//Pulls the phrases from the file as one long char string
void WordsearchPhrases()
{
	ifstream infile(wordphrasesInfile);				//Opens text file
													//infile.open("C:\\Users\\Michael\\Desktop\\WS V2.0\\search1.txt");
	if (!infile)									//if it can't open the file for any reason
	{
		cout << error;								//Display an error message
		cout << cantOpen;							//Very useful during testing, make sure you can open the file before trying to code any more
	}
	while (!infile.eof())							//While its not the end of the file
	{												//Put character by character the search phrases into an array
		for (int i = null; i < wordphraseSize; i++)	//Allows each character to be put into a seperate structure
		{											//Leading to each animal being individual
			infile >> searchPhrase[i];
		}
	}
	infile.close();
}


void ExistsInArray(char charOne, char charTwo, char charThree)
{
	bool found = false;										//Create a local bool of false as its only needed in this function- Efficiency
	int i;													//Global local variable within the scope, allows the location of the word to be used anywhere in the function

															//FORWARDS
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)				//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j][i + one] == charTwo && wordSearch[j][i + two] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;					// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;							//Breaks out of the function sooner- Meaning it won't display found & not found
				}
			}
		}
	}

	//BACKWARDS WORDS
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)				//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j][i - one] == charTwo && wordSearch[j][i - two] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;					// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;							//Breaks out of the function sooner- Meaning it won't display found & not found
				}
			}
		}
	}

	//DOWNWARDS
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)				//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j + one][i] == charTwo && wordSearch[j + two][i] == charThree)
				{

							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;					// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;							//Breaks out of the function sooner- Meaning it won't display found & not found
				}
			}
		}
	}

	//UPWARDS
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)				//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j - one][i] == charTwo && wordSearch[j - two][i] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;					// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;							//Breaks out of the function sooner- Meaning it won't display found & not found
				}
			}
		}
	}

	//DIAGONAL (DOWN RIGHT)
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)				//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j + one][i + one] == charTwo && wordSearch[j + two][i + two] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;					// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;							//Breaks out of the function sooner- Meaning it won't display found & not found
				}
			}
		}
	}

	//DIAGONAL (DOWN LEFT)
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)				//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j + one][i - one] == charTwo && wordSearch[j + two][i - two] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;					// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;							//Breaks out of the function sooner- Meaning it won't display found & not found
				}
			}
		}
	}

	//ORTHOGONAL (DOWN LEFT)
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)				//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j + one][i] == charTwo && wordSearch[j + one][i - one] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;					// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;							//Breaks out of the function sooner- Meaning it won't display found & not found
				}
			}
		}
	}

	//ORTHOGONAL (DOWN RIGHT)
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)			//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j + one][i] == charTwo && wordSearch[j + one][i + one] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;						// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;								//Breaks out of the function sooner- Meaning it won't display found & not found
				}
			}
		}
	}

	//ORTHOGONAL (RIGHT DOWN)
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)					//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j][i + one] == charTwo && wordSearch[j + one][i + one] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;						// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;								//Breaks out of the function sooner- Meaning it won't display found & not found				
				}
			}
		}
	}

	//ORTHOGONAL (LEFT DOWN)
	for (int j = null; j < wordsearchLines; j++)
	{
		for (i = null; i < wordsearchSize && found == false; i++)	//The addition of found == false allows the function to stop going through the for loop as soon as the word has been found
		{
			if (i > null && i < wordsearchSize)					//For when you want to search both forwards and backwards- Won't go out of the array
			{
				if (wordSearch[j][i] == charOne && wordSearch[j][i - one] == charTwo && wordSearch[j + one][i - one] == charThree)
				{
							cout << speechMark << charOne << charTwo << charThree << speechMark << foundLine << j + one << location << i << endl;
							found = true;						// IF FOUND - Bool changes to true -breaks out of function and displays that the word has been fonud with the location and line
							break;								//Breaks out of the function sooner- Meaning it won't display both found & not found
				}
			}
		}
	}

	if (found == false)											//For loop goes through entirely and doesn't find the word- The else statement of the function really
	{
		cout << speechMark << charOne << charTwo << charThree << speechMark << notFound << endl;
	}
}

void WordsearchTitle()				//Function to display the title above the wordsearch
{
	cout << wordsearchtitleOne;
	cout << wordsearchtitleTwo;
}


void WordsearchPhrasesTitle()		//Function to display the the title above the phrases the algorithm is searching for
{
	cout << wordsearchphrasestitleOne;
	cout << wordsearchphrasestitleTwo;
}