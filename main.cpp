#include <vector>
#include <cassert>
#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
#include <cassert>
#include <random>
#include "bdc.h"

using namespace std;

int main() {
    
    vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
    vector<int> ans = biggest_divisible_conglomerate(values);
    //cout<< vec_to_string(ans)<<endl;
    vector<int> sol={56,28,14,2};
    assert(ans == sol);
    
    vector<int> values1 = {10, 5, 3, 15, 20};
    vector<int> ans1 = biggest_divisible_conglomerate(values1);
    vector<int> sol1={20,10,5};
    assert(ans1 == sol1);
    
    vector<int> values3 = {3, 3, 6, 9};
    vector<int> ans3 = biggest_divisible_conglomerate(values3);
    //cout<< vec_to_string(ans3)<<endl;
    vector<int> sol3={9,3,3};
    assert(ans3 == sol3);
    
    vector<int> values4 = {};
    vector<int> ans4 = biggest_divisible_conglomerate(values4);
    //cout<< vec_to_string(ans4)<<endl;
    vector<int> sol4={};
    assert(ans4 == sol4);
    
    vector<int> values5 = {0};
    vector<int> ans5 = biggest_divisible_conglomerate(values5);
    //cout<< vec_to_string(ans5)<<endl;
    vector<int> sol5={0};
    assert(ans5 == sol5);
    
    
    vector<int> values6 = {69};
    vector<int> ans6 = biggest_divisible_conglomerate(values6);
    //cout<< vec_to_string(ans6)<<endl;
    vector<int> sol6={69};
    assert(ans6 == sol6);
    
    vector<int> values7 = {1,INT_MAX};
    vector<int> ans7 = biggest_divisible_conglomerate(values7);
    //cout<< vec_to_string(ans7)<<endl;
    vector<int> sol7={INT_MAX,1};
    assert(ans7 == sol7);
    
    vector<int> values8 = {-7,7,-14,14};
    vector<int> ans8 = biggest_divisible_conglomerate(values8);
    vector<int> sol8={14,7,-7};
    assert(ans8 == sol8);
    
    vector<int> values9 = {7,11,17,3};
    vector<int> ans9 = biggest_divisible_conglomerate(values9);
    //cout<< vec_to_string(ans9)<<endl;
    vector<int> sol9={17};
    assert(ans9 == sol9);
    
    vector<int> values10 = {-1,0,1};
    vector<int> ans10 = biggest_divisible_conglomerate(values10);
    vector<int> sol10={1,-1};
    assert(ans10 == sol10);

    cout<<"PASSED ALL TESTS!!!!!"<<endl;
    
    vector<int> random_values;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 40000);
	while (random_values.size() < 28000) {
		random_values.push_back(dist(gen));
	}

	cout << "\nCalculating answer for input of size: " << random_values.size() << "..." << endl;
	time_t start = time(0);
	ans = biggest_divisible_conglomerate(random_values);
	time_t end = time(0);
	cout << "\x1B[32m" << "\tDone!  The answer is: " << vec_to_string(ans) << "\033[0m" << endl;
	time_t duration = end - start;
	cout << "It took " << duration << " seconds.  Wow!" << endl;\
    
    
    return 0;
}
