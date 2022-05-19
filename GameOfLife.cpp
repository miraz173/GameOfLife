#include <iostream>
using namespace std;

void inputPrint(const bool pos[20][20]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (pos[i][j]){
                cout<< " |  O  ";
            }
            else
                if (i<10)
                {
                    if(j<10){
                        cout<<" | "<<i<<','<<j<<" ";
                    }
                    else
                        cout<<" | "<<i<<','<<j;
                }
                else
                {
                    if(j<10){
                        cout<<" |"<<i<<','<<j<<" ";
                    }
                    else
                        cout<<" |"<<i<<','<<j;
                }
        }
        cout<<"\n\n";
    }
    cout<<"\n\n";
}

void takeInput(bool pos[20][20]){
    int x, y;
    while (true){
        system("cls");
        inputPrint(pos);
        cout<<"Enter x, y coordinate of living cell(negative number to terminate taking input): "; 
        cin>> x >> y;
        if (x<0 || y<0){
            break;
        }
        pos[x][y]= true;
    }
} //takes position of cells that are alive. continues taking input until the input is smaller than 0.

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
} //prints alive cells as zero. Dead ones are represented as ' '(space)

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
} //calculates the number of alive neighbours of cell(pos[i][j]) and stores them in neighbour[i][j].

void createCell(bool pos[20][20], int neighbour[20][20]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (neighbour[i][j]==3){
                pos[i][j] = true;
            }
        }
    }
} //a dead cell comes to life if it has exactly 3 alive neighbour. Otherwise, the dead remains dead.

void destroyCell(bool pos[20][20], int neighbour[20][20]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (neighbour[i][j]>3 || neighbour[i][j]<2){
                pos[i][j] = false;
            }
        }
    }
} //a living cell with less than 2 or more than 3 living neighbour is doomed to die.

int main()
{
    bool pos[20][20]={false}; //a living cell(pos[i][j]) has 'true' as value in its coordinate position.
    int iCount=0;            //number of iteration in while loop.

    takeInput(pos);
    while(iCount<=20){   //program ends in 20th iteration
        int neighbour[20][20]={0};//neighbour[i][j] stores the number of alive neighbours of the cell(pos[i][j]). 
        //previously calculated neighbour[][] becomes obsolete as many creation and destruction of living cell has happened.

        print(pos);
        calculateNeighbour(pos, neighbour);
        createCell(pos, neighbour);
        destroyCell(pos, neighbour);
        system("pause"); //pauses the program before before jumping to next iteration, giving time to check the output.
        system("cls");  //clears console screen before next output.
        
        iCount++;
    }
}