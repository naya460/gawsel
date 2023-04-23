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