#include <iostream>
#include <cstdint>

#include "LightsOutCUI.hpp"

int main(void){
    LightsOutCUI cui;
    // メインループ
    while (true) {
        // 大きさを聞く
        unsigned int length = 3;
        while (true) {
            std::cout << "Input board length (2 - 255) : ";
            std::cin >> length;
            // 範囲内のときループを抜ける
            if (2 <= length && length <= 255) break;
            // 範囲外のとき
            std::cout << "Try again..." << std::endl;
        }
        // 新しい盤面を開始
        cui.NewGame(length);
        std::cout << "Game : " << length << "x" << length << std::endl;
        // クリアまで入力と表示を繰り返す
        while (!cui.IsSuccess()) {
            // 出力
            cui.Display();
            // 入力
            unsigned int row = 0, column = 0;
            while (true) {
                std::cout << "Input row (0-" << length - 1 << ") : ";
                std::cin >> row;
                // 範囲内のときループを抜ける
                if (0 <= row && row <= length - 1) break;
                // 範囲外のとき
                std::cout << "Try again..." << std::endl;
            }
            while (true) {
                std::cout << "Input column (0-" << length - 1 << ") : ";
                std::cin >> column;
                // 範囲内のときループを抜ける
                if (0 <= column && column <= length - 1) break;
                // 範囲外のとき
                std::cout << "Try again..." << std::endl;
            }
            cui.Push(row, column);
        }
        // もう一度遊ぶか聞く
        bool exit = true;
        std::cout << "Clear" << std::endl << "0:continue 1:exit" << std::endl << ">>> ";
        std::cin >> exit;
        if (exit == true) break;
    }
    return 0;
}