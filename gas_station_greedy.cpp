#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) 
{
    int total_gas=0;  
    int total_cost=0;
    for(int i = 0;i<gas.size();i++) 
    { 
        total_gas+=gas[i];
        total_cost+=cost[i];
    }
    if(total_gas<total_cost) { return -1; }
    
    int current_gas = 0;
    int start_station = 0;
    for(int i = 0;i<gas.size();i++) 
    {
        current_gas += gas[i] - cost[i];
        if(current_gas < 0) 
        {
            current_gas= 0;
            start_station = i + 1;
        }
    }
    return start_station;
}

int main()
{

}