//
//  main.cpp
//  Lab 05
//
//  Created by Mitchell Burr on 10/16/18.
//  Copyright © 2018 Mitchell Burr. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int TimeToMinutes(int h, int m){
    int TotalMinutes = (h*60)+m;
    return TotalMinutes;
}

void MinutesToTime (int minutes, int& h, int& m){
    h = minutes/60;
    m = minutes%60;
}

bool negcheck(double n){
    if (n < 0){
        cout << "please input a positive number" << endl;
        return 1;
    }
    return 0;
}

void elapsedTime(int h1, int m1, int h2, int m2, int& h, int& m){
    int TotalMinutes1 = TimeToMinutes(h1, m1);
    int TotalMinutes2 = TimeToMinutes(h2, m2);
    int ElapsedMinutes = abs((TotalMinutes1-TotalMinutes2));
    MinutesToTime(ElapsedMinutes, h, m);
}

int main() {
    char run = 'y';
    while (run == 'y'){
        char function;
        char colon = ':';
        cout << "which function would you like to use? 't' for Time to Minutes, 'm' for minutes to time, 'e' for elapsed time, 'f' for input flight data to a file, " << endl;
        cin >> function;
        
        if (function == 't'){
            int h;
            int m;
            char colon;
            cout << "what time would you like to convert to minutes? hh:mm" << endl;
            cin >> h >> colon >> m;
            cout << TimeToMinutes(h, m) << " minutes" << endl;
        }
        
        if (function == 'm')
        {
            int h;
            int m;
            int minutes;
            cout << "how many minutes would you like to convert to an hh:mm time?" << endl;
            cin >> minutes;
            
            if (negcheck(minutes))break;
            
            MinutesToTime(minutes, h, m);
            if ( m < 10 ){
                cout << "Hours: Minutes is" << h << colon << "0" << m << endl;
       
            }
            else {
                cout << " Hours: Minutes is " << h << colon << m << endl;
            }
        
        }
        
        if (function == 'e'){
            int h;
            int m;
            int h1;
            int h2;
            int m1;
            int m2;
            cout << "Enter first time: (hh:mm)" << endl;
            cin >> h1 >> colon >> m1;
            cout << " Enter second time: (hh:mm) " << endl;
            cin >> h2 >> colon >> m2;
            negcheck(h1);
            negcheck(h2);
            negcheck(m1);
            negcheck(m2);
            elapsedTime(h1, m1, h2, m2, h, m);
            if ( m < 10 ){
                cout << "elapsed time is: " << h << colon << "0" << m << endl;
                
            }
            else {
                cout << "elapsed time is: " << h << colon << m << endl;
            }
        }
        
        if (function == 'f'){
            ofstream FlightData;
            string FlightNumber;
            char space = ' ';
            FlightData.open("FlightData.dat");
            if (FlightData.fail()) {
                cout << "file failed to open" << endl;
                exit(1);
            }
            cout << "please enter the flight number" << endl;
            cin >> FlightNumber;
            if (FlightNumber == "end") break;
            FlightData << FlightNumber << space;
            
            FlightData.close();
        }
        cout << "would you like to utilize another function?" << endl;
        cin >> run;
    }
    
    return 0;
}
