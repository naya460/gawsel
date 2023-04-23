/*
  Copyright 2023 naya460

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include "LightsOutCUI.hpp"

#include <iostream>

bool LightsOutCUI::Inside(std::uint16_t min, std::uint16_t target, std::uint16_t max) noexcept{
    return min <= target && target <= max;
}

std::uint16_t LightsOutCUI::Input(std::string str, std::uint16_t min, std::uint16_t max){
    int num;
    while (true) {
        std::cout << str;
        std::cin >> num;
        // 範囲内のときループを抜ける
        if (Inside(min, num, max)) break;
        // 範囲外のとき
        std::cout << "Try again..." << std::endl;
    }
    return num;
}

void LightsOutCUI::Run() noexcept{
    // メインループ
    while (true) {
        // 大きさを聞く
        unsigned int length = 3;
        length = Input("Input board length (2 - 255) : ", 2, 255);

        // 新しい盤面を開始
        NewGame(length);
        std::cout << "Game : " << length << "x" << length << std::endl;

        // クリアまで入力と表示を繰り返す
        while (!IsSuccess()) {
            // 出力
            Display();

            // 入力
            unsigned int row = 0, column = 0;
            
            std::string row_str = "Input row (0-" + std::to_string(length - 1) + ") : ";
            row = Input(row_str, 0, length - 1);

            std::string column_str = "Input column (0-" + std::to_string(length - 1) + ") : ";
            column = Input(column_str, 0, length - 1);
            
            Push(row, column);
        }
        // もう一度遊ぶか聞く
        bool exit = true;
        std::cout << "Clear" << std::endl << "0:continue 1:exit" << std::endl << ">>> ";
        std::cin >> exit;
        if (exit == true) break;
    }
}

void LightsOutCUI::NewGame(std::uint8_t length) noexcept{
    system.set_length(length);
    system.random();
}

void LightsOutCUI::Display() noexcept{
    // 大きさを取得
    std::uint8_t length = system.get_length();
    std::uint16_t size = system.get_size();
    // 表示
    for (std::uint16_t i = 0; i < size; ++i) {
        std::cout << ((system.is_on(i))? "o" : "_") << " ";
        // 列の最後のとき改行
        if ((i + 1) % length == 0) {
            std::cout << std::endl;
        }
    }
}

bool LightsOutCUI::Push(std::uint16_t position) noexcept{
    try {
        system.push(position);
    }
    catch (bool exception) {
        return false;
    }
    return true;
}

bool LightsOutCUI::Push(std::uint8_t row, std::uint8_t column) noexcept{
    try {
        system.push(row, column);        
    }
    catch (bool exception) {
        return false;
    }
    return true;
}

bool LightsOutCUI::IsSuccess() noexcept{
    return system.check_clear();
}