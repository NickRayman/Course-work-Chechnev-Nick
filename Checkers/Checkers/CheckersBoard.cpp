#include "CheckersBoard.h"


int CheckersBoard::numberToRow(int num)
{
    return (num - 1) / 4;
}

int CheckersBoard::numberToCol(int num)
{
    if (num % 8 <= 4) {

        if (num % 8 == 0)
            return 6;
        return (num % 8) * 2 - 1;
    }
    else {
        if (num % 8 == 0)
            return 7;
        return (num % 4 - 1) * 2;
    }
}

bool CheckersBoard::checkBounds(int row, int col)
{
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize)
        return false;
    return true;
}

bool CheckersBoard::canBeFigth(int rowFrom, int colFrom, int rowWhat, int colWhat)
{
    int rowDif, colDif;
    rowDif = rowWhat - rowFrom;
    colDif = colWhat - colFrom;

    int rowTo, colTo;
    rowTo = rowWhat + rowDif;
    colTo = colWhat + colDif;

    if (!checkBounds(rowTo, colTo))
        return false;

    if (cells[rowTo][colTo] == BLACK)
        return true;

    return false;
}

CheckersBoard::CheckersBoard(int pattern)
{
    cells = new CellTypes * [this->boardSize];
    for (int i = 0; i < this->boardSize; i++)
        cells[i] = new CellTypes[this->boardSize];


    int blackCells = 0;
    int whiteCells = 0;
    switch (pattern) {

    case 1:
        for (int row = 0; row < this->boardSize; row++) {
            for (int col = 0; col < this->boardSize; col++) {
                if (row < 3) {
                    if ((row + col) % 2 == 0)
                        cells[row][col] = WHITE;
                    else
                        cells[row][col] = BlACK_DRAUGHT;
                }
                if ((2 < row) && (row < 5)) {
                    if ((row + col) % 2 == 0)
                        cells[row][col] = WHITE;
                    else
                        cells[row][col] = BLACK;
                }
                if (4 < row) {
                    if ((row + col) % 2 == 0)
                        cells[row][col] = WHITE;
                    else
                        cells[row][col] = WHITE_DRAUGHT;
                }
            }
        }
        return;
    case 2:
        for (int row = 0; row < this->boardSize; row++) {
            for (int col = 0; col < this->boardSize; col++) {
                if ((row + col) % 2 == 0)
                    cells[row][col] = WHITE;
                else
                    cells[row][col] = BLACK;
            }
        }
        int value;
        while (true) {

            display();
            cout << "Куда поставить чёрную шашку? Введите 0, чтобы закончить ";
            cin >> value;
            if (value == 0)
                break;
            cells[numberToRow(value)][numberToCol(value)] = BlACK_DRAUGHT;
            blackCells++;
        }
        while (true) {

            display();
            cout << "Куда ставим чёрную дамку? Введите 0, чтобы закончить. ";
            cin >> value;
            if (value == 0)
                break;
            cells[numberToRow(value)][numberToCol(value)] = BLACK_KING;
            blackCells++;
        }
        while (true) {

            display();
            cout << "Куда поставить белую шашку? Введите 0, чтобы закончить ";
            cin >> value;
            if (value == 0)
                break;
            cells[numberToCol(value)][numberToCol(value)] = WHITE_DRAUGHT;
            whiteCells++;
        }
        while (true) {

            display();
            cout << "Куда ставим белую дамку? Введите 0, чтобы закончить. ";
            cin >> value;
            if (value == 0)
                break;
            cells[numberToRow(value)][numberToCol(value)] = WHITE_KING;
            whiteCells++;
        }
        display();
        if (blackCells == 0 || whiteCells == 0)
            exit(0);
        return;
    default:
        exit(0);

    }
}

CheckersBoard::CheckersBoard(CheckersBoard* board)
{
    this->boardSize = board->boardSize;
    cells = new CellTypes * [boardSize];
    for (int i = 0; i < this->boardSize; i++)
        cells[i] = new CellTypes[this->boardSize];

    for (int row = 0; row < boardSize; row++)
        for (int col = 0; col < boardSize; col++)
            this->cells[row][col] = board->cells[row][col];
}

