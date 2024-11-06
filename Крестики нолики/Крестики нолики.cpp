#include <iostream>
#include <ctime>

using namespace std;
// прототипирование программы где пользоваетль играет с другом
void writeMassiveFriend(char** field);
int checkWinnerFriend(char** field, char symbol, int count);
int checkDrawFriend(char** field, int amountOfFreePlaces);
char** rewriteMassiveFriend(char** field, char symbol);
void playWithFriend(char** field);

//Функция которая выводит массив после хода
void writeMassiveFriend(char** field) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

//Функция которая проверяет выграл один или другой игрок
int checkWinnerFriend(char** field, char symbol, int count) {
    if (field[0][0] == field[0][1] && field[0][0] == field[0][2] && field[0][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[1][0] == field[1][1] && field[1][0] == field[1][2] && field[1][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[2][0] == field[2][1] && field[2][0] == field[2][2] && field[2][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][0] == field[1][0] && field[0][0] == field[2][0] && field[0][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][1] == field[1][1] && field[0][1] == field[2][1] && field[0][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][2] == field[1][2] && field[0][2] == field[2][2] && field[0][2] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][0] == field[1][1] && field[0][0] == field[2][2] && field[1][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][2] == field[1][1] && field[0][2] == field[2][0] && field[1][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
}

//Функция которая высчитывает ничью 
int checkDrawFriend(char** field, int amountOfFreePlaces) {
    int count = 0;
    if (amountOfFreePlaces > 0) {
        return count;
    }
    else {
        cout << "Draw" << endl;
        return ++count;
    }
}

//Переписывания игрового поля с каждм ходом игрока
char** rewriteMassiveFriend(char** field, char symbol) {
    int x, y;
    cout << "Enter a row of place: ";
    cin >> x;
    cout << endl << "Enter a column of place: ";
    cin >> y;

    while ((x < 0 || x > 2) || (y < 0 || y > 2)) {
        cout << "Enter a row of place: ";
        cin >> x;
        cout << endl << "Enter a column of place: ";
        cin >> y;
    }

    while (field[x][y] != '+') {
        cout << "Enter a row of place: ";
        cin >> x;
        cout << endl << "Enter a column of place: ";
        cin >> y;
    }

    field[x][y] = symbol;

    return field;
}

//Оснновная функция которая имеет все нужные переменные и завержает программу
void playWithFriend(char** field) {

    bool isGameOver = false;
    char symbol = 'X';
    int countOfSteps = 1;
    int amountOfFreePlaces = 9;

    while (!isGameOver) {
        if (countOfSteps % 2 == 0) {
            symbol = '0';
        }
        else {
            symbol = 'X';
        }
        countOfSteps++;

        writeMassiveFriend(field);

        rewriteMassiveFriend(field, symbol);

        amountOfFreePlaces--;

        int count = 0;


        if (checkWinnerFriend(field, symbol, count) == 1) {
            break;
        }

        if (checkDrawFriend(field, amountOfFreePlaces) == 0) {
            continue;
        }
        else {
            break;
        }

    }
}

//Прототипирование для игры с ботом
void writeMassiveBot(char** field);
int checkWinnerBot(char** field, char symbol, int count);
int checkDrawBot(char** field, int amountOfFreePlaces);
char** rewriteMassiveBotuserStep(char** field, char symbol);
char** rewriteMassiveBotStep(char** field);
int playWithBot(char** field);

//Вывод массива
void writeMassiveBot(char** field) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

//Проверка на победу
int checkWinnerBot(char** field, char symbol, int count) {
    if (field[0][0] == field[0][1] && field[0][0] == field[0][2] && field[0][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[1][0] == field[1][1] && field[1][0] == field[1][2] && field[1][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[2][0] == field[2][1] && field[2][0] == field[2][2] && field[2][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][0] == field[1][0] && field[0][0] == field[2][0] && field[0][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][1] == field[1][1] && field[0][1] == field[2][1] && field[0][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][2] == field[1][2] && field[0][2] == field[2][2] && field[0][2] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][0] == field[1][1] && field[0][0] == field[2][2] && field[1][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
    else if (field[0][2] == field[1][1] && field[0][2] == field[2][0] && field[1][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return ++count;
    }
}

//проверка на ничью
int checkDrawBot(char** field, int amountOfFreePlaces) {
    int count = 0;
    if (amountOfFreePlaces > 0) {
        return count;
    }
    else {
        cout << "Draw" << endl;
        return ++count;
    }
}

//Переписывания массива в ход игрока
char** rewriteMassiveBotuserStep(char** field, char symbol) {
    int x, y;
    cout << "Enter a row of place: ";
    cin >> x;
    cout << endl << "Enter a column of place: ";
    cin >> y;

    while ((x < 0 || x > 2) || (y < 0 || y > 2)) {
        cout << "Enter a row of place: ";
        cin >> x;
        cout << endl << "Enter a column of place: ";
        cin >> y;
    }

    while (field[x][y] != '+') {
        cout << "Enter a row of place: ";
        cin >> x;
        cout << endl << "Enter a column of place: ";
        cin >> y;
    }

    field[x][y] = symbol;

    return field;
}

//Переписывания массива в ход бота
char** rewriteMassiveBotStep(char** field) {
    int h, z;
    
    h = rand() % 3;
    z = rand() % 3;

    if (field[h][z] != '+') {
        h = rand() % 3;
        z = rand() % 3;
    }

    field[h][z] = 'X';

    return field;
}

//Основная функция которая имееют все нужные переменные и заканиавет программу
int playWithBot(char** field) {

    srand(time(NULL));

    char symbol = '0';
    int countOfSteps = 1;
    int amountOfFreePlaces = 9;

    int count = 0;

    while (checkWinnerBot(field, symbol, count) == 0 || checkDrawBot(field, amountOfFreePlaces) == 0) {

        countOfSteps++;

        writeMassiveBot(field);

        rewriteMassiveBotuserStep(field, symbol);

        rewriteMassiveBotStep(field);

        amountOfFreePlaces -= 2;
        if (checkWinnerBot(field, symbol, count) == 1 || checkDrawBot(field, amountOfFreePlaces) == 1) {
            return 0;
        }
    }
    return 0;
}
/*Знаю что код будет плохо оптимизирован так как можно было сделать одни обзие функцию
Такие как проверка на победу и ничью , а так же вывод масиива , но почему то я об этом подумал только сейчас
когда начал писать эти комментарии к коду*/

int main()
{
    //Создаем двухмерный массив для игры.
    char** field = new char* [3];

    for (int i = 0; i < 3; i++) {
        field[i] = new char[3];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            field[i][j] = '+';
        }
    }

    int choice;
    //Делаем выбор для игрока что он хочет сделать (точнее с кем играть или выйти)
    cout << "Choose with who u want to play : \n1 - friend\n2 - bot\n3 - exit" << endl;
    cin >> choice;
    while (choice < 1 || choice > 3) {
        cout << "Choose with who u want to play : \n1 - friend\n2 - bot\n3 - exit" << endl;
        cin >> choice;
    }

    if (choice == 1) {
        playWithFriend(field);
    }
    else if (choice == 2) {
        playWithBot(field);
    }
    else if (choice == 3) {
        return 0;
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    //Освобождаем память от массива
    for (int i = 0; i < 3; i++) {
        delete[] field[i];
    }

    delete[] field;
    field = nullptr;
    
}