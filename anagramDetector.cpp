#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <fstream>

using namespace std;

map< char, int > charWeightages;
void assignCharWeightages() {
	charWeightages['a'] = 3;
	charWeightages['b'] = 5;
	charWeightages['c'] = 7;
	charWeightages['d'] = 11;
	charWeightages['e'] = 13;
	charWeightages['f'] = 17;
	charWeightages['g'] = 19;
	charWeightages['h'] = 23;
	charWeightages['i'] = 29;
	charWeightages['j'] = 31;
	charWeightages['k'] = 37;
	charWeightages['l'] = 41;
	charWeightages['m'] = 43;
	charWeightages['n'] = 53;
	charWeightages['o'] = 59;
	charWeightages['p'] = 61;
	charWeightages['q'] = 67;
	charWeightages['r'] = 71;
	charWeightages['s'] = 73;
	charWeightages['t'] = 79;
	charWeightages['u'] = 83;
	charWeightages['v'] = 89;
	charWeightages['w'] = 97;
	charWeightages['x'] = 101;
	charWeightages['y'] = 103;
	charWeightages['z'] = 107;
}

/* Each character in the alphabet has been assigned a
 * weightage in the map charWeightages. This function simply
 * multiplies the weightage of each character in a string and returns
 * it.
 */
long long getStringWeightage( string a ) {
	long long total = 1;

	for ( int i = 0; i < a.length(); ++i )
		total *= charWeightages[ a[i] ];

	return total;
}

/* If the length of 2 strings is different, they cannot be
 * anagrams. Otherwise, the total weightage of both strings
 * is calculated and compared and if both weightages are
 * equal, the strings are anagrams.
 */
bool isAnagram( const string& a, const string& b ) {
	if ( a.length() != b.length() or a == b )
		return false;

	if ( getStringWeightage(a) == getStringWeightage(b)) {
		cout << a << " is an anagram of " << b << endl;
		return true;
	}
	else
		return false;
}

int main() {

	int noOfWords;
	cin >> noOfWords;

	pair<string, int>* words = new pair<string, int> [noOfWords];

	for( int i = 0; i < noOfWords; ++i ) {
		cin >> words[i].first;
		words[i].second = 0;
	}

	assignCharWeightages();

	string word;
	ifstream wordFile( "words.txt" );
	if ( !wordFile ) {
		cout << "File could not be opened!";
		exit(1);
	}

	while ( getline( wordFile, word )) {
		for( int i = 0; i < noOfWords; ++i ) {
			if ( isAnagram( word, words[i].first ))
				++words[i].second;
		}
	}
	for( int i = 0; i < noOfWords; ++i ) {
		cout << words[i].second << " ";
	}
}
