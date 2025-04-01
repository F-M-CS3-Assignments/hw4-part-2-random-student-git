#include <vector>
#include <cassert>
#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
#include <cassert>
#include <random>

using namespace std;

// The time complexity for this code is O(n^3) while the time complexity of my previous approach was O(2^n)

string vec_to_string(const vector<int>& vec){
    string s="{";
    for (int i=0;i<vec.size();i++){
        s+=to_string(vec[i]); //concatenate the next element as string
        if (i!=vec.size()-1){ //as long as we aren't on the last element, keep using commas
            s+=",";
        }
    }
    s+="}";
    return s;
}

vector<int> biggest_divisible_conglomerate(vector<int> inputVector){
    if (inputVector.size()==0 || inputVector.size()==1){  // can't do anything with a vector with zero elements
        return inputVector;   // and a vector with one element's biggest conglomerate is always itself
    }
    sort(inputVector.begin(),inputVector.end());  //sort vector before starting
    vector<vector<int>> answers(inputVector.size());  // initialize dynamic programming table 
    for (int i=0;i<answers.size();i++){
        answers.at(i) = {inputVector.at(i)};  // each row is an element of inputVector, but as a vector
    }
    // for each i, check if subset can be appended to for any j greater than i
    for (int i = 0; i < inputVector.size();i++){
        int cur_element = inputVector[i];
        for (int j = i+1; j < inputVector.size();j++){
            if (cur_element!=0){  //  prevent dividing by 0
                if (inputVector.at(j)%cur_element==0 && answers.at(i).size()>=answers.at(j).size()){  // check if divisble and if appending yields a larger subset
                    answers.at(j) = {inputVector.at(j)};  // update answers.at(j), starting with {inputVector.at(j)}
                    for (int k = 0;k<answers.at(i).size();k++){
                        answers.at(j).push_back(answers.at(i).at(k));  //  append each element from answers at row i to answers.at(j), creating a new conglomerate
                    }
                }
            }
        }
    }
    int max_idx=0;  // index for storing maximum (default is 0)
    int size=answers[0].size();  // size of maximum (default is length of answers[0])
    for (int i=1;i<answers.size();i++){
        if (answers[i].size()>=size){  // if there's a number that bigger than size, update max_idx and size to store the new max's location & magnitude
            max_idx=i;
            size=answers[i].size();
        }
    }
    return answers.at(max_idx);  // return maximum
}