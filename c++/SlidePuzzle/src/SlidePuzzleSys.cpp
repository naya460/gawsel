#include "SlidePuzzleSys.hpp"

#include <iostream>

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
    // 座標を計算
    uint16_t position = (
        static_cast<uint16_t>(y) * static_cast<uint16_t>(this->length)
        + static_cast<uint16_t>(x)
    );
    // 左が空いているとき移動
    if (x >= 1 && board[position - 1] == 0) {
        board[position - 1] = board[position];
        board[position] = 0;
        return true;
    }
    // 右が空いているとき移動
    if (x < this->length - 1 && board[position + 1] == 0) {
        board[position + 1] = board[position];
        board[position] = 0;
        return true;
    }
    // 上が空いているとき移動
    if (y >= 1 && board[position - this->length] == 0) {
        board[position - this->length] = board[position];
        board[position] = 0;
        return true;
    }
    // 下が空いているとき移動
    if (y < this->length - 1 && board[position + this->length] == 0) {
        board[position + this->length] = board[position];
        board[position] = 0;
        return true;
    }
    return false;
}

bool SlidePuzzleSys::move_number(uint16_t position) noexcept {
    return move_number(
        static_cast<uint8_t>(position % this->length),
        static_cast<uint8_t>(position / this->length)
    );
}

uint8_t SlidePuzzleSys::get_length() noexcept {
    return this->length;
}

uint16_t SlidePuzzleSys::get_size() noexcept {
    return this->length * this->length;
}

uint16_t SlidePuzzleSys::get_number(uint16_t position) {
    // 範囲外のとき、例外を投げる
    if (position >= get_size()) {
        throw(false);
    }
    // 指定された場所の数字を返却
    return board[position];
}