#include <iostream>
#include <string>
#include <fstream>
#include <locale>
using namespace std;
#include "node.h"
#include"hashtable1.h"
#include "hashtable2.h"

string toLowerCase(string);

int main(int argc, char *argv[]) 
{
  clock_t timeBeginSpellCheck1, timeEndSpellCheck1; 
  clock_t timeBeginHash1, timeEndHash1;
  clock_t timeBeginSpellCheck2, timeEndSpellCheck2; 
  clock_t timeBeginHash2,timeEndHash2;
  double totalTimeSpellCheck1 = 0.0; 
  double totalTimeHash1 = 0.0;
  double totalTimeSpellCheck2 = 0.0;
  double totalTimeHash2 = 0.0;

// FOR HASHTABLE1- chaining method
  ifstream in(argv[1]);//open dictionaryFile
  if(!in)
  {
    cout << argv[1] << " File error. Didn't open"  << endl  ;
    return 0;
  }
  
  timeBeginHash1 = clock();
  Hash dictionary;
  string chain; 
  while(in)
  {
    in >> chain;
    dictionary.insert(chain);
  }
  //stop the clock
  timeEndHash1 = clock();
  totalTimeHash1 = (double)(timeEndHash1 - timeBeginHash1) / CLOCKS_PER_SEC;
  in.close();

  // open input file 
  in.open(argv[2]); 
  if(!in)
  {
    cout << argv[2] << "File error. Didn't open"  << endl  ;
    return 0;
  }
  string wordCheck; 
  int misspelled = 0; 
  timeBeginSpellCheck1 = clock(); 
  while(in)
  {
    in >> wordCheck; 
    toLowerCase(wordCheck); 
    if(dictionary.spellCheck(wordCheck) == false)
    {
      misspelled++; 
    }
  }
  timeEndSpellCheck1 = clock(); 
  totalTimeSpellCheck1 = (double)(timeEndSpellCheck1 - timeBeginSpellCheck1) / CLOCKS_PER_SEC;
  cout<<endl;
  cout << "Total misspelled words from chaining: " << misspelled << endl;
  cout << "total time for spell check with chaining:  " << totalTimeSpellCheck1<< endl;
  cout<<endl;

  in.close(); 
  
  //FOR HASHTABLE2- quadratic probing method
  
  in.open(argv[1]);//open dictionaryFile
  if(!in)
  {
    cout << argv[1] << "File error. Didn't open"  << endl  ;
    return 0;
  }

  //start the clock for quadratic probing hash 
  timeBeginHash2 = clock();
  Hash2 lexicon;
  string quad; 
  while(in)
  {
    in >> quad;
    lexicon.insert(quad);
  }
  //
  //stop the clock
  timeEndHash2 = clock();
  totalTimeHash2 = (double)(timeEndHash2 - timeBeginHash2) / CLOCKS_PER_SEC;
  in.close();

  // open input file 
  in.open(argv[2]); 
  if(!in)
  {
    cout << argv[2] << "File error. Didn't open"  << endl  ;
    return 0;
  }
  string checkInput; 
  int misSpelled = 0; 
  timeBeginSpellCheck2 = clock(); 
  while(in)
  {
    in >> checkInput; 
    toLowerCase(checkInput);
    if((lexicon.spellCheck(checkInput)) != true)
    {
      misSpelled++; 
    }
  }
  timeEndSpellCheck2 = clock(); 
  totalTimeSpellCheck2 = (double)(timeEndSpellCheck2 - timeBeginSpellCheck2) / CLOCKS_PER_SEC;
  cout<<endl;
  cout << "Total misspelled words with Quadratic Probing: " << misSpelled << endl;
  cout << "Total time for spell check with Quadratic Probing: " << totalTimeSpellCheck2<< endl;
  cout<<endl;
  in.close(); 


  cout<<"Final Analysis"<<endl;
  cout<<"Chaining Method: "<< totalTimeHash1<<endl;
  cout<<"Quadratic Probing Method: "<< totalTimeHash2 <<endl;
  return 0; 
}

string toLowerCase(string entry){
  char letter; 
  int length = entry.length();
  for (int i=0; i<length; i++){
    letter = entry[i];
    letter = tolower(letter);
    entry[i] = letter;
  }
  if(entry[length-1] == ',' || entry[length-1] == '.' || entry[length-1] == ':'){
    entry = entry.substr(0, length-1);
  }
  return entry;
}