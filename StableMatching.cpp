/*
Bunga Azizha N - 140810180016
Kelas B
Program Stable Maching Problem
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#define N 5

using namespace std;

bool cowo(int priority[2 * N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
	{
        if (priority[w][i] == m1)
            return true;
        if (priority[w][i] == m)
            return false;
    }
}

void stableMatch(int priority[2 * N][N]){
    int pasanganWanita[N];

    bool priaJomblo[N];

    memset(pasanganWanita, -1, sizeof(pasanganWanita));
    memset(priaJomblo, false, sizeof(priaJomblo));
    
	int jmlJomblo = N;

    while (jmlJomblo > 0){
        int m;
        for (m = 0; m < N; m++)
            if (priaJomblo[m] == false)
                break;

        for (int i = 0; i < N && priaJomblo[m] == false; i++){
            int w = priority[m][i];

            if (pasanganWanita[w - N] == -1){
                pasanganWanita[w - N] = m;
                priaJomblo[m] = true;
                jmlJomblo--;
            }

            else{
                int m1 = pasanganWanita[w - N];

                if (cowo(priority, w, m, m1) == false){
                    pasanganWanita[w - N] = m;
                    priaJomblo[m] = true;
                    priaJomblo[m1] = false;
                }
            } 
        }
    }

    
    cout << "+++++++++++++++++" << endl;
    cout << "  Pria   Wanita  " << endl;
    cout << "+++++++++++++++++" << endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++){
        if (i < N){
        	//Pria
            if (pasanganWanita[i] == 0)
                man = "Victor";
            if (pasanganWanita[i] == 1)
                man = "Wyatt";
            if (pasanganWanita[i] == 2)
                man = "Xavier";
            if (pasanganWanita[i] == 3)
                man = "Yancey";
            if (pasanganWanita[i] == 4)
                man = "Zeus";
            //Wanita
            if (i == 0)
                woman = "Amy";
            if (i == 1)
                woman = "Bertha";
            if (i == 2)
                woman = "Clare";
            if (i == 3)
                woman = "Diane";
            if (i == 4)
                woman = "Erika";
        }
        cout << " " << man << "\t  " << woman << endl;
    }
    cout << "+++++++++++++++++" << endl;
}

int main(){
    int priority[2 * N][N] = {	{6, 5, 8, 9, 7},
                            	{8, 6, 5, 7, 9},
                            	{6, 9, 7, 8, 5},
                            	{5, 8, 7, 6, 9},
                            	{6, 8, 5, 9, 7},
                            	{4, 0, 1, 3, 2},
                            	{2, 1, 3, 0, 4},
                            	{1, 2, 3, 4, 0},
                            	{0, 4, 3, 2, 1},
                            	{3, 1, 4, 2, 0}};
    stableMatch(priority);

    return 0;
}
