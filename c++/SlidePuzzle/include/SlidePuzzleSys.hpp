#pragma once

#include <cstdint>
#include <vector>
#include <optional>

class SlidePuzzleSys {
private:
    uint8_t length = 4; // 辺の長さ
    std::vector<uint16_t> board; // 盤面

public:
    // コンストラクタ
    SlidePuzzleSys();

    // 盤面をリセット
    void reset() noexcept;

    // 数字を移動 (移動できたとき、trueを返却)
    bool move_number(uint8_t x, uint8_t y) noexcept;
    bool move_number(uint16_t position) noexcept;

    // 座標を変換
    uint16_t xy_to_pos(uint8_t x, uint8_t y) const noexcept;
    uint8_t pos_to_x(uint16_t pos) const noexcept;
    uint8_t pos_to_y(uint16_t pos) const noexcept;

    // 辺の長さを変更
    bool set_length(uint8_t length) noexcept;

    // 辺の長さを取得
    uint8_t get_length() const noexcept;

    // 盤面のサイズを取得
    uint16_t get_size() const noexcept;

    // 場所から数字を取り出す (範囲外のとき、nulloptを返却)
    std::optional<uint16_t> get_number(uint16_t position) const noexcept;

    // ランダムに移動
    void randomize() noexcept;

    // クリアしているか確認
    bool check_clear() const noexcept;
};