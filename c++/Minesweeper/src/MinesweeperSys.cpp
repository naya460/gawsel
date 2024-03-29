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

#include "MinesweeperSys.hpp"

#include <algorithm>
#include <random>

// === Direction ===

Direction::Direction(std::int8_t horizontal, std::int8_t vertical){
    SetDirection(horizontal, vertical);
}

void Direction::SetDirection(std::int8_t horizontal, std::int8_t vertical){
    // horizontal
    this->horizontal = horizontal;
    if (horizontal < 0) horizontal = -1;
    if (horizontal > 0) horizontal = 1;
    // vertical
    this->vertical = vertical;
    if (vertical < 0) vertical = -1;
    if (vertical > 0) vertical = 1;
}

std::int8_t Direction::GetHorizontal(){
    return horizontal;
}

std::int8_t Direction::GetVertical(){
    return vertical;
}

// === MinesweeperSys ===

std::uint16_t MinesweeperSys::PosFrom(std::uint8_t row, std::uint8_t column) noexcept{
    return row * column_num + column;
}

bool MinesweeperSys::CheckDirection(Direction dir, std::uint16_t pos) noexcept{
    bool ok = true; // 存在するか保存する変数
    // 上側
    if (dir.GetVertical() > 0) {
        if (pos < column_num) ok = false;
    }
    // 下側
    if (dir.GetVertical() < 0) {
        if (pos >= column_num * (row_num - 1)) ok = false;
    }
    // 左側
    if (dir.GetHorizontal() < 0) {
        if (pos % column_num == 0) ok = false;
    }
    // 右側
    if (dir.GetHorizontal() > 0) {
        if ((pos + 1) % column_num == 0) ok = false;
    }
    // 返却
    return ok;
}

std::uint16_t MinesweeperSys::CalcDirectionPos(Direction dir, std::uint16_t pos) noexcept{
    if (dir.GetVertical() > 0) pos -= column_num;    // 上側
    if (dir.GetVertical() < 0) pos += column_num;    // 下側
    if (dir.GetHorizontal() < 0) pos -= 1;           // 左側
    if (dir.GetHorizontal() > 0) pos += 1;           // 右側
    return pos;
}

void MinesweeperSys::AddCellNum(std::uint16_t pos) noexcept{
    // 特定の方向の数字を加算
    auto AddDirectionNum = [&](Direction dir, std::uint16_t pos) -> void {
            // セルが存在しないとき何もしない
        if (!CheckDirection(dir, pos)) return;
        
        // その方向の場所を計算
        pos = CalcDirectionPos(dir, pos);

        // セルの値を加算
        board[pos].AddCellNum();
    };
    // 全ての方向に対して実行
    AddDirectionNum(Direction(-1,  1), pos);    // 左上
    AddDirectionNum(Direction( 0,  1), pos);    // 上
    AddDirectionNum(Direction( 1,  1), pos);    // 右上
    AddDirectionNum(Direction(-1,  0), pos);    // 左
    AddDirectionNum(Direction( 1,  0), pos);    // 右
    AddDirectionNum(Direction(-1, -1), pos);    // 左下
    AddDirectionNum(Direction( 0, -1), pos);    // 下
    AddDirectionNum(Direction( 1, -1), pos);    // 右下
}

void MinesweeperSys::Random(std::uint16_t pos) noexcept{
    // 配置を初期化
    Reset();
    // 開始したことにする
    started = true;

    // 乱数の準備
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());

    // 座標の一覧
    std::uint16_t size = row_num * column_num;
    std::vector<std::uint16_t> list;
    list.resize(size);
    for (std::uint16_t i = 0; i < size; ++i) {
        list[i] = i;
    }

    // 安全圏を設置
    auto EraseListPos = [=, &list](Direction dir, std::uint16_t pos) -> void {
        // セルが存在しないとき何もしない
        if (!CheckDirection(dir, pos)) return;
        
        // その方向の場所を計算
        pos = CalcDirectionPos(dir, pos);

        // 値を削除
        list.erase(list.begin() + pos);
    };
    EraseListPos(Direction( 1, -1), pos);    // 右下
    EraseListPos(Direction( 0, -1), pos);    // 下
    EraseListPos(Direction(-1, -1), pos);    // 左下
    EraseListPos(Direction( 1,  0), pos);    // 右
    EraseListPos(Direction( 0,  0), pos);    // 中央
    EraseListPos(Direction(-1,  0), pos);    // 左
    EraseListPos(Direction( 1,  1), pos);    // 右上
    EraseListPos(Direction( 0,  1), pos);    // 上
    EraseListPos(Direction(-1,  1), pos);    // 左上

    // ランダムに爆弾を設置
    for (std::uint16_t i = 0; i < mine; ++i) {
        // 乱数を作成
        std::uniform_int_distribution<> dist(0, list.size() - 1);
        std::uint16_t pos = dist(engine);

        // 爆弾を挿入
        board[list[pos]].SetData(CellData::Mine);
        
        // 数字を増やす
        AddCellNum(list[pos]);

        // 今の座標を削除
        list.erase(list.begin() + pos);
    }
}