CheckersBoard::~CheckersBoard()
{
    for (int i = 0; i < boardSize; i++)
        delete[] cells[i];
    delete[] cells;
}

void CheckersBoard::display()
{
    system("cls");//вызов system для постоянного обновления страницы
    cout << " -*-*-*- Нумерация клеток -*-*-*-" << endl;
    int cellCount = 1;
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {

            if ((row + col) % 2 != 0) {

                if (cellCount < 10) {
                    cout << "| " << cellCount << "|";
                    cellCount++;
                }
                else {
                    cout << "|" << cellCount << "|";
                    cellCount++;
                }
            }
            else
                cout << "|  |";
        }
        cout << endl;
    }
    cout << endl;
    cout << (char)(1) << "- чёрные шашки, " << (char)(4) << "- чёрные дамки" << endl << (char)(2) << "- белые шашки, " << (char)(15) << "- белые дамки" << endl;
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {

            switch (cells[row][col]) {

            case BlACK_DRAUGHT:
                cout << "| " << (char)(1) << "|";
                break;
            case WHITE_DRAUGHT:
                cout << "| " << (char)(2) << "|";
                break;
            case WHITE:
                cout << "|  |";
                break;
            case BLACK:
                cout << "|" << (char)(5) << (char)(5) << "|";
                break;
            case BLACK_KING:
                cout << "| " << (char)(4) << "|";
                break;
            case WHITE_KING:
                cout << "| " << (char)(15) << "|";
            }
        }
        cout << endl;
    }
}

bool CheckersBoard::moveDraught(int from, int to)
{
    if (from < 0 || to < 0) {
        cout << from << " !!! " << to << endl;
        _getch();
    }

    int rowTo = numberToRow(to), colTo = numberToCol(to);
    int rowFrom = numberToRow(from), colFrom = numberToCol(from);
    cells[rowTo][colTo] = cells[rowFrom][colFrom];
    cells[rowFrom][colFrom] = BLACK;
    if (abs(rowTo - rowFrom) == 2) {

        /*cout << "Съел!" << endl;*/
        cells[rowFrom + (rowTo - rowFrom) / 2][colFrom + (colTo - colFrom) / 2] = BLACK;

        if (cells[rowTo][colTo] == BlACK_DRAUGHT && rowTo == 7) {
            cells[rowTo][colTo] = BLACK_KING;
            return false;
        }
        if (cells[rowTo][colTo] == WHITE_DRAUGHT && rowTo == 0) {
            cells[rowTo][colTo] = WHITE_KING;
            return false;
        }
        return true;
    }

    if (cells[rowTo][colTo] == BlACK_DRAUGHT && rowTo == 7) {
        cells[rowTo][colTo] = BLACK_KING;
        return false;
    }
    if (cells[rowTo][colTo] == WHITE_DRAUGHT && rowTo == 0) {
        cells[rowTo][colTo] = WHITE_KING;
        return false;
    }

    return false;
}

bool CheckersBoard::checkRegulations(int from, CellTypes cell)
{
    if ((from < 0) || (from > 32)) {
        cout << endl;
        cout << "*- Выход за границы! -*" << endl;
        return false;
    }

    if (cell == BlACK_DRAUGHT) {
        if (!(cells[numberToRow(from)][numberToCol(from)] == BLACK_KING || cells[numberToRow(from)][numberToCol(from)] == BlACK_DRAUGHT)) {

            cout << endl;
            cout << "*- Выберите чёрную шашку! -*" << endl;
            return false;
        }
    }
    if (cell == WHITE_DRAUGHT) {
        if (!(cells[numberToRow(from)][numberToCol(from)] == WHITE_KING || cells[numberToRow(from)][numberToCol(from)] == WHITE_DRAUGHT)) {

            cout << endl;
            cout << "*- Выберите белую шашку! -*" << endl;
            return false;
        }
    }

    //Проверка на обязанность поедания
    int** flashes = new int* [16];
    int* allowedDraughts = new int[16];
    int value = 0;
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            if (cell == BlACK_DRAUGHT) {
                if (cells[row][col] == BlACK_DRAUGHT || cells[row][col] == BLACK_KING) {

                    flashes[value] = possibleЬMoves(rowAndColToNum(row, col));
                    if (flashes[value][0] != 0 && abs(numberToRow(flashes[value][0]) - row) == 2) {

                        allowedDraughts[value] = rowAndColToNum(row, col);
                        value++;
                    }
                }
            }
            if (cell == WHITE_DRAUGHT) {
                if (cells[row][col] == WHITE_DRAUGHT || cells[row][col] == WHITE_KING) {

                    flashes[value] = possibleЬMoves(rowAndColToNum(row, col));
                    if (flashes[value][0] != 0 && abs(numberToRow(flashes[value][0]) - row) == 2) {

                        allowedDraughts[value] = rowAndColToNum(row, col);
                        value++;
                    }
                }
            }
        }
    }

    if (value != 0) {
        for (int i = 0; i < value; i++)
            if (from == allowedDraughts[i])
                return true;
        cout << endl;
        cout << "Надо есть! Выберите нужную шашку!" << endl;
        return false;
    }

    return true;
}

