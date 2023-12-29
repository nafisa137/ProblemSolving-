//file name : A3_SheetPb1_20220334
//purpose : solving problem 1
//author : mariam matarawy ahmed ali
//ID : 20220334
//section : s1
//date : 6/12/2023

#include "bits/stdc++.h"
using namespace std;


class LabelGenerator{//generator fo figures
protected:
    string shape;
    int num;
public:
    LabelGenerator(string shape1 , int num1) ;
    virtual void nextlabel();
};
LabelGenerator::LabelGenerator(string shape , int num):shape(shape),num(num){}
void LabelGenerator::nextlabel(){
    if (shape == "figure"){
        cout<<"Figure"<<" ";
        cout<< num++;
    }
    else if (shape == "p"){
        cout<<"p";
        cout<<num++;
    }
}


class FileLableGenerator : public LabelGenerator{
    string filename;
public:
    FileLableGenerator(string shape , int num , string filename): LabelGenerator(shape,num) , filename(filename){}
    void nextlable();
};
void FileLableGenerator ::nextlable() {
    ifstream f_read(filename);
    string line;
    if (f_read.is_open()) {
        while(getline(f_read,line)){
            if (shape == "figure") {
                cout << "Figure" << " ";
                string result = to_string(num++) + line;

                cout<< result;
            }
            else if (shape == "p") {
                cout << "p";
                string result = to_string(num++) + line;

                cout<< result;


            }

        }cout<<endl;
    }
    f_read.close();
}
