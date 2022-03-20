#include <bits/stdc++.h>
using namespace std;

vector<string> missingWords(string s, string t) {
   
    vector <string> tokens;
	
	// stringstream class check1
	stringstream check1(s);
	
	string intermediate;
	
	// Tokenizing w.r.t. space ' '
	while(getline(check1, intermediate, ' '))
	{
		tokens.push_back(intermediate);
	}
	
	vector <string> tokens1;
	
	// stringstream class check1
	stringstream check2(t);
	
	string inter;
	
	// Tokenizing w.r.t. space ' '
	while(getline(check2, inter, ' '))
	{
		tokens1.push_back(inter);
	}
	// Printing the token vector
	vector<string> missing ;
	for(int i=0, j=0; i < tokens.size(); i++){
		if(tokens[i] != tokens1[j]) {
			missing.push_back(tokens[i]);
		} else {
			j++;
		}
	}
	
	 return missing ;

}

int main(){

    string s="i like cheese";
    string t="like";

    vector<string> str = missingWords(s,t);
    for(auto i:str){
        cout<<i<<endl;
    }
    return 0;
}