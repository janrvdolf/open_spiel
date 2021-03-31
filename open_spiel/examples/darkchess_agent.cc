#include <iostream>
#include <memory>

#include "open_spiel/spiel.h"
#include "open_spiel/games/dark_chess.h"

#include "open_spiel/games/chess.h"
#include "open_spiel/games/chess/chess_board.h"



int main () {
    int board_size = 4;
    const std::string fen_silverman4by4 = "rqkr/pppp/PPPP/RQKR w - - 0 1";

    open_spiel::GameParameters params;
    params["board_size"] = open_spiel::GameParameter(board_size);
    params["fen"] = open_spiel::GameParameter(fen_silverman4by4);

//    open_spiel::dark_chess::DarkChessGame game = open_spiel::dark_chess::DarkChessGame(params);

    std::shared_ptr<const open_spiel::Game> game = LoadGame("dark_chess", params);

    std::unique_ptr<open_spiel::State> state = game->NewInitialState();
//    std::unique_ptr<open_spiel::State> state = *game->NewInitialState();

    while(!state->IsTerminal()) {

        auto actions = state->LegalActions();

        std::string state_string = state->ToString();

        for (auto action: state->LegalActions()) {
            std::cout << "Ahoj" << std::endl;

            std::string action_string = state->ActionToString(action);

            open_spiel::chess::Move move = ActionToMove(action, open_spiel::chess::ChessBoard());
            std::cout << open_spiel::chess::SquareToString(move.from) << std::endl;
            std::cout << open_spiel::chess::SquareToString(move.to) << std::endl;

            std::cout << action_string<< std::endl;
        }
    }

    std::cout << "Hello world!" << std::endl;

    return 0;
}