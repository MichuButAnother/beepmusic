/*
MIT License

Copyright (c) 2020 Piter

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/kd.h>
#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "config.h"

using namespace std;

void beep(int freq,int dur=500,bool wait=false) {
if(freq==0) {ioctl(STDOUT_FILENO, KIOCSOUND, 0); return;}
ioctl(STDOUT_FILENO, KIOCSOUND, 1193180/freq);
if(wait) {
usleep(1000*dur);
if(freq==0) ioctl(STDOUT_FILENO, KIOCSOUND, 0);
}
}

int NOTEFREQ[]= // FREQ OF NOTES
{16,17,18,19,20,21,23,24,25,27,29,30, //0
32,34,36,38,41,43,46,49,51,55,58,61,  // 1
65,69,73,77,82,87,92,98,103,110,116,123,//2
130,138,146,155,164,174,185,196,207,220,233,246,//3
261,277,293,311,329,349,369,392,415,440,466,493, //4
523,554,587,622,659,698,739,783,830,880,932,987, //5
1046,1108,1174,1244,1318,1396,1479,1567,1661,1760,1864,1975,//6
2093,2217,2349,2489,2637,2793,2959,3135,3322,3520,3729,3951, //7
4186,4434,4698,4678,5274,5587,5919,6271,6644,7040,7458,7902}; //8

void exit_handle(int sig) {
beep(0);
cout<<"\033[0m";
cout<<endl<<endl;
cout.flush();
exit(0);
}

int main(int argc, char *argv[])
{
    bool nographics=beepmusic_nographics;
    if(argc<3) {cout<<"beepmusic By maniek207 v"<<beepmusic_VERSION_MAJOR<<"."<<beepmusic_VERSION_MINOR<<"\n\nUsage: beepmusic [file] [tempo]"<<endl; exit(0);}
    if(argc>3) {cout<<"To many arguments!"<<endl; exit(0);}

    signal(SIGINT,exit_handle);
     int tempo=atoi(argv[2]);
    ifstream input(argv[1],ios::binary);
    if(!input.good()) {
    cout<<"Failed to open file input.txt!"<<endl;
    return 0;
    }

    string line;
    getline(input,line);
    if(line=="ModPlug Tracker  IT" || line=="ModPlug Tracker MPT") {} else {cout<<"Invalid format"<<endl; exit(0);}

    int cnt=-1;
    bool innote=false;

    while(1) {
    if(!getline(input,line)) break;
    string t="p";
    string p="o";
    try {t=line.substr(1,2);} catch(std::out_of_range & e) {}
    try {p=line.substr(3,1);} catch(std::out_of_range & e) {}
    if(t=="p") break;

    int g=0;
    if(t=="C-") g=1;
    if(t=="C#") g=2;
    if(t=="D-") g=3;
    if(t=="D#") g=4;
    if(t=="E-") g=5;
    if(t=="F-") g=6;
    if(t=="F#") g=7;
    if(t=="G-") g=8;
    if(t=="G#") g=9;
    if(t=="A-") g=10;
    if(t=="A#") g=11;
    if(t=="B-") g=12;

    int a=1;
    if(p=="1") a=2;
    if(p=="2") a=3;
    if(p=="3") a=4;
    if(p=="4") a=5;
    if(p=="5") a=6;
    if(p=="6") a=7;
    if(p=="7") a=8;
    if(p=="8") a=9;
    if(p=="=") a=0;
    if(line=="ModPlug Tracker  IT" || line=="ModPlug Tracker MPT") {
    } else {

    if(!(p==".")) {
    int freq_index=(a*12)+g;
    innote=true;
    if(a==0) innote=false;
    if(g==0) {beep(0);} else {
    beep(NOTEFREQ[freq_index-1],tempo,false);
    }
    usleep(tempo*1000);
    }
    if(p==".") {
    usleep(tempo*1000);
    }}
    if(!nographics) {
    if(a!=0) cout<<"\033[0;32m";
    if(p==".") cout<<"\033[0;34m";
    if(p=="=") cout<<"\033[0;33m";
    cnt=cnt+1;
    if(cnt>17) {
    cout<<endl;
    cnt=0;
    }
    cout<<"\u2588";
    cout.flush();
    }}
    beep(0);
    cout<<"\033[0m"<<endl<<endl;
    cout.flush();
    return 0;
}


