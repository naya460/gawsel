#include "MinesweeperSys.hpp"

#include <algorithm>
#include <random>

// === MinesweeperCell ===
void MinesweeperCell::Reset(CellData data){
    open = false;
    this->data = data;
}

CellData MinesweeperCell::GetData(){
    return data;
}

bool MinesweeperCell::IsOpen(){
    return open;
}

void MinesweeperCell::Open(){
    open = true;
}

// === MinesweeperSys ===
bool MinesweeperSys::CheckDirection(Direction dir, std::uint16_t pos) noexcept{
    bool ok = true; // 存在するか保存する変数
    // 上側
    if (dir == Direction::UL || dir == Direction::U || dir == Direction::UR) {
        if (pos < row_num) ok = false;
    }
    // 下側
    if (dir == Direction::BL || dir == Direction::B || dir == Direction::BR) {
        if (pos >= row_num * (column_num - 1)) ok = false;
    }
    // 左側
    if (dir == Direction::UL || dir == Direction::L || dir == Direction::BL) {
        if (pos % row_num == 0) ok = false;
    }
    // 右側
    if (dir == Direction::UR || dir == Direction::R || dir == Direction::BR) {
        if ((pos + 1) % row_num == 0) ok = false;
    }
    // 返却
    return ok;
}

void MinesweeperSys::AddDirectionNum(Direction dir, std::uint16_t pos) noexcept{
    // セルが存在しないとき何もしない
    if (!CheckDirection(dir, pos)) return;
    
    // その方向の場所を計算
    if (dir == Direction::UL || dir == Direction::U || dir == Direction::UR) pos -= row_num;    // 上側
    if (dir == Direction::BL || dir == Direction::B || dir == Direction::BR) pos += row_num;    // 下側
    if (dir == Direction::UL || dir == Direction::L || dir == Direction::BL) pos -= 1;          // 左側
    if (dir == Direction::UR || dir == Direction::R || dir == Direction::BR) pos += 1;          // 右側

    // 爆弾のとき何もしない
    if (board[pos].GetData() == CellData::Mine) return;

    // 数字を取得
    int num = static_cast<int>(board[pos].GetData());

    // 加算して代入
    board[pos].Reset(static_cast<CellData>(++num));
}

void MinesweeperSys::AddCellNum(std::uint16_t pos) noexcept{
    AddDirectionNum(Direction::UL, pos);    // 左上
    AddDirectionNum(Direction::U,  pos);    // 上
    AddDirectionNum(Direction::UR, pos);    // 右上
    AddDirectionNum(Direction::L,  pos);    // 左
    AddDirectionNum(Direction::R,  pos);    // 右
    AddDirectionNum(Direction::BL, pos);    // 左下
    AddDirectionNum(Direction::B,  pos);    // 下
    AddDirectionNum(Direction::BR, pos);    // 右下
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
    this->mine = std::min(mine, static_cast<std::uint16_t>(row_num * column_num - 9));
    // 盤面の大きさを変更
    board.resize(row_num * column_num);
    for (auto v : board) {
        v.Reset(CellData::_0);
    }
}

void MinesweeperSys::Randam() noexcept{
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

    // ランダムに爆弾を設置
    for (std::uint16_t i = 0; i < mine; ++i) {
        // 乱数を作成
        std::uniform_int_distribution<> dist(0, list.size() - 1);
        std::uint16_t pos = dist(engine);
        // 爆弾を挿入
        board[list[pos]].Reset(CellData::Mine);
        // 数字を増やす
        AddCellNum(list[pos]);
        // 今の座標を削除
        list.erase(list.begin() + pos);
    }
}

MinesweeperCell MinesweeperSys::GetCell(std::uint16_t pos) noexcept{
    return board[pos];
}

MinesweeperCell MinesweeperSys::GetCell(std::uint8_t row, std::uint8_t column) noexcept{
    return GetCell(column * column_num + row);
}