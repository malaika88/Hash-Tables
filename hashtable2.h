#ifndef HASHTABLE2_H
#define HASHTABLE2_H
#include <string>
using namespace std; 

//quadratic probing
class Hash2
{
  public: 
    Hash2(); 
    ~Hash2(); 
    void insert(string); 
    bool spellCheck(string); 
    void print(); 

  private: 
    void resize(); 
    unsigned search(string);
    int stringToInt(string);
    bool isPrime (unsigned); 
    unsigned getNextPrime(unsigned);
    unsigned collisions; 
    
    string * data; // pointer to array of data
    string vacant;
    unsigned size; 
    unsigned capacity; 

};
Hash2 :: Hash2()
{
  size = 0;
  capacity = 53;
  data = new string[capacity];
  vacant = data[0];
  
}

Hash2:: ~Hash2()
{
  delete [] data; 
}

int Hash2::stringToInt(string word)
{
  // for every character in the string we add up the ascii value to make it an int then add 88 to increase chances it will be prime 
  unsigned ascii = 0;
  for (unsigned i = 0; i < word.length(); i++)
  {
    ascii += word[i];
  } 
  ascii += 88;
  return ascii;
}

bool Hash2::isPrime(unsigned num)
{
  if (num == 2 || num == 3)
    return true;
  if (num == 1 || num % 2 == 0)
    return false;
  for (unsigned i = 3; i * i <= num; i += 2)
  {
    if (num % i == 0)
    {
        return false;
    }
  }
  return true;
}

unsigned Hash2::getNextPrime(unsigned num)
{
  if (num == 0)
  {
    num = 3;
  }
  else if (num % 2 == 0)
  {
    num++;
  }
  while (!isPrime(num))
  {
    num = num + 2;
  }
  return num;
}

void Hash2:: resize()
{
  unsigned newCap; 
  newCap = getNextPrime(capacity*2); 
  string *newData  = new string[newCap]; 

  for (unsigned long i = 0; i < size ; i++)
  {
    newData[i]= data[i]; 
  }
  delete [] data;
  data = newData; 
  return;  
}

unsigned Hash2:: search(string value)
{
  unsigned index;
  unsigned collisions = 0;
  index = stringToInt(value)%capacity;
  while (data[index] != vacant && data[index] != value)
  {
    index = index + 2* collisions++ -1;
    if(index >= capacity)
    {
      index = index - capacity;
    }
  }
  //cout<< collisions<< "number of comparisions made quadratic probing"<<endl;
  return index;
} 

void Hash2::insert(string entry)
{
  unsigned index;
  size += 1;
  // if hashed index is outside of the range of the hash table resize the table 
  if( size > capacity)
  {
    resize(); 
    index = search(entry);
    data[index] = entry; 
  }
  // if everything is good just add the hashed data to the table  
  else
  {
    index = search(entry);
    data[index] = entry;
  }
}

bool Hash2:: spellCheck(string check)
{
  /* 2 options:
  1) search function returns vacant index --> word not found 
  2) search function returns index of the check string --> word found 
  */
  bool alright = false;  
  if(data[search(check)] == check)
  {
    alright = true; 
  }
  return alright;
}

void Hash2::print()
{
  cout<<"[";
  for(unsigned i = 0; i < capacity ;i++)
  {
    if( data[i] != vacant)
    {
      cout<<data[i] << ","; 
    }
    
  }
  cout<< "]";
}
#endif