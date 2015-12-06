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
int main()
{
	ifstream ifs("data-clean.txt");						//Input file
	ofstream ofs;
	string reservedWords[6] = {"program", "var", "integer", 		//Array of reserved words
				   "begin", "write", "end."};
	string fileName;
	string varName;
	string assignName;
	string temp;								//Temporary string to hold line and parse reserved words out
	string temp2;	
	bool varRead;
	bool assignRead;	
	size_t foundAt;								//Variable to hold the position the reserved word was found
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;	//Typedef the boost statement to tokenizer.
  	boost::char_separator<char> lineSep("\n");				//Tokenize each line
	boost::char_separator<char> sep;
	//boost::char_separator<char> writeSep("(),")
	string content( (istreambuf_iterator<char>(ifs) ),			//String variable fed an entire text file.
			(istreambuf_iterator<char>()    ));
	
	//Set the tokenizer with the string holding the entire file and seperate it by new lines
  	tokenizer tokens(content, lineSep);

	varRead = false;
	assignRead = false;

  	//FOR - Loop through each new line
  	for(tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
  	{
  		//Set an additional tokenizer that breaks up the line by spaces and identifiers
  		tokenizer tokens2(*tok_iter, sep);

		assignName = *tok_iter;

		if(assignRead)
		{
			
			while(assignName.compare("end.") != 0)
			{
				tokenizer tokens3(assignName, sep);
				ofs << "\t";
				for(tokenizer::iterator tok_iter3 = tokens3.begin(); tok_iter3 != tokens3.end(); ++tok_iter3)
				{
					temp2 = *tok_iter3;

					if(temp2.compare("write") == 0)
					{
						ofs << "cout << ";
						while(temp2.compare(";") != 0)
						{
							++tok_iter3;
							temp2 = *tok_iter3;
							if(temp2.compare("(") != 0 && temp2.compare(")") != 0 && temp2.compare(",") != 0)
							{
								ofs << temp2 << " ";
							}
							else if(temp2.compare(",") == 0)
							{
								ofs << "<< ";
							}
						}
						
					}
					else
					{
						ofs << temp2 << " ";
					}
				}
				ofs << endl;
				tok_iter++;
				assignName = *tok_iter;
			}
			assignRead = false;
			ofs << "\treturn 0;\n";
			ofs << "}";
		}
		
		for(tokenizer::iterator tok_iter2 = tokens2.begin(); tok_iter2 != tokens2.end(); ++tok_iter2)
		{
			temp = *tok_iter2;
			if(varRead)
			{

				varName = temp;
				while(varName.compare(":") != 0)
				{
					ofs << " " << varName; 
					tok_iter2++;
					varName = *tok_iter2;
				}
				ofs << ";\n";
				varRead = false;
			}

			if(temp.compare(reservedWords[0]) == 0)
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
			else if(temp.compare(reservedWords[1]) == 0)
			{	
				ofs << "\tint"; 
				varRead = true;
			}
			else if(temp.compare(reservedWords[3]) == 0)
			{
				assignRead = true;
			}
		}
	}//END FOR

	ofs.close();
	return 0;
}
