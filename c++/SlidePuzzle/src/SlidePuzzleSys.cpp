#include "SlidePuzzleSys.hpp"

#include <iostream>
#include <algorithm>
#include <random>

SlidePuzzleSys::SlidePuzzleSys() {
    // 盤面の大きさを変更
    this->set_length(4);
}

void SlidePuzzleSys::reset() noexcept {
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
    uint8_t zero_x = pos_to_x(pos);
    uint8_t zero_y = pos_to_y(pos);
    // 横の位置が同じのとき移動
    if (zero_x == x) {
        // 0が上のとき
        if (zero_y < y) {
            for (uint8_t i = zero_y; i < y; ++i) {
                board[xy_to_pos(x, i)] = board[xy_to_pos(x, i + 1)];
            }
        }
        // 0が下のとき
        else {
            for (uint8_t i = zero_y; i > y; --i) {
                board[xy_to_pos(x, i)] = board[xy_to_pos(x, i - 1)];
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
                board[xy_to_pos(i, y)] = board[xy_to_pos(i + 1, y)];
            }
        }
        // 0が右のとき
        else {
            for (uint8_t i = zero_x; i > x; --i) {
                board[xy_to_pos(i, y)] = board[xy_to_pos(i - 1, y)];
            }
        }
        board[xy_to_pos(x, y)] = 0;
        return true;
    }
    // どこにも当てはまらなかったとき
    return false;
}

bool SlidePuzzleSys::move_number(uint16_t position) noexcept {
    return move_number(pos_to_x(position), pos_to_y(position));
}

uint16_t SlidePuzzleSys::xy_to_pos(uint8_t x, uint8_t y) const noexcept {
    return (
        static_cast<uint16_t>(y) * static_cast<uint16_t>(this->length)
        + static_cast<uint16_t>(x)
    );
}

uint8_t SlidePuzzleSys::pos_to_x(uint16_t pos) const noexcept {
    return pos % static_cast<uint16_t>(this->length);
}

uint8_t SlidePuzzleSys::pos_to_y(uint16_t pos) const noexcept {
    return pos / static_cast<uint16_t>(this->length);
}

bool SlidePuzzleSys::set_length(uint8_t length) noexcept {
    if (length < 2) return false;
    // 盤面の長さを変更
    this->length = length;
    // 盤面のサイズを変更
    board.resize(get_size());
    // 盤面をリセット
    this->reset();
    return true;
}

uint8_t SlidePuzzleSys::get_length() const noexcept {
    return this->length;
}

uint16_t SlidePuzzleSys::get_size() const noexcept {
    return this->length * this->length;
}

std::optional<uint16_t> SlidePuzzleSys::get_number(uint16_t position) const noexcept {
    // 範囲外のとき、nulloptを返却
    if (position >= get_size()) {
        return std::nullopt;
    }
    // 指定された場所の数字を返却
    return board[position];
}

void SlidePuzzleSys::randomize() noexcept {
    // 乱数の準備
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::uniform_int_distribution<> dist(0, length);

    // 盤面をリセット
    reset();

    // ランダムに移動
    int m = this->get_size() * 5;
    for (int i = 0; i < m; ++i) {
        if (!move_number(dist(engine), dist(engine))) continue;
    }
}

bool SlidePuzzleSys::check_clear() const noexcept {
    for (int i = 0; i < this->get_size() - 1; ++i) {
        if (board[i] != i + 1) return false;
    }
    return true;
}