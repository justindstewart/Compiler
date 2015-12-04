/*************************************************************************************************************************************************************************
* AUTHOR		: Richard Erdtsieck & Justin Stewart
* STUDENT ID    	: 890962574 & 890986904
* PROJECT		: Final
* CLASS 		: CSPC 323
* SECTION		: TTH: 4:00 - 5:20pm
* INSTRUCTOR    	: Dr. Ray Ahmadnia
* DUE DATE		: December 9, 2015
* COMPILE		: g++ -std=c++11 cleaner.cpp -lboost_regex -L/usr/lib/libboost_regex.so
**************************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <boost/tokenizer.hpp>

using namespace std;

/*************************************************************************************************************************************************************************
* PROGRAM NAME: C++ WHITESPACE/COMMENT CLEANER (CPPCC)
**************************************************************************************************************************************************************************
* PURPOSE: This program receives a text file that is filled with C++ code. It will first remove all comments, then remove all whitespace. After that it properly formats
*	   the file to be correct syntactically.
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
	size_t foundAt;								//Variable to hold the position the reserved word was found
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;	//Typedef the boost statement to tokenizer.
  	boost::char_separator<char> sep;					//Tokenizer by special chars
	string content( (istreambuf_iterator<char>(ifs) ),			//String variable fed an entire text file.
			(istreambuf_iterator<char>()    ));
	
	//Set the tokenizer with the string and delimiter setup.
  	tokenizer tokens(content, sep);
  	
  	//FOR - Loop through the string and take each token
  	for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
  	{
		if(temp.compare(reservedWords[0]) == 0)
		{
			fileName = *tok_iter;
			ofs.open(fileName.c_str());
			ofs << "#include <iostream>\n";
			ofs << "using namespace std;\n";
			ofs << "int main()\n";
			ofs << "{\n";
		}
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
		//else if(temp.compare(reservedWords[3]) == 0)
		//{
		//	++tok_iter;
		//	while(assignName.compare("end") != 0)
		//	{
		//		assignName = *tok_iter;
		//		if(assignName.compare("write") != 0)
		//		{
		//			ofs << assignName;
		//			if(assignName.compare(";") == 0)
		//			{
		//				ofs << endl;
		//			}
		//			else
		//			{
		//				ofs << " ";
		//			}
		//		}
		//	}
		//}
		else if(temp.compare(reservedWords[5]) == 0)
		{
			ofs << "\treturn 0;\n";
			ofs << "}";
		}

		
		temp = *tok_iter;
  		
		cout << "<" << temp << ">\n";
		
	}//END FOR

	ofs.close();
	return 0;
}
