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
				   "begin", "write", "end"};
	string fileName;
	string varName;
	string assignName;
	string temp;								//Temporary string to hold line and parse reserved words out
	bool varRead;
	bool assignRead;	
	size_t foundAt;								//Variable to hold the position the reserved word was found
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;	//Typedef the boost statement to tokenizer.
  	boost::char_separator<char> lineSep("\n");				//Tokenize each line
	boost::char_separator<char> sep;
	string content( (istreambuf_iterator<char>(ifs) ),			//String variable fed an entire text file.
			(istreambuf_iterator<char>()    ));
	
	//Set the tokenizer with the string and delimiter setup.
  	tokenizer tokens(content, lineSep);

	varRead = false;
	assignRead = false;

  	//FOR - Loop through the string and take each token
  	for(tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
  	{
  		//Set an additional tokenizer with special chars delimters.
  		tokenizer tokens2(*tok_iter, sep);
		assignName = *tok_iter;
		if(assignRead)
		{
			while(assignName.compare("end.") != 0)
			{
				ofs << "\t" << assignName << endl;
				tok_iter++;
				assignName = *tok_iter;
				//cout << assignName << endl;
			}
			assignRead = false;
			cout << assignName;
			temp = assignName;
		}
		
		for(tokenizer::iterator tok_iter2 = tokens2.begin(); tok_iter2 != tokens2.end(); ++tok_iter2)
		{
			temp = *tok_iter2;
			cout << temp << endl;
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
		/*
		//IF - If "program" is found, create a file based on the indentifier after program and output the header for the C++ file.
		if(temp.compare(reservedWords[0]) == 0)
		{
			fileName = *tok_iter;
			ofs.open(fileName.c_str());
			ofs << "#include <iostream>\n";
			ofs << "using namespace std;\n";
			ofs << "int main()\n";
			ofs << "{\n";
		}//IF - If var is found, begin by declaring the int type and output each identifier
		else if(temp.compare(reservedWords[1]) == 0)
		{	
			ofs << "\tint"; 
			
			while(varName.compare(":") != 0)
			{
				varName = *tok_iter;

				if(varName.compare(":") != 0)
				{
					ofs << " " << varName;	
				}

				++tok_iter;
			}
			ofs << ";\n";
		}
		else if(temp.compare(reservedWords[3]) == 0)
		{
			while(assignName.compare("end") != 0)
			{
				assignName = *tok_iter;
				if(assignName.compare("write") != 0)
				{
					ofs << assignName;
					if(assignName.compare(";") == 0)
					{
						ofs << endl;
					}
					else
					{
						ofs << " ";
					}
				}
				++tok_iter;
			}
		}
		else if(temp.compare(reservedWords[5]) == 0)
		{
			ofs << "\treturn 0;\n";
			ofs << "}";
		}

		
		temp = *tok_iter;
  		*/
	}//END FOR

	ofs.close();
	return 0;
}
