#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int num;
    int x = 0;
    int iter;
    int score[50];
    for (int i = 0; i < 50; i++) { score[i] = 0; }
    
    cout << "How many iterations would you like to run?" << endl;
    cin >> iter;
    srand(time(NULL));


    while (x < iter)
    {
        num = (rand() % 50);
        score[num]++;
        x++;
    }
    cout << "Results:\n";
    int lvl;
    for (int i = 0; i < 50; i++)
    {
        lvl = score[i];
        cout << i << "\t";
        while (lvl > 0)
        {
            cout << "#";
            lvl--;
        }
        cout << endl;
    }
    return 0;
}
