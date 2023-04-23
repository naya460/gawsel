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

#pragma once

#include <cstdint>

#include "MinesweeperUI.hpp"

class MinesweeperCUI : public MinesweeperUI {
private:
    std::uint8_t cur_row = 0;
    std::uint8_t cur_column = 0;

    // コマンドを入力
    bool Input() noexcept;
public:
    // コンストラクタ
    MinesweeperCUI() = default;

    // ゲームのメインループを実行
    void Run() noexcept;
    
    // 新しい盤面で開始
    void NewGame(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept override;

    // 盤面を表示
    void Display() noexcept override;

    // セルを開ける
    bool Open(std::uint16_t position) noexcept override;
    bool Open(std::uint8_t row, std::uint8_t column) noexcept override;

    // 旗を切り替える
    void ToggleFlag(std::uint16_t position) noexcept override;
    void ToggleFlag(std::uint8_t row, std::uint8_t column) noexcept override;
    
    // 爆弾の残り数を表示
    void DisplayRemainingMines() noexcept override;

    // クリアしているか調べる(爆弾の数と開けていないセルの数を比較)
    bool IsSuccess() noexcept override;
};