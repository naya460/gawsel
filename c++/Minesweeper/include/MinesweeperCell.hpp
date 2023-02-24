#pragma once

// 番号や爆弾の一覧
enum class CellData {
    Mine = -1,
    _0 = 0,
    _1, _2, _3, _4,
    _5, _6, _7, _8,
};

class MinesweeperCell {
private:
    bool open = false;              // セルが空いているか
    CellData data = CellData::_0;   // 番号や爆弾
    bool flag = false;              // 旗が立っているか
public:
    // コンストラクタ
    MinesweeperCell() = default;

    // セルの初期化 (セルを閉じる & 値を0にする & 旗を解除)
    void Reset();

    // 番号や爆弾を設定
    void SetData(CellData data);

    // 数字を1つ増やす (爆弾のときは無視)
    void AddCellNum();

    // 番号や爆弾を返す
    CellData GetData();

    // 開ける (旗が立っているときは開けない)
    // 開けたときtrue、開けなかったときfalseを返す
    bool Open();

    // 空いているか確認
    bool IsOpen();

    // 旗を切り替える
    void ToggleFlag();

    // 旗の状態を調べる（true:旗が立っている）
    bool IsFlagged();
};
