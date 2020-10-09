#include "wordFrequency.h"
int main(int argc, char** argv) {
        wordFrequency run; 
        int bookChoice;
        cout << "1. Call of the Wild" << endl;
        cout << "2. Anne of Green Gables" << endl;
        cout << "3. Tale of Two Cities" << endl;
        cout << "Please choose a book to check the frequency of each word: ";
        cin >> bookChoice;
    switch(bookChoice)
    {
        case 1:
            run.readSample("CallWild.txt");
            run.wordAmount();
            break;
        case 2:
            run.readSample("AnneGables.txt");
            run.wordAmount();
            break;
        case 3:
            run.readSample("TaleTwoCities.txt");
            run.wordAmount();
            break;
        default:
            cout << "Not a valid input: " << endl;
            break;
            
    }
    system("pause");
    return 0;
}

