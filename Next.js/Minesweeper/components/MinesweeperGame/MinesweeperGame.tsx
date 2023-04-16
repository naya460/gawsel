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

import styles from "./MinesweeperGame.module.css"

import MinesweeperBoard, {CellStatus} from "../MinesweeperBoard/MinesweeperBoard"
import MineSweeperMenuBar from "../MinesweeperMenuBar/MinesweeperMenuBar"

export default function MinesweeperGame(): react.ReactElement {
	const [lx, setLx] = useState(30);     // 横幅
  const [ly, setLy] = useState(16);     // 縦幅
  const [mine, setMine] = useState(99); // 爆弾の数
  const [start, setStart] = useState(false);  // 開始しているかどうか
  const [board, setBoard] = useState<Array<CellStatus>>(
    Array<CellStatus>(lx * ly).fill({isOpen: false, number: 0, isFlagged: false})
  );  // 盤面
  const [flagCount, setFlagCount] = useState(0);

	// 方向が存在するか確認する関数
	function checkUpper(pos: number): boolean {
		return (pos / lx) >= 1;
	}
	function checkBottom(pos: number): boolean {
		return (pos / lx) < ly - 1;
	}
	function checkLeft(pos: number): boolean {
		return (pos % lx) >= 1;
	}
	function checkRight(pos: number): boolean {
		return (pos % lx) < lx - 1;
	}

	// 周りに対して処理を施す関数
	function processAround(x: number, y:number, process: (x: number, y: number) => void): void {
		const pos = lx * y + x;
		if (checkUpper(pos)) {	// 上側
			if (checkLeft(pos)) process(x - 1, y - 1);	// 左上
			process(x, y - 1);													// 上
			if (checkRight(pos)) process(x + 1, y - 1);	// 右上
		}
    if (checkLeft(pos)) process(x - 1, y);  // 左
    if (checkRight(pos)) process(x + 1, y);	// 右
    if (checkBottom(pos)) { // 下側
      if (checkLeft(pos)) process(x - 1, y + 1);	// 左下
			process(x, y + 1);													// 下
			if (checkRight(pos)) process(x + 1, y + 1);	// 右下
    }
	}

	// セルを開ける関数
	function openCell(board_slice: CellStatus[], x: number, y: number): void {
		const pos = lx * y + x;
		// 開いているとき返却
		if (board_slice[pos].isOpen == true) return;
    // 旗が立っているとき返却
    if (board_slice[pos].isFlagged == true) return;
		// 開ける
		board_slice[pos] = {...board_slice[pos], isOpen: true};
		if (board_slice[pos].number == 0) {
      processAround(x, y, (x, y) => {openCell(board_slice, x, y)})
		}
	}

	// ランダムに爆弾を生成する関数
  function Randomize(x: number, y: number): CellStatus[] {
    // 番号の一覧を作成
    let number_list = Array<number>(lx * ly);
    for (let i = 0; i < number_list.length; i++) {
      number_list[i] = i;
    }
    // 安全地帯の作成
    number_list.splice(number_list.indexOf(lx * (y - 1) + x - 1), 1); // 左上
    number_list.splice(number_list.indexOf(lx * (y - 1) + x), 1);     // 上
    number_list.splice(number_list.indexOf(lx * (y - 1) + x + 1), 1); // 右上
    number_list.splice(number_list.indexOf(lx * y + x - 1), 1);       // 左
    number_list.splice(number_list.indexOf(lx * y + x), 1);           // 中央
    number_list.splice(number_list.indexOf(lx * y + x + 1), 1);       // 右
    number_list.splice(number_list.indexOf(lx * (y + 1) + x - 1), 1); // 左下
    number_list.splice(number_list.indexOf(lx * (y + 1) + x), 1);     // 下
    number_list.splice(number_list.indexOf(lx * (y + 1) + x + 1), 1); // 右下
    // 数字を増やす関数
    function addNumber(pos: number): void {
      if (board_slice[pos].number == -1) return;
      board_slice[pos] = {
        ...board_slice[pos], number: board_slice[pos].number + 1
      };
    }
    // ランダムに配置
    let board_slice = board.slice();
    board_slice.fill({isOpen: false, number: 0, isFlagged: false});
    for (let i = 0; i < mine; i++) {
      // 爆弾を配置
      let pos = number_list[Math.floor(Math.random() * number_list.length)];
      board_slice[pos] = {...board_slice[pos], number: -1};
      number_list.splice(number_list.indexOf(pos), 1);
      // 周囲に数字を配置
      processAround(pos % lx, Math.floor(pos / lx), (x, y) => {addNumber(lx * y + x)});
    }

    return board_slice;
  }

	// セルを左クリックしたときの処理
  function handleClickCell(x: number, y: number): void {
    let board_slice = board.slice();
    const pos = lx * y + x;
    // 旗が立っているとき開けない
    if (board_slice[pos].isFlagged == true) return;
    // 最初に開けるときに初期化
    if (start == false) {
      board_slice = Randomize(x, y);
      setStart(true);
    }
    // 開ける
    if (board_slice[pos].isOpen == false) {
      openCell(board_slice, x, y);
    } else {
      // 周りの旗の数をカウント
      let flags = 0;
      processAround(
        pos % lx,
        Math.floor(pos / lx),
        (x, y) => {if (board_slice[lx * y + x].isFlagged) flags++}
      );
      // 爆弾の数と旗の数が一致したとき開ける
      if (board_slice[pos].number == flags) {
        processAround(
          pos % lx,
          Math.floor(pos / lx),
          (x, y) => {openCell(board_slice, x, y)}
        );
      }
    }
    setBoard(board_slice);
  }

	// セルを右クリックしたときの処理
	function handleRightClickCell(x: number, y: number): void {
		const board_slice = board.slice();
		const pos = lx * y + x;
		// 開いているとき、旗を立てない
		if (board_slice[pos].isOpen == true) return;
		// 旗を立てる
		board_slice[pos] = {...board_slice[pos], isFlagged: !board_slice[pos].isFlagged}
    if (board_slice[pos].isFlagged) setFlagCount(flagCount + 1); else setFlagCount(flagCount - 1);
		setBoard(board_slice);
	}

	return (
		<>
      <div style={{'width': 'fit-content'}}>
        <MineSweeperMenuBar
          mine={mine - flagCount}
          start={start}
          onClickNewGameButton={() => {
            const board_slice = board.slice();
            board_slice.fill({isOpen: false, number: 0, isFlagged: false});
            setBoard(board_slice);
            setStart(false);
            setFlagCount(0);
          }}
          setSize={(lx, ly, mine) => {
            setLx(lx);
            setLy(ly);
            setMine(mine);
            setStart(false);
            setFlagCount(0);
            const board_slice = board.slice();
            board_slice.fill({isOpen: false, number: 0, isFlagged: false});
            setBoard(board_slice);
          }}
        />
        <MinesweeperBoard
          lx={lx} ly={ly} board={board}
          onClickCell={handleClickCell}
          onRightClickCell={handleRightClickCell}
        />
      </div>
		</>
	)
}