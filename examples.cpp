#include "split.hpp"
#include <iostream>

int main(){
    string str="Thanks-for-visiting-my-Blog-~!";
    split::splitC spl;
    spl = split::split(str,"-");

    for(int i=0;i<spl.size();i++){
        cout << spl[i] << " ";
        if(i!=spl.size()-1) cout << "+ ";
    }
}