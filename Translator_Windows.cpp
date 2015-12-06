/*************************************************************************************************************************************************************************
* AUTHOR		: Richard Erdtsieck & Justin Stewart
* STUDENT ID    	: 890962574 & 890986904
* PROJECT		: Final
* CLASS 		: CSPC 323
* SECTION		: TTH: 4:00 - 5:20pm
* INSTRUCTOR    	: Dr. Ray Ahmadnia
* DUE DATE		: December 9, 2015
* COMPILE		: g++ translator.cpp -o translate.o
**************************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <boost/tokenizer.hpp>

using namespace std;

/*************************************************************************************************************************************************************************
* PROGRAM NAME: TRANSLATOR
**************************************************************************************************************************************************************************
* PURPOSE: This program receives a text file that is filled with verified code. It will then translate the code into C++ to be compiled and run.
**************************************************************************************************************************************************************************/
int translate()
{
	ifstream ifs("finalv2.txt");						//Input file
	ofstream ofs;								//Output file
	string reservedWords[6] = { "program", "var", "integer", 		//Array of reserved words
		"begin", "write", "end." };
	string fileName;							//String to hold the file name to be opened after program is read
	string varName;								//String to hold variable names read from program
	string assignName;							//String to hold assignment names read from program
	string temp;								//Temporary string to hold line and parse reserved words out
	string temp2;								//Temporary string to hold tokens
	bool varRead;								//Boolean flag to specify we are reading in variables
	bool assignRead;							//Boolean flag to specify we are reading in assignment statements
	//size_t foundAt;								//Variable to hold the position the reserved word was found
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;	//Typedef the boost statement to tokenizer.
	boost::char_separator<char> lineSep("\n");				//Tokenize each line
	boost::char_separator<char> sep;					//Tokenize each identifier and special char
	string content((istreambuf_iterator<char>(ifs)),			//String variable fed an entire text file.
		(istreambuf_iterator<char>()));

	//Set the tokenizer with the string holding the entire file and seperate it by new lines
	tokenizer tokens(content, lineSep);

	varRead = false;
	assignRead = false;

	//FOR - Loop through each new line
	for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
	{
		//Set an additional tokenizer that breaks up the line by spaces and identifiers
		tokenizer tokens2(*tok_iter, sep);

		assignName = *tok_iter;

		//IF - Checks if the assignment read flag is set, if it is read in the assignment statements until end of program is reached.
		if (assignRead)
		{
			//WHILE - Loops through each token until end of program is reached, outputting each assignment statement.
			while (assignName.compare("end.") != 0)
			{
				//Set an additional tokenizer to further break up each token
				tokenizer tokens3(assignName, sep);
				ofs << "\t";

				//Loop through each token checking for write command due to special circumstances of output, otherwise output assignments as is.
				for (tokenizer::iterator tok_iter3 = tokens3.begin(); tok_iter3 != tokens3.end(); ++tok_iter3)
				{
					temp2 = *tok_iter3;

					//IF - Checks each token for write value, outputs cout statement instead and takes arguments out of parenthesis
					if (temp2.compare(reservedWords[4]) == 0)
					{
						ofs << "cout << ";
						//WHILE - Loops through tokens until end of line is found, delimited by ;
						while (temp2.compare(";") != 0)
						{
							++tok_iter3;
							temp2 = *tok_iter3;
							//IF - Checks to make sure (), are not output, if they are not found we output regularly
							if (temp2.compare("(") != 0 && temp2.compare(")") != 0 && temp2.compare(",") != 0)
							{
								ofs << temp2 << " ";
							}//IF - If comma is found, output another insertion operator for more than one argument
							else if (temp2.compare(",") == 0)
							{
								ofs << "<< ";
							}//END IF

						}//END WHILE

					}//Default case
					else
					{
						ofs << temp2 << " ";
					}//END IF

				}//END FOR (Loop through tokens)

				ofs << endl;
				tok_iter++;
				assignName = *tok_iter;
			}//END WHILE (Compare assign to "end."

			assignRead = false;
			ofs << "\treturn 0;\n";
			ofs << "}";
			return 0;
		}//END IF (assignRead)

		 //FOR - Loops through the line and sets flags if reserved words are found, and outputs variables.
		for (tokenizer::iterator tok_iter2 = tokens2.begin(); tok_iter2 != tokens2.end(); ++tok_iter2)
		{
			temp = *tok_iter2;

			//IF - Checks for variable read flag, outputs variable names.
			if (varRead)
			{
				varName = temp;

				//WHILE - Loops through variable declarations until a colon is reached
				while (varName.compare(":") != 0)
				{
					ofs << " " << varName;
					tok_iter2++;
					varName = *tok_iter2;
				}//END WHILE

				ofs << ";\n";
				varRead = false;
			}//END IF

			 //IF - Checks for reserved words and sets up header for output file, or sets flags to read in appropriately
			if (temp.compare(reservedWords[0]) == 0)
			{
				++tok_iter2;
				fileName = *tok_iter2;
				fileName.append(".cpp");
				ofs.open(fileName.c_str());
				ofs << "#include <iostream>\n";
				ofs << "using namespace std;\n";
				ofs << "int main()\n";
				ofs << "{\n";
			}//IF - If var is found, begin by declaring the int type and output each identifier
			else if (temp.compare(reservedWords[1]) == 0)
			{
				ofs << "\tint";
				varRead = true;
			}
			else if (temp.compare(reservedWords[3]) == 0)
			{
				assignRead = true;
			}//END IF

		}//END IF

	}//END FOR

	ofs.close();

	return 0;
}