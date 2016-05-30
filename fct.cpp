/*
Student Name: Halil Cetiner
Student Number: 2013400195
Project Numbner: 3
Operating System: Virtual Machine
Compile Status: Compiling
Program Status: Working
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>


using namespace std;

string colors[4] = {"red", "blue", "green", "orange"};
int N;
int** G;
int* x;
vector < pair < int,int > > val;

bool descend (pair < int,int > x, pair < int,int > y) { return (x.first>y.first); }

void graphColour(string filename){
    ofstream fout(filename);

    int i, j;
    int ctr = N;
    int colorCtr = 0;
    bool notSame = true;

    while(ctr){
        if(colorCtr > 3){
            fout << "ups" <<endl;
            return;
        }
        for(i = 0 ; i < N ; i++){
            if(x[val[i].second] == -1){
                x[val[i].second] = colorCtr;
                ctr--;
                i++;
                break;
            }
        }
        for( ; i < N ; i++){
            if(x[val[i].second] != -1)
                continue;
            notSame = true;
            for(j = 0 ; j < N ; j++){
                if(G[val[i].second][j] && x[j] == colorCtr)
                    notSame = false;
            }
            if(notSame){
                val[i].first = 0;
                x[val[i].second] = colorCtr;
                ctr--;
            }
        }
        colorCtr++;

    }

    for(i = 0; i < N; i++)
        fout << colors[x[i]] << endl;

}


int main(int argc, char* argv[]){
    ifstream fin(argv[1]);

    fin >> N;

    val.resize(N);
    x = new int[N];

    G = new int*[N];
    for(int i = 0; i < N; ++i)
        G[i] = new int[N];

    for(int i = 0 ; i < N ; i++){
        val[i].second = i;
        val[i].first = 0;
        x[i] = -1;
        for(int j = 0 ; j < N ; j++){
            fin >> G[i][j];
            if(G[i][j]){
                val[i].first++;
            }
        }
    }

    sort(val.begin(), val.end(), descend);

    graphColour(argv[2]);
    
    return 0;
}