bool CheckersBoard::checkEndGame()
{
    int blackCount = 0, whiteCount = 0;
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            if (cells[row][col] == BlACK_DRAUGHT || cells[row][col] == BLACK_KING)
                blackCount++;
            if (cells[row][col] == WHITE_DRAUGHT || cells[row][col] == WHITE_KING)
                whiteCount++;
        }
    }
    if (blackCount == 0 || whiteCount == 0 || possibleDraughts(BlACK_DRAUGHT)[0] == 0 || possibleDraughts(WHITE_DRAUGHT)[0] == 0)
        return true;

    return false;
}

int* CheckersBoard::possibleЬMoves(int from, bool fight)
{
    int row, col;
    int* flashes = new int[4];

    row = numberToRow(from), col = numberToCol(from);
    CellTypes cell = cells[row][col];

    for (int i = 0; i < 4; i++)
        flashes[i] = 0;
    int value = 0;
    bool pl_fight = fight;

    //Число возмодных ходов черной дамки
    if (cell == BLACK_KING) {
        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {

                if (!checkBounds(row + i, col + j))
                    continue;
                if (cells[row + i][col + j] == WHITE_DRAUGHT || cells[row + i][col + j] == WHITE_KING) {
                    if (canBeFigth(row, col, row + i, col + j)) {

                        flashes[value] = rowAndColToNum(row + i * 2, col + j * 2);
                        value++;
                        pl_fight = true;
                    }
                }
            }
        }
    }
    if (cell == BLACK_KING && !pl_fight) {
        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {
                if (!checkBounds(row + i, col + j))
                    continue;
                if (cells[row + i][col + j] == BLACK) {
                    flashes[value] = rowAndColToNum(row + i, col + j);
                    value++;
                }
            }
        }
    }

    //Число возмодных ходов черной шашки
    if (cell == BlACK_DRAUGHT) {
        for (int j = -1; j <= 1; j += 2) {
            if (!checkBounds(row + 1, col + j))
                continue;
            if (cells[row + 1][col + j] == WHITE_DRAUGHT || cells[row + 1][col + j] == WHITE_KING) {
                if (canBeFigth(row, col, row + 1, col + j)) {

                    flashes[value] = rowAndColToNum(row + 2, col + j * 2);
                    value++;
                    pl_fight = true;
                }
            }
        }
    }
    if (cell == BlACK_DRAUGHT && !pl_fight) {
        for (int j = -1; j <= 1; j += 2) {
            if (!checkBounds(row + 1, col + j))
                continue;
            if (cells[row + 1][col + j] == BLACK) {
                flashes[value] = rowAndColToNum(row + 1, col + j);
                value++;
            }
        }
    }

    //Число возмодных ходов белой дамки
    if (cell == WHITE_KING) {
        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {

                if (!checkBounds(row + i, col + j))
                    continue;
                if (cells[row + i][col + j] == BlACK_DRAUGHT || cells[row + i][col + j] == BLACK_KING) {
                    if (canBeFigth(row, col, row + i, col + j)) {

                        flashes[value] = rowAndColToNum(row + i * 2, col + j * 2);
                        value++;
                        pl_fight = true;
                    }
                }
            }
        }
    }
    if (cell == WHITE_KING && !pl_fight) {
        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {
                if (!checkBounds(row + i, col + j))
                    continue;
                if (cells[row + i][col + j] == BLACK) {
                    flashes[value] = rowAndColToNum(row + i, col + j);
                    value++;
                }
            }
        }
    }

    //Число возмодных ходов белой шашки
    if (cell == WHITE_DRAUGHT) {
        for (int j = -1; j <= 1; j += 2) {
            if (!checkBounds(row - 1, col + j))
                continue;
            if (cells[row + 1][col + j] == BlACK_DRAUGHT || cells[row - 1][col + j] == BLACK_KING) {
                if (canBeFigth(row, col, row - 1, col + j)) {

                    flashes[value] = rowAndColToNum(row - 2, col + j * 2);
                    value++;
                    pl_fight = true;
                }
            }
        }
    }
    if (cell == WHITE_DRAUGHT && !pl_fight) {
        for (int j = -1; j <= 1; j += 2) {
            if (!checkBounds(row - 1, col + j))
                continue;
            if (cells[row - 1][col + j] == BLACK) {
                flashes[value] = rowAndColToNum(row - 1, col + j);
                value++;
            }
        }
    }

    return flashes;
}

