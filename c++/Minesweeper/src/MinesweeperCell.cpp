#include "MinesweeperCell.hpp"

void MinesweeperCell::Reset(){
    open = false;
    this->data = CellData::_0;
    flag = false;
}

void MinesweeperCell::SetData(CellData data){
    this->data = data;
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