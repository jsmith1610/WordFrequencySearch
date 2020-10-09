/* 
 * File:   wordFrequency.cpp
 * Author: Jake Smith
 * 
 * Created on April 16, 2020, 12:23 PM
 */

#include "wordFrequency.h"

wordFrequency::wordFrequency() {
   
}

wordFrequency::wordFrequency(const wordFrequency& orig) {
}

wordFrequency::~wordFrequency() {
}

void wordFrequency::readSample(string filename){
    // Open input file
    int count = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    ifstream din;
    din.open(filename.c_str());
   if (din.fail()){
      cout << "File not found\n";
      return;
   } 
   // Read strings into word array
    string sampleWord;
   while (!din.eof()){
        din >> sampleWord;
        string updateWord = FixWord(sampleWord);
        if(updateWord.length() > 0 && updateWord[0] >= 'a' && updateWord[0] <= 'z'){
            words.push_back(updateWord);
        } 
    }
     din.close(); 
     HybridSort();
}

string wordFrequency::FixWord(string word)
//----------------------------------------------
{
    // Loop over characters to fix word
    string result = "";
    for (int i=0; i<(int)word.length(); i++)
    {
        // Save special character
        if (word[i] == '\'')
            result += word[i];
        
        // Save lower case letters
        else if ((word[i] >= 'a') && (word[i] <= 'z'))
            result += word[i];
        
        // Save upper case letters as lower case letters
        else if ((word[i] >= 'A') && (word[i] <= 'Z'))
            result += word[i] - 'A' + 'a';
    }
    return result;
}
void wordFrequency::HybridSort() //Use a hybrid sort to 
{
    // Create New Vector
    for(int i = 0; i < words.size(); i++){
        string temp = words[i];
        char first_char =temp[0];
        int position = int(first_char) - 97;
        sorted[position].push_back(temp); 
    }
    for(int i = 0; i < 26; i++){
        merge_sort(sorted[i],0,sorted[i].size()-1);
    }
    words.clear();
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < sorted[i].size(); j++){
            
            words.push_back(sorted[i][j]);
        }
    }
}
 void wordFrequency::merge_sort(vector<string> &data, int low, int high){
       //mergeSort
    int range = high - low +1;
        if (range > 1){
            // Divide the array and sort both halves
            int mid = (low + high) / 2;
            merge_sort(data,low, mid);
            merge_sort(data, mid + 1, high);
           
            // Create temporary array for merged data  
            string *copy = new string[range];
            
            // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
	 if (data[index1] < data[index2])
	    copy[index++] = data[index1++];
	 else
	    copy[index++] = data[index2++];
      }
      // Copy any remaining entries from the first half
      while (index1 <= mid)
	 copy[index++] = data[index1++];

      // Copy any remaining entries from the second half
      while (index2 <= high)
	 copy[index++] = data[index2++];

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
	 data[low + index] = copy[index];
      delete []copy;
   }
}
 
void wordFrequency::wordAmount(){
    ofstream myfile;
    myfile.open("book.count");
    string temp;
    int amount = 0;
    for(int i = 0; i < words.size()-1; i++){
        temp = words[i];
        if(temp == words[i+1]){
            amount++;
        }
        else{
             myfile << amount << " " << temp << endl;
            amount = 1;
        }
    }
    myfile.close();
} 

            
            
            
            