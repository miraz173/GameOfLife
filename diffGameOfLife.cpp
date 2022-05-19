//
// Created by HP on 12-Apr-22.
//

#include<iostream>
using namespace std;

/*class Cell{
public:
    int x;
    int y;
    bool life;
    Cell(int x, int y, bool life){
        this->x=x;
        this->y=y;
        this->life=life;
    }
    Cell(int x, int y){
        this->x=x;
        this->y=y;
        this->life= true;
    }
};*/
void takeInput(bool pos[20][20]){
    int x, y;
    while (true){
        cin>>x >> y;
        if (x<0 || y<0){
            break;
        }
        pos[x][y]= true;
    }
} //takes position of cells that are alive. continues taking input until any input is smaller than 0.
void print(const bool pos[20][20]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (pos[i][j]){
                cout<< "| O ";
            }
            else
                cout<<"|   ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}
void calculateNeighbour(const bool pos[20][20], int neighbour[20][20]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (pos[i][j]){
                if (i>0){
                    neighbour[i-1][j]++;
                    if (j>0){
                        neighbour[i-1][j-1]++;
                    }
                    if (j<19){
                        neighbour[i-1][j+1]++;
                    }
                }
                if (i<19){
                    neighbour[i+1][j]++;
                    if (j>0){
                        neighbour[i+1][j-1]++;
                    }
                    if (j<19){
                        neighbour[i+1][j+1]++;
                    }
                }
                if (j<19){
                    neighbour[i][j+1]++;
                }
                if (j>0){
                    neighbour[i][j-1]++;
                }
            }
        }
    }
}
void createCell(bool pos[20][20], int neighbour[20][20]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (neighbour[i][j]==3){
                pos[i][j] = true;
            }
        }
    }
}
void destroyCell(bool pos[20][20], int neighbour[20][20]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (neighbour[i][j]>3 || neighbour[i][j]<2){
                pos[i][j] = false;
            }
        }
    }
}
void create(bool pos[20][20]){
    int neighbour[20][20]={0};
    calculateNeighbour(pos, neighbour);
    createCell(pos, neighbour);
}
void destroy(bool pos[20][20]){
    int neighbour[20][20]={0};
    calculateNeighbour(pos, neighbour);
    destroyCell(pos, neighbour);
}
int main()
{
    bool pos[20][20]={false};
    int m=0;
    takeInput(pos);
    while(true){
        print(pos);
        create(pos);
        destroy(pos);
        system("pause");
        system("cls");
        if(m==20){
            break;
        } m++;
    }
}