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

import react, {useState} from "react"

import styles from "./MinesweeperBoard.module.css"

import MinesweeperCell from "../MinesweeperCell/MinesweeperCell"

export interface CellStatus {
  isOpen: boolean;
  number: number; // -1のとき爆弾
  isFlagged: boolean;
}

type Props = {
  lx: number;           // 盤面の横幅
  ly: number;           // 盤面の縦幅
  board: CellStatus[];  // 盤面
  onClickCell: (x: number, y: number) => void;
  onRightClickCell: (x: number, y: number) => void;
}

export default function(props: Props): react.ReactElement {
  const lx = props.lx;
  const ly = props.ly;
  const board = props.board;

  return (
    <>
      <div onContextMenu={(event) => event.preventDefault()}>
        {
          function (): react.ReactElement {
            const list = [];
            for (let i = 0; i < ly; i++) {
              const line = [];
              for (let j = 0; j < lx; j++) {
                const pos = lx * i + j;
                line.push(
                  <MinesweeperCell
                    isOpen={board[pos].isOpen}
                    number={board[pos].number}
                    isFlagged={board[pos].isFlagged}
                    onClick={() => props.onClickCell(j, i)}
                    onRightClick={() => props.onRightClickCell(j, i)}
                    key={pos}
                  />
                );
              }
              list.push(<div className={styles.line} key={i}>{line}</div>);
            }
            return <div className={styles.board}>{list}</div>;
          }()
        }
      </div>
    </>
  );
}