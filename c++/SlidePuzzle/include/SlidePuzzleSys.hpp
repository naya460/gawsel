#pragma once

#include <cstdint>
#include <vector>

class SlidePuzzleSys {
private:
    uint8_t length = 4; // 辺の長さ
    std::vector<uint16_t> board; // 盤面

public:
    // コンストラクタ
    SlidePuzzleSys();

    // 辺の長さを取得
    uint8_t get_length() noexcept;

    // 盤面のサイズを取得
    uint16_t get_size() noexcept;

    // 場所から数字を取り出す (範囲外のとき、falseの例外を投げる)
    uint16_t get_number(uint16_t position);
};