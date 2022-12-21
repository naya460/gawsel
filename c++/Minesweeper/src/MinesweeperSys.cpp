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
        // 今の座標を削除
        list.erase(list.begin() + pos);
    }

    // 数字を配置
    for (std::uint16_t i = 0; i < size; ++i) {
        // 爆弾のとき無視
        if (board[i].GetData() == CellData::Mine) continue;
        // 変数宣言
        std::uint8_t count = 0;
        bool left = (i % row_num != 0);
        bool right = (i % row_num != row_num - 1);
        bool upper = (i >= column_num);
        bool bottom = (i <= row_num * column_num - column_num);
        // 上側
        if (upper) {
            // 左上
            if (left && (board[i - 1 - row_num].GetData() == CellData::Mine)) ++count;
            // 上
            if ((board[i - row_num].GetData() == CellData::Mine)) ++count;
            // 右上
            if (right && (board[i + 1 - row_num].GetData() == CellData::Mine)) ++count;
        }
        // 左
        if (left && (board[i - 1].GetData() == CellData::Mine)) ++count;
        // 右
        if (right && (board[i + 1].GetData() == CellData::Mine)) ++ count;
        // 下側
        if (bottom) {
            // 左下
            if (left && (board[i - 1 + row_num].GetData() == CellData::Mine)) ++count;
            // 下
            if ((board[i + row_num].GetData() == CellData::Mine)) ++count;
            // 右下
            if (bottom && (board[i + 1 + row_num].GetData() == CellData::Mine)) ++ count;
        }
        // 数字を書き込む
        board[i].Reset(static_cast<CellData>(count));
    }
}

MinesweeperCell MinesweeperSys::GetCell(std::uint16_t pos) noexcept{
    return board[pos];
}

MinesweeperCell MinesweeperSys::GetCell(std::uint8_t row, std::uint8_t column) noexcept{
    return GetCell(column * column_num + row);
}