#include <iostream>
#include <cstdio>
using namespace std;

class weight{
    public:
        int num;
        int* left;
        int* right;
        int bal;//-1: zuo<you 0: zuo==you 1: zuo>you
        void gx();
        /*
         *  ~weight(){
         *          delete [] left;
         *                  delete [] right;
         *                      }
         *                          */
};

int B(char c){
    if(c == '=') return 0;
    if(c == '<') return -1;
    if(c == '>') return 1;
    return 0;
}


int state[1000] = {0};//零表示有可能为假币。
int Num, wnum;

void weight::gx(){
    switch(bal){
        case 0:
            for(int i = 0; i < num; i++){
                state[left[i]-1] = 1;
                state[right[i]-1] = 1;
            }
            break;
        case -1:
        case 1:
            int* temp = new int[Num];
            for(int i = 0; i < Num; i++)temp[i] = 0;
            for(int i = 0; i < num; i++){
                temp[left[i]-1] = 1;
                temp[right[i]-1] = 1;
            }
            for(int i = 0; i < Num; i++){
                if(temp[i] == 0) state[i] = 1;
            }
            delete [] temp;
    }
}

int main() {
#ifdef _POJ
    freopen("poj1029.txt", "r", stdin);
#endif
    weight ws[100];
    cin >> Num >> wnum;
    for(int i = 0; i < wnum; i++){
        cin >> ws[i].num;
        ws[i].left = new int[ws[i].num];
        ws[i].right = new int[ws[i].num];
        for(int j = 0; j < ws[i].num; j++){
            cin >> ws[i].left[j];
        }
        for(int j = 0; j < ws[i].num; j++){
            cin >> ws[i].right[j];
        }
        char c;
        cin >> c;
        ws[i].bal = B(c);
        ws[i].gx();
    }

    int jia = -1;
    bool only = true;
    for(int i = 0; i < Num; i++){
        if(state[i] != 0) continue;
        int bl = 0;
        int j;
        for(j = 0; j < wnum; j++){
            if(ws[j].bal == 0) continue;
            bool inL = false, inR = false;
            for(int k = 0; k < ws[j].num; k++){
                if(i == ws[j].left[k] - 1){
                    inL = true;
                    break;
                }
                if(i == ws[j].right[k] - 1){
                    inR = true;
                    break;
                }
            }
            int tempBl;
            if(inL) tempBl = ws[j].bal;
            if(inR) tempBl = -ws[j].bal;
            if(bl != 0 && tempBl != bl) break;
            bl = tempBl;
        }
        if(j != wnum) continue;
        int tempJia = i;
        if(jia != -1 && tempJia != jia){
            only = false;
            break;
        }
        jia = tempJia;
    }

    if(!only || jia == -1){
        cout << 0 << endl;
    }
    else{
        cout << (jia+1) << endl;
    }

    //cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    //  return 0;
    //  }
    //
}
