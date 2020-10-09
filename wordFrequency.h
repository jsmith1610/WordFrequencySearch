/* 
 * File:   wordFrequency.h
 * Author: Jake Smith
 *
 * Created on April 16, 2020, 12:23 PM
 */

#ifndef WORDFREQUENCY_H
#define WORDFREQUENCY_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class wordFrequency {
public:
    wordFrequency();
    wordFrequency(const wordFrequency& orig);
    void readSample(string filename);
    string FixWord(string word);
    void HybridSort();
    void merge_sort(vector<string> &data, int low, int high);
    void wordAmount();
    virtual ~wordFrequency();
private:
    vector<string> words;
    vector<string> sorted[26];

};

#endif /* WORDFREQUENCY_H */

