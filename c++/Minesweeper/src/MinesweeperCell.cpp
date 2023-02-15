#include "MinesweeperCell.hpp"

void MinesweeperCell::Reset(CellData data){
    open = false;
    this->data = data;
    flag = false;
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