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

pub trait LightsOutUI {
    // 新しい盤面で開始
    fn new_game(&mut self, length: u8);

    // 盤面を表示
    fn display(&self);
    
    // ライトを押す (失敗時:false)
    fn push(&mut self, pos: u16) -> bool;
}