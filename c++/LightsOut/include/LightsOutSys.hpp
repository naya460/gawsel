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
#include <vector>

class LightsOutSys {
private:
    std::uint8_t length = 0;    // 一辺のライトの数
    std::uint16_t size = 0;     // ライトの数
    std::vector<bool> board;    // 盤面

    // ライトを反転
    void invert(std::uint16_t pos);
    void invert(std::uint8_t row, std::uint8_t column);

    // すべてオフにする
    void clear() noexcept;
public:
    // コンストラクタ
    LightsOutSys();
    LightsOutSys(std::uint8_t length);

    // 大きさを変更
    void set_length(std::uint8_t length) noexcept;

    // 一辺のライトの数を取得
    std::uint8_t get_length() noexcept;

    // ライトの数を取得
    std::uint16_t get_size() noexcept;

    // ライトが光っているか確認（on:true, off:false）
    bool is_on(std::uint16_t pos);
    bool is_on(std::uint8_t row, std::uint8_t column);

    // ライトを押す
    void push(std::uint16_t pos);
    void push(std::uint8_t row, std::uint8_t column);

    // クリアしているか確認
    bool check_clear() noexcept;

    // ランダムに配置
    void random() noexcept;
};