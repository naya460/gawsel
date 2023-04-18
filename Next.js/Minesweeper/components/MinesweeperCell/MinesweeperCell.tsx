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

import react from "react"

import styles from "./MinesweeperCell.module.css"

type Props = {
  x: number;
  y: number;
  isOpen: boolean;
  number: number;
  isFlagged: boolean;
  onClick: (x: number, y: number) => void;
  onRightClick: (x: number, y: number) => void;
}

const MinesweeperCell = react.memo(
  (props: Props): react.ReactElement => {
    // 表示する内容を返却
    function displayNumber(): string {
      if (props.isFlagged == true) {
        return 'P';
      }
      if (props.isOpen == false) {
        return '';
      }
      if (props.number == 0) {
        return '';
      }
      if (props.number == -1) {
        return 'X';
      }
      return props.number.toString();
    }

    return (
      <button
        className={`
          ${styles.cell} 
          ${props.isFlagged? (
              (props.number == -2) ? styles.mistake_flag : styles.cell_flagged
            ):
              (props.isOpen? (
                (props.number == -1) ? styles.cell_mine : styles.cell_open
              ): styles.cell_close
            )
          }
        `}
        onClick={() => props.onClick(props.x, props.y)}
        onContextMenu={() => {props.onRightClick(props.x, props.y)}}
      >{displayNumber()}</button>
    );
  }
);

export default MinesweeperCell;