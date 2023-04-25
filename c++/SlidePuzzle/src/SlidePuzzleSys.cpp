#include "SlidePuzzleSys.hpp"

SlidePuzzleSys::SlidePuzzleSys() {
    // 盤面のサイズを変更
    board.resize(get_size());

    // 順番に数字を割り当てる
    for (int i = 0; i < get_size(); ++i) {
        board[i] = i + 1;
    }
    board[board.size() - 1] = 0;
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