MinesweeperSys::MinesweeperSys(){
    // 何もない盤面を作成
    SetSizeAndMine(0, 0, 0);
}

MinesweeperSys::MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine){
    // 盤面の大きさを設定
    SetSizeAndMine(row_number, column_number, mine);
}

void MinesweeperSys::SetSizeAndMine(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept{
    // 大きさを保存
    row_num = row_number;
    column_num = column_number;
    // 爆弾の数を変更
    this->mine = std::min(mine, static_cast<std::uint16_t>(GetSize() - 9));
    // 盤面の大きさを変更
    board.resize(GetSize());
    Reset();
}

std::uint8_t MinesweeperSys::GetRowNumber() noexcept{
    return row_num;
}

std::uint8_t MinesweeperSys::GetColumnNumber() noexcept{
    return column_num;
}

std::uint16_t MinesweeperSys::GetSize() noexcept{
    return row_num * column_num;
}

void MinesweeperSys::Reset() noexcept{
    for (std::uint16_t i = 0; i < GetSize(); ++i) {
        board[i].Reset();
    }
    started = false;
    closing_cells = GetSize();
}

CellData MinesweeperSys::GetCellData(std::uint16_t pos) noexcept{
    return board[pos].GetData();
}

CellData MinesweeperSys::GetCellData(std::uint8_t row, std::uint8_t column) noexcept{
    return GetCellData(PosFrom(row, column));
}

bool MinesweeperSys::Open(std::uint16_t pos){
    //存在するか確認
    if (pos >= GetSize()) throw(false);

    // 旗のとき関数を抜ける
    if (board[pos].IsFlagged()) {
        return false;
    }

    // 最初に開けたとき、生成
    if (started == false) Random(pos);
    
    // 空いているとき、falseを返す
    if (board[pos].IsOpen()) return false;

    // 押した場所を開ける (旗のとき関数を抜ける)
    board[pos].Open();

    // closing_cellsの値を減らす
    --closing_cells;

    // 爆弾のとき、trueを返す
    if (board[pos].GetData() == CellData::Mine) return true;

    // 数字のとき、falseを返す
    if (board[pos].GetData() != CellData::_0) return false;

    // 周りを開ける
    auto OpenDirection = [&](Direction dir, std::uint16_t pos) -> void {
        // セルが存在しないとき何もしない
        if (!CheckDirection(dir, pos)) return;

        // その方向の場所を計算
        pos = CalcDirectionPos(dir, pos);

        // 開ける
        Open(pos);
    };
    OpenDirection(Direction(-1,  1), pos);   // 左上
    OpenDirection(Direction( 0,  1), pos);   // 上
    OpenDirection(Direction( 1,  1), pos);   // 右上
    OpenDirection(Direction(-1,  0), pos);   // 左
    OpenDirection(Direction( 1,  0), pos);   // 右
    OpenDirection(Direction(-1, -1), pos);   // 左下
    OpenDirection(Direction( 0, -1), pos);   // 下
    OpenDirection(Direction( 1, -1), pos);   // 右下

    return false;
}

bool MinesweeperSys::Open(std::uint8_t row, std::uint8_t column){
    if (row >= row_num) throw(false);
    if (column >= column_num) throw(false);
    return Open(PosFrom(row, column));
}

bool MinesweeperSys::IsOpen(std::uint16_t pos) noexcept{
    return board[pos].IsOpen();
}

bool MinesweeperSys::IsOpen(std::uint8_t row, std::uint8_t column) noexcept{
    return IsOpen(PosFrom(row, column));
}

void MinesweeperSys::ToggleFlag(std::uint16_t pos){
    // 存在するか確認
    if (pos >= GetSize()) throw(false);
    // 旗を反転
    board[pos].ToggleFlag();
}

void MinesweeperSys::ToggleFlag(std::uint8_t row, std::uint8_t column){
    // 存在するか確認
    if (row >= row_num || column >= column_num) throw(false);
    // 旗を反転
    ToggleFlag(PosFrom(row, column));
}

bool MinesweeperSys::IsFlagged(std::uint16_t pos) noexcept{
    return board[pos].IsFlagged();
}

bool MinesweeperSys::IsFlagged(std::uint8_t row, std::uint8_t column) noexcept{
    return IsFlagged(PosFrom(row, column));
}

std::uint16_t MinesweeperSys::GetRemainingMines() noexcept{
    std::uint16_t flag_count = 0;
    for (std::uint16_t i = 0; i < row_num * column_num; ++i) {
        if (board[i].IsOpen() == false) {
            if (board[i].IsFlagged() == true) {
                ++flag_count;
            }
        }
    }
    return mine - flag_count;
}

bool MinesweeperSys::IsSuccess() noexcept{
    if (closing_cells == mine) {
        return true;
    }
    return false;
}