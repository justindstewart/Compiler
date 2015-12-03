#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int getRow(string);
int getCol(string);

int getCol(string code)
{
	if (code == "program")
		return 0;
	if (code == "a")
		return 1;
	if (code == "b")
		return 2;
	if (code == "c")
		return 3;
	if (code == "d")
		return 4;
	if (code == "0")
		return 5;
	if (code == "1")
		return 6;
	if (code == "2")
		return 7;
	if (code == "3")
		return 8;
	if (code == "4")
		return 9;
	if (code == "5")
		return 10;
	if (code == "6")
		return 11;
	if (code == "7")
		return 12;
	if (code == "8")
		return 13;
	if (code == "9")
		return 14;
	if (code == "+")
		return 15;
	if (code == "-")
		return 16;
	if (code == "*")
		return 17;
	if (code == "/")
		return 18;
	if (code == "integer")
		return 19;
	if (code == "write")
		return 20;
	if (code == "\"")
		return 21;
	if (code == "(")
		return 22;
	if (code == ")")
		return 23;
	if (code == ",")
		return 24;
	if (code == ";")
		return 25;
	if (code == ":")
		return 26;
	if (code == "=")
		return 27;
	if (code == "$")
		return 28;
	if (code == "begin")
		return 29;
	if (code == "end.")
		return 30;

	cout << endl << "Failed to find Column" << endl;
	system("pause");
}
int getRow(string poppedStack)
{
	if (poppedStack == "prog")
		return 0;
	if (poppedStack == "identifier")
		return 1;
	if (poppedStack == "a")
		return 2;
	if (poppedStack == "dec-list")
		return 3;
	if (poppedStack == "dec")
		return 4;
	if (poppedStack == "c")
		return 5;
	if (poppedStack == "type")
		return 6;
	if (poppedStack == "stat-list")
		return 7;
	if (poppedStack == "d")
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
	if (poppedStack == "e")
		return 14;
	if (poppedStack == "term")
		return 15;
	if (poppedStack == "q")
		return 16;
	if (poppedStack == "factor")
		return 17;
	if (poppedStack == "number")
		return 18;
	if (poppedStack == "b")
		return 19;
	if (poppedStack == "sign")
		return 20;
	if (poppedStack == "digit")
		return 21;
	if (poppedStack == "id")
		return 22;
	cout << endl << "Failed to find Row" << endl;
	system("pause");
}
int main()
{	// 0 = blank; 37 = lambda; 38-47 = 0-9; 48-51 = a-d; 52 = integer; + = 52; - = 53 0 = blank
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
	string temp;

	/*while (!inputFile.eof())
	{
		getline(inputFile, temp);
		lineOfCode += temp + " ";
	}*/

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

	cout << currentSyntax << endl;
	while (!stack.empty() && isValid == true)
	{

		if (stack.back() == currentSyntax)
		{
			stack.pop_back();
		
			cout << "Current Stack: ";
			for (vector<string>::iterator it = stack.begin(); it != stack.end(); ++it)
			{
				cout << *it;
			}

			cout << endl << "Matched: " << currentSyntax;
			//Read next syntax to look at
			inputFile >> currentSyntax;
			cout << endl << endl;
		}
		else if (stack.back() == "$")
		{
			stack.pop_back();
		}
		else
		{
			col = getCol(currentSyntax);
			row = getRow(stack.back());
			/*switch (word[wordCounter])
			{
			case 'i':
			{
				col = 0;
				break;
			}
			case '+':
			{
				col = 1;
				break;
			}
			case '-':
			{
				col = 2;
				break;
			}
			case '*':
			{
				col = 3;
				break;
			}
			case '/':
			{
				col = 4;
				break;
			}
			case '(':
			{
				col = 5;
				break;
			}
			case ')':
			{
				col = 6;
				break;
			}
			case '$':
			{
				col = 7;
				break;
			}

			}//END SWITCH*/

			/*switch (stack.back())
			{
			case 'E':
			{
				row = 0;
				break;
			}
			case 'Q':
			{
				row = 1;
				break;
			}
			case 'T':
			{
				row = 2;
				break;
			}
			case 'R':
			{
				row = 3;
				break;
			}
			case 'F':
			{
				row = 4;
				break;
			}
			}//END SWITCH*/

			stack.pop_back();

			if (grammarTable[row][col] != 0 && grammarTable[row][col] != 37)
			{
				for (int::reverse_iterator rit = grammarTable[row][col].rbegin(); rit != grammarTable[row][col].rend(); ++rit)
				{
					stack.push_back(*rit);
				}
			}

			if (grammarTable[row][col] == 0)
			{
				isValid = false;
			}


		}

		/*cout << "Current Stack: ";
		for (vector<char>::iterator it = stack.begin(); it != stack.end(); ++it)
		{
		cout << *it;
		}
		cout << endl << "Looking For: " << word[wordCounter] << endl << endl;
	}//END WHILE*/

	if (isValid)
	{
		cout << word << " is Valid." << endl;
	}
	else
	{
		cout << word << " is not valid." << endl;
	}
	
	system("pause");
	return 0;
}