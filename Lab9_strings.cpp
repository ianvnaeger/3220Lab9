// Lab9_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	string s1, s2("Hello"), s3 = "World";
	cout << "\nEnter a word:" << endl;
	cin >> s1;
	
	string s4(s1);
	
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;
	
	s1 = s2 + s3;
	cout << s1 << endl;

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************

	string s5("Five"), s6("Six"), s7("Seven"), s8("Eight");

	cout<<"First Thing "<<s2<<endl;

	cout<<"Second Thing "<<endl;
	cin>>s3;
	getline( cin , s5 );
	cout<<"Third Thing "<<s5<<endl; 
	cout<<"Fourth Thing "<<s5.empty()<<endl;
	cout<<"Fifth Thing "<<s4.size()<<endl;
	cout<<"Sixth Thing "<<s5[3]<<endl;
	cout<<"Seventh Thing "<<s6+s7<<endl;
	s6=s7;
	cout<<"Eighth Thing "<<s6<<endl;
	if( s6 == s7 )
	{
		cout<<"Nineth Thing "<<"s6 and s7 are equal!"<<endl;
	}
	if( s6 != s7 )
	{
		cout<<"Tenth Thing "<<"s6 and s7 are NOT equal!"<<endl;
	}
	if( s7 <= s8)
	{
		cout<<"Eleventh Thing "<<"s7 is less than or equal to s8!"<<endl;
	}
	if( s7 > s8)
	{
		cout<<"Twelveth Thing "<<"s7 is greater than s8!"<<endl;
	}
// All of these commands are in the order you find them on the table in the book

// -----------------------------------------------------------------------
	string line;
	int length , k;
	cout << "\nEnter some text, finish it with an &" << endl;
	getline(cin, line, '&');
	cout << line << endl;

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************
	length = line.length(); 
	
	int check1 = 2;
	int check2 = 8;
	string blah(".....");
	
	for(k = 0; k < length; k++)
	{
		if( (islower(line[k])) == check1 )
		{
			line[k] = toupper(line[k]);
		}
		else
		{ 
			line[k] = tolower(line[k]);
		}
	}
	
	cout<<line<<endl;
	
	for( k = 0; k < length; k++)
	{
		if( (isspace(line[k])) == check2 )
		{
			line[k] = blah[3]; 
		}
	}
	
	cout<<line<<endl;
// This code accomplishes everything asked in the instuctions above

	return 0;
}