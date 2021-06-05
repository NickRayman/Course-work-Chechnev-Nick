#include "InOut.h"

InOut::InOut()
{
}

InOut::~InOut()
{
}

pair<pair<size_t, size_t>, pair<size_t, size_t>> InOut::GetMove(string player)
{
    size_t p1, p2;

    string line1, line2;

    bool isLine1Number = true, isLine2Number = true;

    pair<pair<size_t, size_t>, pair<size_t, size_t>> position;

    cout << player << " move:" << endl;

    cin >> line1;
    cin >> line2;
    for_each(line1.cbegin(), line1.cend(), [&](char c) {
        if (!isdigit(c))
            isLine1Number = false;
        });
    for_each(line2.cbegin(), line2.cend(), [&](char c) {
        if (!isdigit(c))
            isLine2Number = false;
        });
    
    if (!isLine2Number || !isLine1Number) {
        if (line1 == "ff") {
            // 00 00 передвижение означает сдаться
            position.first.first = 0;
            position.first.second = 0;
            position.second.first = 0;
            position.second.second = 0;
        }
        else {
            // 11 11 не правильный ход пользователя
            position.first.first = 1;
            position.first.second = 1;
            position.second.first = 1;
            position.second.second = 1;
        }
    }
    else {

        p1 = (size_t) stoi(line1);
        p2 = (size_t) stoi(line2);

        position.first.first = p1 / 10;
        position.first.second = p1 - 10 * position.first.first;

        position.second.first = p2 / 10;
        position.second.second = p2 - 10 * position.second.first;
    }
   
   

    return move(position);
}

void InOut::DrawBoard(const map<pair<size_t, size_t>, Cell>& board)
{
    size_t cBoardSize = static_cast<size_t>(sqrt(board.size()));

    for (size_t i = 0; i < cBoardSize; i++) {

        cout << "|";
        for (size_t j = 0; j < cBoardSize; j++) {

            cout << CastState(board.at(pair<size_t, size_t>(i, j)).GetState());
            cout << "|";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void InOut::PrintScore(size_t whiteScore, size_t blackScore)
{
    
    cout << "White Player score: " << whiteScore << endl;
    cout << "Black Player score: " << blackScore << endl;
    cout << endl;
}

void InOut::endGame(string player)
{
    cout << "\nGame over!" << endl << player << " wins!" << endl;
}

string InOut::CastState(State state)
{
    string result;
    
    switch (state) {

    case State::BLACK:
        result = "B";
        break;
    case State::WHITE:
        result = "W";
        break;
    default:
        result = " ";
        break;
    }

    return move(result);
}


    
