#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct zipfRank{
	string w;
	int count;

	bool operator> (const zipfRank& rhs);
	bool operator< (const zipfRank& rhs);
};

bool zipfRank::operator> (const zipfRank& rhs){ return count > rhs.count; }
bool zipfRank::operator< (const zipfRank& rhs){ return count < rhs.count; }

void modifyscript()
{
	ifstream finp;
	ofstream fout;
	finp.open("script.txt");
	fout.open("modifiedscript.txt");
	char tmp;
	string stmp;
	if(finp.good()){
		while(!finp.eof()){
			getline(finp, stmp);
			for(int i = 0; i < stmp.size(); ++i){
				tmp = stmp[i];
				if( tmp != '.' &&  tmp != '-' && tmp != '?' && tmp != '!' && tmp != ','){
					fout << tmp;
				}
			}
		fout << '\n';
		}
	}
	else
		cout << "bad file" << endl;

	return;
}

vector<zipfRank> createList(){
	ifstream finp;
	finp.open("modifiedscript.txt");

	string word;
	int theCount = 0;
	int ofCount = 0;
	int toCount = 0;
	int aCount = 0;
	int inCount = 0;
	int isCount = 0;
	int iCount = 0;
	int thatCount = 0;
	int itCount = 0;
	int forCount= 0;

	int count = 0;


	vector<zipfRank> list;
	if(finp.good()){
		while(finp >> word){
			for(int i = 0; i<word.size(); ++i){
				char tmp;
				tmp = word[i];
				tmp = tolower(tmp);
				word[i] = tmp;
			}

			// cout << word << endl;
			if(word == "the") theCount++;
			if(word == "of") ofCount++;
			if(word == "to") toCount++;
			if(word == "a") aCount++;
			if(word == "in") inCount++;
			if(word == "is") isCount++;
			if(word == "i") iCount++;
			if(word == "that") thatCount++;
			if(word == "it") itCount++;
			if(word == "for") forCount++;

			
			
			count++;
		} // end while

		cout << "count: " << count << endl;
		cout << "theCount: " << theCount << endl;
		cout << "toCount: " << toCount << endl;
		cout << "aCount: " << aCount << endl;
		cout << "inCount: " << inCount << endl;
		cout << "isCount: " << isCount << endl;
		cout << "iCount: " << iCount << endl;
		cout << "thatCount: " << thatCount << endl;
		cout << "itCount: " << itCount << endl;
		cout << "forCount: " << forCount << endl;
		

		cout << endl;
		
		list.push_back({"count",count});
		list.push_back({"the", theCount});
		list.push_back({"to", toCount});
		list.push_back({"a", aCount});
		list.push_back({"in", inCount});
		list.push_back({"is", isCount});
		list.push_back({"i", iCount});
		list.push_back({"that", thatCount});
		list.push_back({"it", itCount});
		list.push_back({"for", forCount});


	}
	else{
		cout << "file bad" << endl;
	}


	return list;
}

int main()
{
	
	modifyscript();
	vector<zipfRank> vzipf = createList();
	// sort vector
	sort(vzipf.begin(), vzipf.end(), greater());
	for(int i = 0; i < vzipf.size(); ++i){
		if(i == 0)
			cout << vzipf[i].w << ": " << vzipf[i].count << endl;
		else
			cout << i << " " << vzipf[i].w << " " << vzipf[i].count << endl;

	}


	return 0;
}
