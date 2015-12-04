#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int getRow(string);
int getCol(string);
int getCol(char);
vector<string> findPush(vector<string>, int);


int getCol(string code)
{
	if (code == "program")
		return 0;
	if (code == "integer")
		return 19;
	if (code == "write")
		return 20;
	if (code == "begin")
		return 29;
	if (code == "end.")
		return 30;


	cout << endl << "Failed to find Column" << endl;
	system("pause");
	return 0;
}

int getCol(char code)
{
	if (code == 'a')
		return 1;
	if (code == 'b')
		return 2;
	if (code == 'c')
		return 3;
	if (code == 'd')
		return 4;
	if (code == '0')
		return 5;
	if (code == '1')
		return 6;
	if (code == '2')
		return 7;
	if (code == '3')
		return 8;
	if (code == '4')
		return 9;
	if (code == '5')
		return 10;
	if (code == '6')
		return 11;
	if (code == '7')
		return 12;
	if (code == '8')
		return 13;
	if (code == '9')
		return 14;
	if (code == '+')
		return 15;
	if (code == '-')
		return 16;
	if (code == '*')
		return 17;
	if (code == '/')
		return 18;
	if (code == '"')
		return 21;
	if (code == '(')
		return 22;
	if (code == ')')
		return 23;
	if (code == ',')
		return 24;
	if (code == ';')
		return 25;
	if (code == ':')
		return 26;
	if (code == '=')
		return 27;
	if (code == '$')
		return 28;

	cout << endl << "Failed to find Column" << endl;
	system("pause");
	return 0;
}
int getRow(string poppedStack)
{
	if (poppedStack == "prog")
		return 0;
	if (poppedStack == "identifier")
		return 1;
	if (poppedStack == "A")
		return 2;
	if (poppedStack == "dec-list")
		return 3;
	if (poppedStack == "dec")
		return 4;
	if (poppedStack == "C")
		return 5;
	if (poppedStack == "type")
		return 6;
	if (poppedStack == "stat-list")
		return 7;
	if (poppedStack == "D")
		return 8;
	if (poppedStack == "stat")
		return 9;
	if (poppedStack == "write")
		return 10;
	if (poppedStack == "str")
		return 11;
	if (poppedStack == "assign")
		return 12;
	if (poppedStack == "expr")
		return 13;
	if (poppedStack == "E")
		return 14;
	if (poppedStack == "term")
		return 15;
	if (poppedStack == "Q")
		return 16;
	if (poppedStack == "factor")
		return 17;
	if (poppedStack == "number")
		return 18;
	if (poppedStack == "B")
		return 19;
	if (poppedStack == "sign")
		return 20;
	if (poppedStack == "digit")
		return 21;
	if (poppedStack == "id")
		return 22;
	cout << endl << "Failed to find Row" << endl;
	system("pause");
	return 0;
}
vector<string> findPush(vector<string> stack, int grammar)
{
	if (grammar == 1)
	{
		stack.push_back("end.");
		stack.push_back("stat-list");
		stack.push_back("begin");
		stack.push_back("dec-list");
		stack.push_back("var");
		stack.push_back(";");
		stack.push_back("identifier");
		stack.push_back("program");
		return stack;
	}
	if (grammar == 2)
	{
		stack.push_back("A");
		stack.push_back("id");
		return stack;
	}
	if (grammar == 3)
	{
		stack.push_back("A");
		stack.push_back("id");
		return stack;
	}
	if (grammar == 4)
	{
		stack.push_back("A");
		stack.push_back("digit");
		return stack;
	}
	if (grammar == 6)
	{
		stack.push_back(";");
		stack.push_back("type");
		stack.push_back(":");
		stack.push_back("dec");
		return stack;
	}
	if (grammar == 7)
	{
		stack.push_back("C");
		stack.push_back("identifier");
		return stack;
	}
	if (grammar == 8)
	{
		stack.push_back("dec");
		stack.push_back(",");
		return stack;
	}
	if (grammar == 10)
	{
		stack.push_back("integer");
		return stack;
	}
	if (grammar == 11)
	{
		stack.push_back("D");
		stack.push_back("stat");
		return stack;
	}
	if (grammar == 12)
	{
		stack.push_back("write");
		return stack;
	}
	if (grammar == 14)
	{
		stack.push_back("write");
		return stack;
	}
	if (grammar == 15)
	{
		stack.push_back("assign");
		return stack;
	}
	if (grammar == 16)
	{
		stack.push_back(";");
		stack.push_back(")");
		stack.push_back("identifier");
		stack.push_back("str");
		stack.push_back("(");
		stack.push_back("write");
		return stack;
	}
	if (grammar == 17)
	{
		stack.push_back("\"");
		stack.push_back("\"");
		return stack;
	}
	if (grammar == 19)
	{
		stack.push_back(";");
		stack.push_back("expr");
		stack.push_back("=");
		stack.push_back("identifier");
		return stack;
	}
	if (grammar == 20)
	{
		stack.push_back("E");
		stack.push_back("term");
		return stack;
	}
	if (grammar == 21)
	{
		stack.push_back("expr");
		stack.push_back("+");
		return stack;
	}
	if (grammar == 22)
	{
		stack.push_back("expr");
		stack.push_back("-");
		return stack;
	}
	if (grammar == 24)
	{
		stack.push_back("Q");
		stack.push_back("factor");
		return stack;
	}
	if (grammar == 25)
	{
		stack.push_back("Q");
		stack.push_back("factor");
		stack.push_back("*");
		return stack;
	}
	if (grammar == 26)
	{
		stack.push_back("Q");
		stack.push_back("factor");
		stack.push_back("/");
		return stack;
	}
	if (grammar == 28)
	{
		stack.push_back("identifier");
		return stack;
	}
	if (grammar == 29)
	{
		stack.push_back("number");
		return stack;
	}
	if (grammar == 30)
	{
		stack.push_back("(");
		stack.push_back("expr");
		stack.push_back(")");
		return stack;
	}
	if (grammar == 31)
	{
		stack.push_back("B");
		stack.push_back("digit");
		stack.push_back("sign");
		return stack;
	}
	if (grammar == 32)
	{
		stack.push_back("B");
		stack.push_back("digit");
		return stack;
	}
	if (grammar == 38)
	{
		stack.push_back("0");
		return stack;
	}
	if (grammar == 39)
	{
		stack.push_back("1");
		return stack;
	}
	if (grammar == 40)
	{
		stack.push_back("2");
		return stack;
	}
	if (grammar == 41)
	{
		stack.push_back("3");
		return stack;
	}
	if (grammar == 42)
	{
		stack.push_back("4");
		return stack;
	}
	if (grammar == 43)
	{
		stack.push_back("5");
		return stack;
	}
	if (grammar == 44)
	{
		stack.push_back("6");
		return stack;
	}
	if (grammar == 45)
	{
		stack.push_back("7");
		return stack;
	}
	if (grammar == 46)
	{
		stack.push_back("8");
		return stack;
	}
	if (grammar == 47)
	{
		stack.push_back("9");
		return stack;
	}
	if (grammar == 48)
	{
		stack.push_back("a");
		return stack;
	}
	if (grammar == 49)
	{
		stack.push_back("b");
		return stack;
	}
	if (grammar == 50)
	{
		stack.push_back("c");
		return stack;
	}
	if (grammar == 51)
	{
		stack.push_back("d");
		return stack;
	}
	if (grammar == 52)
	{
		stack.push_back("integer");
		return stack;
	}
	if (grammar == 53)
	{
		stack.push_back("+");
		return stack;
	}
	if (grammar == 54)
	{
		stack.push_back("-");
		return stack;
	}
	return stack;
}


