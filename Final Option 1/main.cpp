/* 
 * File:   main.cpp
 * Author: Michael Donnelly
 * CS-130
 * Professor Samuel Addington 
 * Created on June 12, 2025, 6:15 PM
 * 90 lines of code
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    /* I am representing this graph as 2 parallel arrays. This works because 
     * there are 7 vertices and 6 edges which is equivalent to a Binary Tree. 
     * The Binary Tree only has one child node per parent node so it is linear
     * and thus can be represented with 2 parallel arrays.
     */     
    //7 vertices
    string Planet[7] = {"Taris","Dantooine","Tatooine","Kashyyyk","Mannan","Korriban","Rakata Prime"};
    //6 edges
    float Distance[6] = {1,7,4,0.5,3,6};
    
    //Display graph structure to user
    for (int i = 0; i<=5; i++){
        cout << Planet[i] << " -- " << Distance[i] << " -- " << Planet[i+1] << endl;
    }
    
    //Part ONE
    cout << endl << "#1 Calculate the Total Path:" << endl;
    cout << Planet[0] << " <--> " << Planet[6] << " = ";
    float Total_Path = 0;
    for (int i = 0; i<=5; i++){
        if (i==5){
            cout << Distance[i];
        } else {
            cout << Distance[i] << " + ";
        }
        Total_Path += Distance[i];
    }
    cout << " = " << Total_Path << endl << endl;
    
    //Part TWO
    cout << "#2 Calculate the shortest path from Rakata Prime to Dantooine" << endl;
    float Shortest_Path = 0;
    for (int i = 6; i>=2; i--){
        cout <<  Planet[i] <<  " --> " << Planet[i-1] << " = " << Shortest_Path;
        cout << " + " << Distance[i-1] << " = ";
        Shortest_Path += Distance[i-1];
        cout << Shortest_Path << endl;
    }
    cout << "Shortest path from Rakata Prime to Dantooine = ";
    cout << Shortest_Path << endl << endl;
    
    //Part THREE
    cout << "#3 What is the best planet for a base?" << endl;
    
    int Best_Planet = 0; //array index value of best planet
    int Worst_Planet = 0; //array index value of worst planet
    float MST[7]; // store total distances here for each planet
    for (int i = 0; i<=6; i++){
        /* Splitting this into 2 additional for loops
         * "down loop" that calculates distances to planets below i
         * "up loop" that calculates distances to planets above i
         * Example: i=3, "down" calculates distances to planets 0, 1, and 2
         *      and "up" calculates distances to planets 4,5, and 6 */
        float Planet_Down_Sum=0;
        float Total_Down_Sum=0; //distance sum for "down loop"
        for (int j = i; j>0; j--){
            Planet_Down_Sum += Distance[j-1];
            Total_Down_Sum += Planet_Down_Sum;
            cout <<  Planet[i] <<  " --> " << Planet[j-1] << " = " << Planet_Down_Sum << endl;
        }
        
        float Planet_Up_Sum = 0;
        float Total_Up_Sum = 0; //distance sum for "up loop"
        for (int j = i; j<6; j++){
            Planet_Up_Sum += Distance[j];
            Total_Up_Sum += Planet_Up_Sum;
            cout <<  Planet[i] <<  " --> " << Planet[j+1] << " = " << Planet_Up_Sum << endl;
        }
        MST[i]= Total_Down_Sum+Total_Up_Sum;
        cout << "Total distance = " << MST[i] << endl;
        cout << endl;
        
        //Saves index of the planet with lowest Minimum Spanning Tree
        if (MST[Best_Planet] > MST[i]) {
            Best_Planet = i;
        }         
        //Saves index of the planet with highest Minimum Spanning Tree
        if (MST[Worst_Planet] < MST[i]) {
            Worst_Planet = i;
        }         
    }

    cout << "Best planet = " << Planet[Best_Planet] << endl;
    cout << "Total distance = " << MST[Best_Planet] << endl;
    //Average distance divides the MST of the planet by the number of planets
    cout << "Average distance = " << MST[Best_Planet]/7 << endl << endl;
    
    cout << "Worst planet = " << Planet[Worst_Planet] << endl;
    cout << "Total distance = " << MST[Worst_Planet] << endl;
    cout << "Average distance = " << MST[Worst_Planet]/7 << endl;
    
    
    return 0;
}