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
#include <boost/regex.hpp>
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
  	boost::regex commentReg("\\(\\*.*?\\*\\)"); 				//Regular Expression to find anything beginning with //
  	boost::regex firstLine("\\s");						//Regular Expression to find any spaces
	ifstream ifs("data.txt");						//Input file
	ofstream ofs("data-clean.txt");						//Output file
	string reservedWords[3] = {"program", "INTEGER", "write"};		//Array of reserved words
	string sectionHeads[2] = {"begin", "var"};				//Array of section heads
	string temp;								//Temporary string to hold line and parse reserved words out
	size_t foundAt;								//Variable to hold the position the reserved word was found
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;	//Typedef the boost statement to tokenizer.
  	boost::char_separator<char> sep("",",;=+():*");				//Tokenizer by special chars
	string content( (istreambuf_iterator<char>(ifs) ),			//String variable fed an entire text file.
			(istreambuf_iterator<char>()    ));
	content = regex_replace (content, commentReg, "");			//Take out all comments
	content = regex_replace (content, firstLine, "");			//Take out all whitespace
	
	//Set the tokenizer with the string and delimiter setup.
  	tokenizer tokens(content, sep);
  	
  	//FOR - Loop through the string and take each token
  	for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
  	{
		temp = *tok_iter;
  		
		foundAt = temp.find(reservedWords[0]);
			
		//IF - If the string is found then insert a space.
		if(foundAt != string::npos)
		{
			temp.insert(foundAt + reservedWords[0].length(), " ");
		}//END IF
		
		for(int i = 0; i < 2; i++)
		{
			foundAt = temp.find(sectionHeads[i]);
			
			//IF - If the string is found then insert a space.
			if(foundAt != string::npos)
			{
				temp.insert(foundAt + sectionHeads[i].length(), "\n");
			}//END IF
		}//END FOR
  		
		ofs << temp;

		if(temp.compare("end.") != 0 && temp.compare(";"))
		{
			ofs << " ";
		}

		if(temp.compare(";") == 0)
		{
			ofs << endl;
		}

	}//END FOR
	
	return 0;
}
	
