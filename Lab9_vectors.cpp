// Lab9_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
// Example: g++ Lab9_vectors.cpp -o Lab9_vectors -std=c++11
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	int i;
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a template

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
		
	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
// PreCoded
	
	
	
	float temp;
	vector<float>v1;
	v1 = {34.2};
	vector<float>v2(v1);
	vector<float>v3 = v1;
	vector<float>v4(3,149.5);
	vector<float>v5(7);
	vector<float>v6{8.7,5,9.6};
	vector<float>v7 = {14,75,62.87}; 
//Everything from vector table 3.4
	
	for(auto i:v1)	
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v2)	
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v3)	
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v4)	
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v5)	
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v6)	
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v7)	
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
//Displaying vector table 3.4 stuff
	
	int tempInt;
	vector<int>v8(10);
	for( i=0; i<10; i++)
	{
		cout<<"Enter Numbers:"<<endl;
		cin>>tempInt; 
		v8[i] = tempInt;
		cout<<v8[i]<<endl;
	}
//  Exercise 3.14
	
	string tempString;
	vector<string>v9(5);
	for( i=0; i<5; i++)
	{
		cout<<"Enter Strings:"<<endl;
		cin>>tempString;
		v9[i] = tempString;
		cout<<v9[i]<<endl;
	}
// Exercise 3.15
		
	temp = v7.empty();
	cout<<temp<<endl;
	temp = v6.size();
	cout<<temp<<endl;
 	v6.push_back(1);
	cout<<"Push back"<<endl;
	for(auto i:v6)
		cout<<i<<endl;
	cout << "\n------------------------------------------------------------------" << endl;
 	temp = v4[1];
 	cout<<temp<<endl;
 	v7 = {8,7,6,5,4,3,2,1};
	v6 = v7;
 	if(v4 == v5) 
		cout << "The vectors are equal" << endl;
 	else 
		cout << "FAILURE" << endl;
 	if(v4 != v5) 
		cout << "The vectors are not equal" << endl;
 	else  
		cout <<"Still equal" << endl;
//Stuff from vector table 3.5
	
  
// ***********************************************************************
// Try all the wasy to initializa a vector shown in Table 3.4. Use the
// vectors above and/or declare new vectors.
// Some of those operations have already been used, but write your
// own examples.

// Do exercises 3.14 and 3.15 from Lippman (page 102)

// Try all the vector operations shown in table 3.5. Use the vectors above
// or define new ones. Try different types.
// ***********************************************************************

	return 0;
}