int main()
{	// 0 = blank; 37 = lambda; 38-47 = 0-9; 48-51 = a-d; 52 = integer; 53 = +; 54 = -; 0 = blank
	//			0		1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19		20		21	22	23	24	25	26	27	28	29		30
	/*			Program	a	b	c	d	0	1	2	3	4	5	6	7	8	9	+	-	*	/	integer	write	"	(	)	,	;	:	=	$	begin	end
	Prog		1
	Identifier			2	2	2	2
	A					3	3	3	3	4	4	4	4	4	4	4	4	4	4	37	37	37	37							37	37	37	37	37			
	dec-list			6	6	6	6
	dec					7	7	7	7
	C																														8		37
	type																						52
	stat-list			11	11	11	11																	11	
	D					12	12	12	12																	12												37
	stat				15	15	15	15																	14
	write																								16
	str					37	37	37	37																			17
	assign				19	19	19	19		
	expr				20	20	20	20	20	20	20	20	20	20	20	20	20	20	20	20								20	
	E																			21	22									37		37
	term				24	24	24	24	24	24	24	24	24	24	24	24	24	24	24	24								24	
	Q																			37	37	25	26							37		37
	factor				28	28	28	28	29	29	29	29	29	29	29	29	29	29	29	29								30
	number								31	31	31	31	31	31	31	31	31	31	31	31
	B									32	32	32	32	32	32	32	32	32	32	37	37	37	37							37		37
	sign								37	37	37	37	37	37	37	37	37	37	52	53
	digit								38	39	40	41	42	43	44	45	46	47
	id					48	49	50	51
	*/

	fstream inputFile;

	inputFile.open("finalv2.txt");
	string lineOfCode = "";

							//   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 	
	int grammarTable[23][31] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 37, 37, 37, 37, 0, 0, 0, 0, 37, 37, 37, 37, 37, 0, 0, 0},
								{0, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 37, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37},
								{0, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 37, 37, 37, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 19, 19, 19, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 22, 0, 0, 0, 0, 0, 0, 37, 0, 37, 0, 0, 0, 0, 0},
								{0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 37, 25, 26, 0, 0, 0, 0, 37, 0, 37, 0, 0, 0, 0, 0},
								{0, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 37, 37, 37, 37, 0, 0, 0, 0, 37, 0, 37, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 52, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 48, 49, 50, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int row = 0;
	int col = 0;
	bool isValid = true;

	vector<string> stack;

	stack.push_back("$");
	stack.push_back("prog");

	string currentSyntax;

	inputFile >> currentSyntax;

	int counter = 0;

	while (!stack.empty() && isValid == true )
	{
		string temp (currentSyntax, counter, 1);
		
		if (stack.back() == currentSyntax)
		{
			cout << "Popped Value: " << stack.back() << endl;
			stack.pop_back();
		
			cout << "Matched: " << currentSyntax << endl;
			cout << "New Stack: ";
			for (vector<string>::iterator it = stack.begin(); it != stack.end(); ++it)
			{
				cout << *it << " ";
			}

			//Read next syntax to look at
			inputFile >> currentSyntax;
			cout << endl << endl;
		}
		else if (stack.back() == temp)
		{
			cout << "Popped Value: " << stack.back() << endl;
			stack.pop_back();

			cout << "Matched " << currentSyntax[counter] << endl;
			cout << "New Stack: ";
			for (vector<string>::iterator it = stack.begin(); it != stack.end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl << endl;
			
			counter++;
			if (counter >= currentSyntax.size())
			{
				counter = 0;
				inputFile >> currentSyntax;
			}

		}
		else if (stack.back() == "$")
		{
			stack.pop_back();
		}
		else
		{
			if (currentSyntax == "program" || currentSyntax == "integer" || currentSyntax == "write" || currentSyntax == "begin" || currentSyntax == "end.")
			{
				cout << "Looking For: " << currentSyntax << endl;
				col = getCol(currentSyntax);
			}
			else
			{
				cout << "Looking For: " << currentSyntax[counter] << endl;
				col = getCol(currentSyntax[counter]);
				//counter++;
			}

			row = getRow(stack.back());

			cout << "Popped Value: " << stack.back() << endl;
			stack.pop_back();

			if (grammarTable[row][col] != 0 && grammarTable[row][col] != 37)
			{
				stack = findPush(stack, grammarTable[row][col]);
			}
			cout << "New Stack: ";
			for (vector<string>::iterator it = stack.begin(); it != stack.end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl << endl;

			/*if (grammarTable[row][col] != 0 && grammarTable[row][col] != 37)
			{
				for (int::reverse_iterator rit = grammarTable[row][col].rbegin(); rit != grammarTable[row][col].rend(); ++rit)
				{
					stack.push_back(*rit);
				}
			}*/

			if (grammarTable[row][col] == 0)
			{
				isValid = false;
			}
		}
	}//END WHILE

	if (isValid)
	{
		cout << "Program is Valid." << endl;
	}
	else
	{
		cout << "Program is not valid." << endl;
	}
	
	system("pause");
	return 0;
}