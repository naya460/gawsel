#include "SlidePuzzleSys.hpp"

#include <iostream>
#include <algorithm>

SlidePuzzleSys::SlidePuzzleSys() {
    // 盤面のサイズを変更
    board.resize(get_size());

    // 順番に数字を割り当てる
    for (int i = 0; i < get_size(); ++i) {
        board[i] = i + 1;
    }
    board[board.size() - 1] = 0;
}

bool SlidePuzzleSys::move_number(uint8_t x, uint8_t y) noexcept {
    // 範囲外のとき false を返却
    if (x >= this->length || y >= this->length) {
        return false;
    }
    // 0の位置を探す
    auto itr = std::find(board.begin(), board.end(), 0);
    uint16_t pos = itr - board.begin();
    // 0の位置のときfalseを返却
    if (pos == y * this->length + x) {
        return false;
    }
    // ゼロの場所を計算
    uint8_t zero_x = static_cast<uint8_t>(pos % this->length);
    uint8_t zero_y = static_cast<uint8_t>(pos / this->length);
    // 横の位置が同じのとき移動
    if (zero_x == x) {
        // 0が上のとき
        if (zero_y < y) {
            for (uint8_t i = zero_y; i < y; ++i) {
                board[i * this->length + x] = board[(i + 1) * this->length + x];
            }
        }
        // 0が下のとき
        else {
            for (uint8_t i = zero_y; i > y; --i) {
                board[i * this->length + x] = board[(i - 1) * this->length + x];
            }
        }
        board[y * this->length + x] = 0;
        return true;
    }
    // 縦の位置が同じのとき移動
    if (pos / this->length == y) {
        // 0が左のとき
        if (zero_x < x) {
            for (uint8_t i = zero_x; i < x; ++i) {
                board[i + y * this->length] = board[i + 1 + y * this->length];
            }
        }
        // 0が右のとき
        else {
            for (uint8_t i = zero_x; i > x; --i) {
                board[i + y *this->length] = board[i - 1 + y * this->length];
            }
        }
        board[x + y * this->length] = 0;
        return true;
    }
    // どこにも当てはまらなかったとき
    return false;
}

bool SlidePuzzleSys::move_number(uint16_t position) noexcept {
    return move_number(
        static_cast<uint8_t>(position % this->length),
        static_cast<uint8_t>(position / this->length)
    );
}

uint8_t SlidePuzzleSys::get_length() const noexcept {
    return this->length;
}

uint16_t SlidePuzzleSys::get_size() const noexcept {
    return this->length * this->length;
}

uint16_t SlidePuzzleSys::get_number(uint16_t position) const {
    // 範囲外のとき、例外を投げる
    if (position >= get_size()) {
        throw(false);
    }
    // 指定された場所の数字を返却
    return board[position];
}