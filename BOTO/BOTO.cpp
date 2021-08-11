// BOTO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <chrono>




using namespace std;



struct node
{
	string data;
	node *before, *after;       //creates a CD linked list ;
};
typedef node *ptr;
ptr head, last, cura, curb, curc;
string i;                  //strings for counting and inatiating loading and saving algorithms ;; ex : output1 , output11


int fcounter = 2; // file name counter ;


static int r = 0;



void create_CD(string m)
{
	head = new node();  //creates CD while accepting 1 data ;
	head->data = m;
	last = head;
	head->after = head;
	last->before = head;


}
int print_CD()
{

	if (!head||!cura)
		return 0;
	cout << head->data << " ";
	cura = head;
	while (cura!= last)
	{                                //prints the CD list ;
		cura = cura->after;
		cout << cura->data << " ";
	}

	cout << "\n";

}

void addlast(string m)
{
	ptr temp = new node();
	temp->data = m;
	temp->before = last;   
	last->after = temp;
	last = temp;
	last->after = head;
	head->before = last;
}
int case_insensitive_match(string s1, string s2) {
	//convert s1 and s2 into lower case strings
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);   
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	if (s1.compare(s2) == 0)
		return 1; //The strings are same
	return 0; //not matched
}
/*void date_time() 
{
	auto start = std::chrono::system_clock::now();
	// Some computation here
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << std::ctime(&end_time) <<   "\n";
		
}*/



void save()
{
	
   cura = head;
   
	
   
	
	for (int k = 1;k <= i.length()+1;k++)   
		cura = cura->after;
	ofstream out("output"+to_string(fcounter++)+".txt");
	out << cura->data;                         
	out.close();
	i += "1";
	ofstream out2("i.txt");
	out2 << i;
	out2.close();
	
	

}
void load()
{
	ifstream f("i.txt");
	if (f)
	{
		ostringstream ss;
		ss << f.rdbuf();
		i = ss.str();
		f.close();
	}
	int j = 1;
	
	string data;
	while (j<i.length())
	{
		
		
		ifstream f1("output" + to_string(fcounter++) + ".txt");
		if (f1)
		{
			ostringstream ss;
			ss << f1.rdbuf();
			data = ss.str();
			f1.close();
		}
		addlast(data);
		j++;
		
	}
}




int FindText(string userStrr, string wordPhrase) 
{
	if (wordPhrase == "time" || wordPhrase == "date"||wordPhrase==" time"||wordPhrase==" date")
		return 111;
	if (wordPhrase == "count();")
		return 222;
	transform(userStrr.begin(), userStrr.end(), userStrr.begin(), ::tolower);
	transform(wordPhrase.begin(), wordPhrase.end(), wordPhrase.begin(), ::tolower);
	int numWords = 0;
	stringstream ss(userStrr);
	string word;

	while (ss >> word) {                                  //Find if a certain word occours in the user string ;
		if (word == wordPhrase) {
			numWords++;
		}
	}
	return numWords;
}

int SubString(string x)

{
	int count = 0;
	curb = head->after;
	while (curb != head)
	{
		int v = -1;  char cx[100]; char space = ' '; int spaces = 1; int v2 = 0;
		for (int i = 0; i < x.length(); i++)
		{
		if (x[i] == space)
		{
				v = i;
				for (int j = 0; j < v; j++)                     // this method seperates the sentence into multiple words
					cx[j] = x[j];
			                                                    //  and then adds each word to string y and sends it to FindText(y) method to count the words in the current sentence ;
			spaces++;
			cx[v] = NULL;
			while (1 == 1)
			{
				if (x[v] == space)
					v++;
				else
					break;

			}
			string y = cx;
			/*if (FindText(curb->data, y) == 111)
			{
				date_time();
					return 0;
			}*/
			if (FindText(curb->data, y) == 222)
			{
				curc = head->after;
				int ccc = 1;
				while (curc != head)
				{
					ccc++;
					curc = curc->after;
					cout << "The number of current output in storge is :" << ccc;
				}
				
				return 0;
			}
			if (FindText(curb->data, y) >= 2)
				count++;
			
		}
		 if(i>0)
			if (x[i - 1] == space)
			{
				while (1 == 1)
				{
					if (x[i] == space)
					{
						v2 = i;
						break;
					}
					if (x[i] != space && x[i] != NULL)
						i++;
					if (x[i] == NULL)
					{
						v2 = i;
						break;
					}

				}
				int k2 = 0;
				for (int k = v ; k < v2; k++)
				{

					cx[k2] = x[k];
					k2++;
				}
				cx[k2] = NULL;
				string y = cx;
				/*if (FindText(curb->data, y) == 111)
				{
					date_time();
					return 0;
				}*/
				if (FindText(curb->data, y) == 222)
				{
					curc = head->after;
					int ccc = 1;
					while (curc != head)
					{
						ccc++;
						curc = curc->after;
						cout << "The number of current output in storge is :" << ccc;
					}
					return 0;
				}
				if (FindText(curb->data, y) >= 2)
				{
					count++;
					i = v2 + 1;
				}
			}
		}
		if (count >= 2)
		{
			cout << curb->after->data;
			break;
		}
		else

			curb = curb->after;

	
	



	}
	if (curb != head)
		return 1;
	else
		return 0;
}


		
			
			
		


		
	
	
	
	



int AI(string x)
{
	/*if (x == "time" || x == "date" || x == "date and time" || x == "current time" || x == "current date" || x == "current date and time"  )
	{
		date_time();
		return 0;
	}*/
	cura = head;
	while (case_insensitive_match(cura->data,x)!=1)
	{
		cura = cura->after;
		if (cura == last )
			break;
	}
	if (case_insensitive_match(cura->data, x) != 1 && (cura->after = head) )       //Search in ignoring cases and returns the node after which contains the answer
	{
		
	if (SubString(x) == 1)
			cout<<"";
		else
		{





			//to the question ;
			addlast(x); save();
			string y;
			if (r % 2 == 0)
			{
				cout << "I don't know the answer, teach me what to say ..." << endl << "                                                     ";
				r++;
			}                                                                                       //reply when not having an answer is randomly selected ;
			else
			{
				cout << "No answer for that ! , What do i say ?" << endl;
				r++;
			}
			getline(cin, y);
			addlast(y); save();
			cout << y;

		}
			
	}
	else
	{
		
		


			cura = cura->after;
			cout << cura->data << endl;
		
		
	}


}


int main()
{
	cout << "Hi" << endl;
	int c = 0;
	create_CD("Hi");
	addlast("Hey ,how are you ?");
	load();
	
	
	
	
	
	

	string x;
	while (c == 0)
	{
		
		cout << "                                                     ";
		getline(cin , x);
		cout << endl;
		AI(x);
	}

	



	
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
