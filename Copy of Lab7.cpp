/*
 ============================================================================
 Name        : Lab7.c
 Author      : Ian Naeger
 Version     :
 Copyright   : N/A
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

class Signal{ 

	private:
	public:
		int length;
		int max;
		int average;
		int k;
		vector<double>data; 
		void FindAverage( )
		{
			int k = 0;
			average = 0;
			while(k < length)
			{
				average = average + (int)data[k];
						k++;
			}
			average = average / length;
			// Finds the average of the array
		}
		void FindMax( )
		{
			int k = 0;
			max = 0;
			while(k < length)
			{
				if( data[k] > max )
				{
					max = data[k];
				}
				k++;
			}
			// Finds the max of the array
		}
		void ScaleIt( double scale );
		void OffsetIt( double offset );
		void StatIt(void);
		void CenterIt( double mean );
		void NormalizeIt( double max );
		void Sig_Info(void); 
		void Save_File( const char* Filename );
		void DoThings( Signal );
		Signal (void);
		Signal ( int num );
		Signal ( const char* Filename ); 
		~Signal(void); 
		double operator+(double);
		double operator*(double);
		//Makes the public bits of the class, including constructors and destructor
};

Signal operator+(Signal , Signal);

Signal::Signal ()
{
	length = 0;
	max = 0;
	k = 0; 
	data.resize(0,0);
	average = 0;

// Fills out Signal with default data 
}

Signal::Signal ( int num )
{ 
	k = 0;
	char *Filename = new char[50];

	sprintf(Filename, "Raw_data_%02d.txt", num);
	FILE *fp = fopen(Filename, "r");
	fscanf( fp , "%d %d" , &length , &max);
	while(k < length)
	{
		int temp;
		fscanf(fp,"%d\n",&temp);
		data[k] = temp;
		k++;
	}

	FindAverage();

	fclose(fp);
	delete[] Filename;
//Fills out Signal with data from number files	
} 

Signal::Signal ( const char* Filename)
{ 
	k = 0;

	char fileString[50];
	sprintf(fileString,"%s",Filename);
	FILE *fp = fopen(fileString, "r");

	fscanf( fp , "%d %d" , &length , &max);

	while(k < length)
	{
		int temp;
		fscanf(fp,"%d\n",&temp);
		data[k] = temp;

		k++;
	}

	FindAverage();

	fclose(fp);
	delete[] Filename;
//Fills out Signal with data from user inputted file	
}

Signal::~Signal()
{
//Destruct-o-trons things	
}

Signal operator+( Signal s1 , Signal s2 )
{
	int k = 0;
	Signal s3(1);
	if( s1.length != s2.length )
	{
		cout<<"ERROR"<<endl;
		return s3;
	}
	else
	{
		s3.length = s1.length;
		if( s1.max > s2.max )
		{
			s3.max = s1.max;
		}
		else 
			s3.max = s2.max;
		for( k = 0; k < s3.length; k++ )
		{
			s3.data[k] = s1.data[k] + s2.data[k];
		}
	}
		s3.FindAverage();
		return s3; 
	// Adds equal size signals 
}

double Signal::operator+( double off )
{
	double newval;
	newval = data[k] + off;
	return newval;
	//offsets a signal
}

double Signal::operator*( double scl )
{
	double newval;
	newval = data[k] * scl;
	return newval;
	//scales a signal
}


void Signal::ScaleIt( double scale )
{
	for(k = 0; k < length; k++)
	{
		data[k] = operator*(scale);
	}
// scales the array
}

void Signal::OffsetIt( double offset )
{
	for(k = 0; k < length; k++)
	{
		data[k]= operator+(offset);
	}
// offsets the array
}

void Signal::StatIt( )
{
	FindAverage();
	FindMax();
	//Finds Average and Max of data
}

void Signal::CenterIt( double mean )
{
	int k;
	for(k = 0; k < length; k++)
	{
		data[k] = data[k] - mean;
	}
// Centers the array
}

void Signal::NormalizeIt( double max )
{
	int k;
	for(k = 0; k < length; k++)
	{
		data[k] = data[k] / max;
	}
// normalizes the array
}

void Signal::Sig_Info( )
{ 
	FindAverage();
	FindMax();
	std::cout << "Length: " << length << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << "Average: " << average << std::endl; 
// prints some info from the signal
}

void Signal::Save_File( const char* Filename)
{ 
	int k = 1;
	//double* start = data;
	
	char fileString[50];
//	string fileString;
	sprintf(fileString,"%s",Filename);
	FILE *fp = fopen(fileString, "w");

	fprintf( fp , "%d %d\n" , length , max);
	
	while(k <= length)
	{
		fprintf(fp,"%lf\n",data[k]);
		//data++;
		k++;
	}
	//data = start;

	fclose(fp);
//Saves the updated file under a new name	
}

void Signal::DoThings( Signal Sig )
{
	int choice = 0; 
	double Scl , Off;
//	string Renamed; 
	char Renamed[50]; 
	
	do { 
	
	cout<<"Select an Option: \n1. Scale \n2. Offset \n3. Statistics \n4. Center \n5. Normalize \n6. Info \n7. Save \n8. Exit "<<endl;
	cin>>choice; 
	//Gets choice
	
	if( choice < 1 || choice > 8)
	{
		cout<<"ERROR: Incorrect Selection, try again. "<<endl; 
	//Error checking
	}
	
	if( choice == 1 )
	{
		cout<<"Enter a number for scaling: "<<endl; 
		cin>>Scl;
		
		cout<<"Scaling"<<endl;
		Sig.ScaleIt( Scl );
	
	// takes array, scales it, puts it in a new array and prints it to a file
	}
	else if( choice == 2 )
	{	
		cout<<"Enter a number for offsetting: "<<endl; 
		cin>>Off;
	
		cout<<"Offsetting"<<endl;
		Sig.OffsetIt( Off );
		
	// takes array, offsets it, puts it in a new array and prints it to a file
	}
	else if( choice == 3 )
	{
		cout<<"Printing Statistics"<<endl;
		Sig.StatIt(); 
	// finds the mean and max of the array and prints it to a file
	}
	else if( choice == 4)
	{
		cout<<"Centering"<<endl;
		Sig.CenterIt( Sig.average );
	// centers the array and prints it to a file
	}
	else if( choice == 5)
	{
		cout<<"Normalizing"<<endl;
		Sig.NormalizeIt( Sig.max );
	// normalizes the array and prints it to a file
	}
	else if( choice == 6)
	{
		cout<<"Printing Info"<<endl;
		Sig.Sig_Info();
	//Prints out info
	}
	else if( choice == 7)
	{
		cout<<"Enter name to save file as:"<<endl;
		cin>>Renamed;
		cout<<"Saving"<<endl;

		Sig.Save_File(Renamed);
	//Saves Files
	}
	else if( choice == 8)
	{
		cout<<"Exitting"<<endl; 
	//Exits the program
	}

	} while( choice != 8 ); 
}

int main(int argc , char **argv)
{
	int num = 0;
	int Def = 0;
	int FnF = 0;
	int nmF = 0;
	int k =0;
	int FlnmVDflt = 0;
//	string Filename;
	char *Filename = new char[100];
	
	while( k < argc )
	{
		
		if( strcmp( "-n" , argv[k]) == 0 )
		{
			k++;
			
			if( k >= (argc-1) )
			{ 
				num = 0;
			}
			else
			{
				num = atoi(argv[k]);
			}	
			nmF = 1;
		}

		else if(strcmp( "-f" , argv[k]) == 0 ) 
		{ 
			FnF = 1;
			k++;
			Filename = argv[(k)];
		}

		k++;
	//Gets command lines prompts
	}
	

	if(num == 0 && FnF == 0)
	{ 
		cout<<"MUST ENTER FILENAME OR USE DEFAULT: \n1. Enter Filename \n2. Default "<<endl; 
		cin>>FlnmVDflt;
		if( FlnmVDflt == 1)
		{
			cout<<"Enter Filename: "<<endl;
			cin>>Filename;
			FnF = 1;
		}
		else if( FlnmVDflt == 2)
		{ 
			Def = 1;
		}
	//Gets filename or uses default
	}

	if( Def == 1 )
	{
		Signal Sig;
		cout<<"THERE IS NOTHING IN THIS NOW!!! SOMETHINGS WON'T WORK WITH NOTHING IN IT!!!"<<endl;
		Sig.DoThings(Sig);
	// makes default signal	
	}
	else if( nmF == 1 )
	{
		Signal Sig ( num ); 
		Sig.DoThings(Sig);
	//makes num file signal	
	}
	else if( FnF == 1 )
	{ 
		Signal Sig ( Filename ); 
		Sig.DoThings(Sig);
	//makes user file signal	
	}
	
	return 0;
}