int* CheckersBoard::possibleDraughts(CellTypes cell)
{
    int** flashes = new int* [16];
    int* allowedDraughts = new int[16];
    int value = 0;

    for (int i = 0; i < 16; i++)
        allowedDraughts[i] = 0;

    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {

            if (cell == BlACK_DRAUGHT) {
                if (cells[row][col] == BlACK_DRAUGHT || cells[row][col] == BLACK_KING) {

                    flashes[value] = possibleЬMoves(rowAndColToNum(row, col));
                    if (flashes[value][0] != 0 && abs(numberToRow(flashes[value][0]) - row) == 2) {

                        allowedDraughts[value] = rowAndColToNum(row, col);
                        value++;
                    }
                }

            }
            if (cell == WHITE_DRAUGHT) {
                if (cells[row][col] == WHITE_DRAUGHT || cells[row][col] == WHITE_KING) {

                    flashes[value] = possibleЬMoves(rowAndColToNum(row, col));
                    if (flashes[value][0] != 0 && abs(numberToRow(flashes[value][0]) - row) == 2) {

                        allowedDraughts[value] = rowAndColToNum(row, col);
                        value++;
                    }
                }

            }
        }
    }
    if (allowedDraughts[0] == 0) {
        for (int row = 0; row < boardSize; row++) {
            for (int col = 0; col < boardSize; col++) {
                if (cell == BlACK_DRAUGHT) {
                    if (cells[row][col] == BlACK_DRAUGHT || cells[row][col] == BLACK_KING) {
                        flashes[value] = possibleЬMoves(rowAndColToNum(row, col));
                        if (flashes[value][0] != 0) {
                            allowedDraughts[value] = rowAndColToNum(row, col);
                            value++;
                        }
                    }
                }

                if (cell == WHITE_DRAUGHT) {
                    if (cells[row][col] == WHITE_DRAUGHT || cells[row][col] == WHITE_KING) {
                        flashes[value] = possibleЬMoves(rowAndColToNum(row, col));
                        if (flashes[value][0] != 0) {
                            allowedDraughts[value] = rowAndColToNum(row, col);
                            value++;
                        }
                    }
                }
            }
        }
    }
    return allowedDraughts;
}

CellTypes CheckersBoard::getCell(int row, int col)
{
    return cells[row][col];
}

int CheckersBoard::rowAndColToNum(int row, int col)
{
    if (row % 2 == 0)
        return row * 4 + (col + 1) / 2;
    else
        return row * 4 + (col + 2) / 2;
}

bool operator==(const CheckersBoard& left, const CheckersBoard& right)
{
    cout << "Проверка!" << endl;
    for (int row = 0; row < left.boardSize; row++) {
        for (int col = 0; col < left.boardSize; col++) {
            if (left.cells[row][col] != right.cells[row][col])
                return false;
        }
    }
    return true;
}

bool operator!=(const CheckersBoard& left, const CheckersBoard& right)
{
    return !(left == right);
}
