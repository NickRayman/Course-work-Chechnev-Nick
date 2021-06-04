#include "InOut.h"

InOut::InOut()
{
}

InOut::~InOut()
{
}

pair<pair<size_t, size_t>, pair<size_t, size_t>> InOut::GetMove()
{
    size_t p1, p2;

    pair<pair<size_t, size_t>, pair<size_t, size_t>> position;

    cin >> p1;
    cin >> p2;
    position.first.first = p1 / 10;
    position.first.second = p1 - 10 * position.first.first;

    position.second.first = p2 / 10;
    position.second.second = p2 - 10 * position.second.first;

    return move(position);
}

void InOut::DrawBoard(const map<pair<size_t, size_t>, Cell>& board)
{
    size_t cBoardSize = sqrt(board.size());

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


    
