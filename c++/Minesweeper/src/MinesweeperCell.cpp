#include "MinesweeperCell.hpp"

#include <cstdint>

void MinesweeperCell::Reset(){
    open = false;
    this->data = CellData::_0;
    flag = false;
}

void MinesweeperCell::SetData(CellData data){
    this->data = data;
}

void MinesweeperCell::AddCellNum(){
    if (data == CellData::Mine) {
        return;
    }
    std::uint8_t num = static_cast<std::uint8_t>(data);
    data = static_cast<CellData>(++num);
}

CellData MinesweeperCell::GetData(){
    return data;
}

bool MinesweeperCell::IsOpen(){
    return open;
}

bool MinesweeperCell::Open(){
    if (flag == true) {
        return false;
    }
    return open = true;
}

void MinesweeperCell::ToggleFlag(){
    flag = !flag;
}

bool MinesweeperCell::IsFlagged(){
    return flag;
}