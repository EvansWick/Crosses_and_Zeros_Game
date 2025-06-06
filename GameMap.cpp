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
    if (cell.x < 0 || cell.x >= Size.x || cell.y < 0 || cell.y >= Size.y) return false;
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

//Checked
int GameMap::CheckList(std::vector<int> a)
{
    int current = 0;
    int count = 1;

    for (int i = 1; i < a.size(); i++) {
        if (a[i] != 0 && a[i] == a[i - 1]) {
            count++;
            if (count >= length)
                return a[i]; // 1 - player1 win, 2 - player2 win
        }
        else {
            count = 1;
        }
    }

    return 0; // nobody
}


//Checked
int GameMap::CheckingWin()
{
    int rows = Size.x;
    int cols = Size.y;

    // Горизонталі
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= cols - length; ++j) {
            std::vector<int> line;
            for (int k = 0; k < length; ++k)
                line.push_back(map[i][j + k]);
            int res = CheckList(line);
            if (res == 1 || res == 2) return res;
        }
    }

    // Вертикалі
    for (int i = 0; i <= rows - length; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::vector<int> line;
            for (int k = 0; k < length; ++k)
                line.push_back(map[i + k][j]);
            int res = CheckList(line);
            if (res == 1 || res == 2) return res;
        }
    }

    // Діагоналі \ (зліва направо вниз)
    for (int i = 0; i <= rows - length; ++i) {
        for (int j = 0; j <= cols - length; ++j) {
            std::vector<int> line;
            for (int k = 0; k < length; ++k)
                line.push_back(map[i + k][j + k]);
            int res = CheckList(line);
            if (res == 1 || res == 2) return res;
        }
    }

    // Діагоналі / (справа наліво вниз)
    for (int i = 0; i <= rows - length; ++i) {
        for (int j = length - 1; j < cols; ++j) {
            std::vector<int> line;
            for (int k = 0; k < length; ++k)
                line.push_back(map[i + k][j - k]);
            int res = CheckList(line);
            if (res == 1 || res == 2) return res;
        }
    }

    return CanMove() ? 0 : 3;
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
