#ifndef __splitC__
#define __splitC__

#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

namespace split{

class splitC{
private:
int _size,maxsize;
string *data=NULL;
public:
    splitC() : _size(0), maxsize(1) { }
    void add(string arr){
        if(_size+1>=maxsize){
            maxsize*=2;
            string *temp = new string[maxsize];
            for(int i=0;i<_size;i++) temp[i]=data[i];
            temp[_size++]=arr;
            delete[] data;
            data=temp;
        }
        else data[_size++]=arr;
    }
    int size(){ return _size; }
    int capacity(){ return maxsize; }
    string& operator[](int i){ return data[i]; }
};

void stoc(string str,char *chr){
    int cnt=0;
    while(chr[cnt]!='\0') cnt++;
    for(int i=0;i<cnt;i++) chr[i]='\0';
    for(int i=0;i<str.size();i++) chr[i]=str[i];
}

splitC split(string str,const char* tok){
    splitC vec;
    char chr[str.size()];
    stoc(str,chr);
    char *token = strtok(chr,tok);

    while(token!=NULL){
        vec.add(token);
        token = strtok(NULL,tok);
    }
    return vec;
}

int SplitToInt(string str){
    int i = atoi(str.c_str());
    return i;
}

int SplitToInt(splitC spl){
    int cnt=0;
    for(int i=0;i<spl.size();i++) cnt+=atoi(spl[i].c_str());
    return cnt;
}

}

#endif