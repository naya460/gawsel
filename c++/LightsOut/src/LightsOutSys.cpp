#include "LightsOutSys.hpp"

#include <random>

void LightsOutSys::invert(std::uint16_t pos){
    // 範囲外のとき、例外を投げる
    if (pos >= get_size()) {
        throw false;
    }
    // 反転
    board[pos] = ~board[pos];
}

void LightsOutSys::invert(std::uint8_t row, std::uint8_t column){
    // 反転
    invert(column * length + row);
}

LightsOutSys::LightsOutSys(std::uint8_t length){
    // 一辺のライトの数を変数に保存
    this->length = length;
    // ライトの数を変数に保存
    this->size = length * length;
    
    // 盤面の大きさを変更
    board.resize(size);
    // ランダムに配置
    random();
}

std::uint8_t LightsOutSys::get_length() noexcept{
    return length;
}

std::uint16_t LightsOutSys::get_size() noexcept{
    return size;
}

bool LightsOutSys::is_on(std::uint16_t pos){
    // 範囲外のとき、例外を投げる
    if (pos >= get_size()) {
        throw false;
    }
    // ライトの状態を返す
    return board[pos];
}

bool LightsOutSys::is_on(std::uint8_t row, std::uint8_t column){
    // ライトの状態を返す
    return is_on(column * length + row);
}

void LightsOutSys::push(std::uint16_t pos){
    push(pos % length, pos / length);
}

void LightsOutSys::push(std::uint8_t row, std::uint8_t column){
    // 範囲外のとき、例外を投げる
    if (row > length || column > length) {
        throw false;
    }
    // 反転
    invert(row, column);                              // 押した場所
    if (row > 0)             invert(row - 1, column); // 左
    if (row < length - 1)    invert(row + 1, column); // 右
    if (column > 0)          invert(row, column - 1); // 下
    if (column < length - 1) invert(row, column + 1); // 上
}