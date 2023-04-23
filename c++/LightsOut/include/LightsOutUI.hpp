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

#pragma once

#include <cstdint>

#include "LightsOutSys.hpp"

class LightsOutUI {
protected:
    LightsOutSys system;
public:
    // 新しい盤面で開始
    virtual void NewGame(std::uint8_t length) noexcept = 0;

    // 盤面を表示
    virtual void Display() noexcept = 0;

    // ライトを押す（失敗時：false）
    virtual bool Push(std::uint16_t position) noexcept = 0;
    virtual bool Push(std::uint8_t row, std::uint8_t column) noexcept = 0;

    // すべてoffにできているか確認
    virtual bool IsSuccess() noexcept = 0;
};