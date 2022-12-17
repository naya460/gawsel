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
public:
    // コンストラクタ
    LightsOutSys(std::uint8_t length);

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
};