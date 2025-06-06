#include "GameMap.h"

GameMap::GameMap()
{
    Size.x = 0;
    Size.y = 0;

    length = 0;

    map = new int*[Size.x];
    for (int i = 0; i < Size.x; i++) {
        map[i] = new int[Size.y];
    }
}

GameMap::GameMap(Vector2 _size, int leng)
{
    this->Size = _size;
    this->length = leng;

    map = new int* [Size.x];
    for (int i = 0; i < Size.x; i++) {
        map[i] = new int[Size.y];
    }
    // map to 0
    for (int i = 0; i < Size.x; i++) {
        for (int j = 0; j < Size.y; j++) {
            map[i][j] = 0;
        }
    }
}

GameMap::GameMap(int _i, int _j, int leng)
{
    Size.x = _i;
    Size.y = _j;
    this->length = leng;

    map = new int* [Size.x];
    for (int i = 0; i < Size.x; i++) {
        map[i] = new int[Size.y];
    }
    // map to 0
    for (int i = 0; i < Size.x; i++) {
        for (int j = 0; j < Size.y; j++) {
            map[i][j] = 0;
        }
    }
}

GameMap::~GameMap()
{
    for (int i = 0; i < Size.x; i++) {
        delete[] map[i];
    }
    delete[] map;
}

bool GameMap::setPosition(Vector2 cell, int c)
{
    if (isEmpty(cell)) {
        map[cell.x][cell.y] = c;
        return true;
    }
    else return false;
}

bool GameMap::isEmpty(Vector2 cell)
{
    if (map[cell.x][cell.y] == 0) return true;
    else false;
}

bool GameMap::isEmpty(int i, int j)
{
    if (map[i][j] == 0) return true;
    else false;
}

void GameMap::setMap(Vector2 _size, int leng)
{
    this->Size = _size;
    this->length = leng;

    map = new int* [Size.x];
    for (int i = 0; i < Size.x; i++) {
        map[i] = new int[Size.y];
    }
    // map to 0
    for (int i = 0; i < Size.x; i++) {
        for (int j = 0; j < Size.y; j++) {
            map[i][j] = 0;
        }
    }
}

void GameMap::setMap(int _i, int _j, int leng)
{
    Size.x = _i;
    Size.y = _j;
    this->length = leng;

    map = new int* [Size.x];
    for (int i = 0; i < Size.x; i++) {
        map[i] = new int[Size.y];
    }
    // map to 0
    for (int i = 0; i < Size.x; i++) {
        for (int j = 0; j < Size.y; j++) {
            map[i][j] = 0;
        }
    }
}

int GameMap::getValue(Vector2 cell) // returning val from map cell
{
    return map[cell.x][cell.y];
}

int GameMap::getValue(int _i, int _j)
{
    return map[_i][_j];
}

int GameMap::CheckList(std::vector<int> a)
{
    if (a.size() < length) return 0;
    bool WinP1 = false;
    bool WinP2 = false;

    int count1 = 0;
    int count2 = 0;

    // Checking score
    for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < i + length; j++) {
            if (j < a.size()) {
                if (a[j] == 1) count1++;
            }
            else break;
        }
        if (count1 >= length) {
            WinP1 = true;
            break;
        }
        count1 = 0;
    }
    for (int i = 0; i < a.size(); i++) { // checking second player
        for (int j = i; j < i + length; j++) {
            if (j < a.size()) {
                if (a[j] == 2) count2++;
            }
            else break;
        }
        if (count2 >= length) {
            WinP1 = true;
            break;
        }
        count2 = 0;
    }

    if (WinP1 && WinP2) return 3; // draw
    else if (!WinP1 && WinP2) return 2; // second won
    else if (WinP1 && !WinP2) return 1; // first won
    else return 0;
}

int GameMap::CheckingWin()
{
    int StateWin = 0;
    std::vector<int> check;

    for (int i = 0; i < Size.x; i++) { // gorizontal
        for (int j = 0; j < Size.y; j++) {
            check.push_back(map[i][j]);
        }
        StateWin = CheckList(check);
        check.clear();

        //Checking
        if (StateWin == 3) return 3; // draw
        else if (StateWin == 2) return 2; // win second
        else if (StateWin == 1) return 1; // win first

    }

    for (int i = 0; i < Size.x; i++) { // vertical
        for (int j = 0; j < Size.y; j++) {
            check.push_back(map[j][i]);
        }
        StateWin = CheckList(check);
        check.clear();

        //Checking
        if (StateWin == 3) return 3; // draw
        else if (StateWin == 2) return 2; // win second
        else if (StateWin == 1) return 1; // win first

    }

    for (int i = 0; i < Size.x; ++i) { // main diagonal and up her
        for (int j = 0; i + j < Size.y; ++j) {
            check.push_back(map[i+j][i]);
        }
        StateWin = CheckList(check);
        check.clear();

        //Checking
        if (StateWin == 3) return 3; // draw
        else if (StateWin == 2) return 2; // win second
        else if (StateWin == 1) return 1; // win first

    }
    for (int i = 1; i < Size.x; ++i) { // main diagonal and under her
        for (int j = 0; i + j < Size.y; ++j) {
            check.push_back(map[i + j][i]);
        }
        StateWin = CheckList(check);
        check.clear();

        //Checking
        if (StateWin == 3) return 3; // draw
        else if (StateWin == 2) return 2; // win second
        else if (StateWin == 1) return 1; // win first

    }

    //all rights diagonales
    for (int j = Size.y; j > 0; --j) { // 
        for (int i = 0; i < Size.x; ++i) {
            if (Size.x - i - j >= 0) check.push_back(map[i][Size.x - i - j]);
        }
        StateWin = CheckList(check);
        check.clear();

        //Checking
        if (StateWin == 3) return 3; // draw
        else if (StateWin == 2) return 2; // win second
        else if (StateWin == 1) return 1; // win first

    }

    for (int j = 0; j < Size.y; ++j) { // under poboch diagonal
        for (int i = 0; i < Size.x; ++i) {
            if (Size.x + j - i < Size.x) check.push_back(map[i][Size.x + j - i]);
        }
        StateWin = CheckList(check);
        check.clear();

        //Checking
        if (StateWin == 3) return 3; // draw
        else if (StateWin == 2) return 2; // win second
        else if (StateWin == 1) return 1; // win first

    }

    if (CanMove()) return 0; // win nobody
    else return 3; //draw
}

bool GameMap::CanMove()
{
    for (int i = 0; i < Size.x; i++) {
        for (int j = 0; j < Size.y; j++) {
            if (map[i][j] == 0) return true;
        }
    }
    return false;
}

Vector2 GameMap::GetCenter()
{
    Vector2 center;
    int x;
    if (Size.x % 2 != 0) {
        x = (Size.x - 1) / 2;
    }
    else x = (Size.x / 2) - 1;

    center.x = x;
    center.y = x;

    return center;
}
