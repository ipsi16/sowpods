#include<iostream>
#include<fstream>
#include<cstring>
#include<map>
using namespace std;

map<unsigned long int, string>  createAnagramMap(ifstream& myfile){
	char primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
	unsigned long product = 1;
	int index;
	string word;
	map<unsigned long int, string> anagram_map;    
    
    if (myfile.is_open()){
    	while (getline (myfile,word)){
    		product = 1, index = 0;
    		int size = word.size();
	    	while (index < size){
				product *= primes[word[index++] - 'a'];
			}
			if (anagram_map.find(product) == anagram_map.end()){
				anagram_map[product] = word;
			}
			else {
			anagram_map[product] = anagram_map[product] + " " + word;
		    } 
    	}
    	
    myfile.close();
    return anagram_map;
    }

    else {
	 cout << "Unable to open file";
    }
}
void printAnagrams(map<unsigned long int, string> anagram_map)
{
	ofstream myfile("sowpods_output.txt");
    	for (map<unsigned long int, string>::iterator it = anagram_map.begin(); it != anagram_map.end() ; it++){
    		if (it->second.find(" ",0) != -1){
    		myfile<<it->second<<endl;
			}
		}
}

int main(){
	
	ifstream myfile("sowpods_data.txt");
	map<unsigned long int, string> m = createAnagramMap(myfile);
	printAnagrams(m);
    getchar();
    return 0;
}
