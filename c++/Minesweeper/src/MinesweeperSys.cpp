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

        // 爆弾のとき何もしない
        if (board[pos].GetData() == CellData::Mine) return;

        // 数字を取得
        int num = static_cast<int>(board[pos].GetData());

        // 加算して代入
        board[pos].SetData(static_cast<CellData>(++num));
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
    this->mine = std::min(mine, static_cast<std::uint16_t>(row_num * column_num - 9));
    // 盤面の大きさを変更
    board.resize(row_num * column_num);
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
}

MinesweeperCell MinesweeperSys::GetCell(std::uint16_t pos) noexcept{
    return board[pos];
}

MinesweeperCell MinesweeperSys::GetCell(std::uint8_t row, std::uint8_t column) noexcept{
    return GetCell(row * column_num + column);
}

bool MinesweeperSys::Open(std::uint16_t pos){
    //存在するか確認
    if (pos >= GetSize()) throw(false);

    // 最初に開けたとき、生成
    if (started == false) Random(pos);
    
    // 空いているとき、falseを返す
    if (board[pos].IsOpen()) return false;

    // 押した場所を開ける (旗のとき関数を抜ける)
    if (!board[pos].Open()) {
        return false;
    }

    // 爆弾のとき、trueを返す
    if (board[pos].GetData() == CellData::Mine) return true;

    // 数字のとき、falseを返す
    if (board[pos].GetData() != CellData::_0) return false;

    // 周りを開ける
    if (CheckDirection(Direction(-1,  1), pos)) Open(pos - column_num - 1);
    if (CheckDirection(Direction( 0,  1), pos)) Open(pos - column_num);
    if (CheckDirection(Direction( 1,  1), pos)) Open(pos - column_num + 1);
    if (CheckDirection(Direction(-1,  0), pos)) Open(pos - 1);
    if (CheckDirection(Direction( 1,  0), pos)) Open(pos + 1);
    if (CheckDirection(Direction(-1, -1), pos)) Open(pos + column_num - 1);
    if (CheckDirection(Direction( 0, -1), pos)) Open(pos + column_num);
    if (CheckDirection(Direction( 1, -1), pos)) Open(pos + column_num + 1);

    return false;
}

bool MinesweeperSys::Open(std::uint8_t row, std::uint8_t column){
    if (row >= row_num) throw(false);
    if (column >= column_num) throw(false);
    return Open(row * column_num + column);
}

void MinesweeperSys::ToggleFlag(std::uint16_t pos){
    // 存在するか確認
    if (pos >= row_num * column_num) throw(false);
    // 旗を反転
    board[pos].ToggleFlag();
}

void MinesweeperSys::ToggleFlag(std::uint8_t row, std::uint8_t column){
    // 存在するか確認
    if (row >= row_num || column >= column_num) throw(false);
    // 旗を反転
    ToggleFlag(row * column_num + column);
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
    std::uint16_t close_count = 0;
    for (std::uint16_t i = 0; i < row_num * column_num; ++i) {
        if (board[i].IsOpen() == false) {
            ++close_count;
        }
    }
    if (close_count == mine) {
        return true;
    }
    return false;
}