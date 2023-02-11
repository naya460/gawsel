#pragma once

// 番号や爆弾の一覧
enum class CellData {
    Mine = -1,
    _0 = 0,
    _1, _2, _3, _4,
    _5, _6, _7, _8,
};

// 方向の一覧
enum class Direction {
    UL, U, UR,  // 左上、上、右上
    L, C, R,    // 左、中央、右
    BL, B, BR,  // 左下、下、右下
};

class MinesweeperCell {
private:
    bool open = false;              // セルが空いているか
    CellData data = CellData::_0;   // 番号や爆弾
    bool flag = false;              // 旗が立っているか
public:
    // コンストラクタ
    MinesweeperCell() = default;

    // セルの初期化
    void Reset(CellData data);

    // 番号や爆弾を返す
    CellData GetData();

    // 開ける
    void Open();

    // 空いているか確認
    bool IsOpen();

    // 旗を切り替える
    void ToggleFlag();

    // 旗の状態を調べる（true:旗が立っている）
    bool IsFlagged();
};
