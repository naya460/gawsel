import react, {useState} from "react"

import styles from "./MinesweeperBoard.module.css"

import MinesweeperCell from "./MinesweeperCell"

interface CellStatus {
  isOpen: boolean;
  number: number; // -1のとき爆弾
  isFlagged: boolean;
}

export default function(): react.ReactElement {
  const [lx, setLx] = useState(30);     // 横幅
  const [ly, setLy] = useState(16);     // 縦幅
  const [mine, setMine] = useState(99); // 爆弾の数
  const [start, setStart] = useState(false);  // 開始しているかどうか
  const [board, setBoard] = useState<Array<CellStatus>>(
    Array<CellStatus>(lx * ly).fill({isOpen: false, number: 0, isFlagged: false})
  );  // 盤面

  // セルを左クリックしたとき
  function handleClickCell(x: number, y: number): void {
    let board_slice = board.slice();
    const pos = lx * y + x;
    // 旗が立っているとき開けない
    if (board_slice[pos].isFlagged == true) return;
    // 最初に開けるときに初期化
    if (start == false) {
      board_slice = handleRandomize(x, y);
      setStart(true);
    }
    // 開ける
    if (board_slice[pos].isOpen == false) {
      board_slice = openCell(board_slice, x, y);
    } else {
      // 周りの旗の数をカウント
      let flags = 0;
      if (checkUpper(pos)) {  // 上側
        if (checkLeft(pos) && board_slice[pos - lx - 1].isFlagged) flags++; // 左上
        if (board_slice[pos - lx].isFlagged) flags++; // 上
        if (checkRight(pos) && board_slice[pos - lx + 1].isFlagged) flags++;  // 右上
      }
      if (checkLeft(pos) && board_slice[pos - 1].isFlagged) flags++;  // 左
      if (checkRight(pos) && board_slice[pos + 1].isFlagged) flags++; // 右
      if (checkBottom(pos)) {  // 下側
        if (checkLeft(pos) && board_slice[pos + lx - 1].isFlagged) flags++; // 左下
        if (board_slice[pos + lx].isFlagged) flags++; // 下
        if (checkRight(pos) && board_slice[pos + lx + 1].isFlagged) flags++;  // 右下
      }
      // 爆弾の数と旗の数が一致したとき開ける
      if (board_slice[pos].number == flags) {
        if (checkUpper(pos)) {  // 上側
          if (checkLeft(pos)) board_slice = openCell(board_slice, x - 1, y - 1);  // 左上
          board_slice = openCell(board_slice, x, y - 1); // 上
          if (checkRight(pos)) board_slice = openCell(board_slice, x + 1, y - 1); // 右上
        }
        if (checkLeft(pos)) board_slice = openCell(board_slice, x - 1, y);  // 左
        if (checkRight(pos)) board_slice = openCell(board_slice, x + 1, y); // 右
        if (checkBottom(pos)) {  // 下側
          if (checkLeft(pos)) board_slice = openCell(board_slice, x - 1, y + 1);  // 左下
          board_slice = openCell(board_slice, x, y + 1); // 下
          if (checkRight(pos)) board_slice = openCell(board_slice, x + 1, y + 1); // 右下
        }
      }
    }
    setBoard(board_slice);
  }

  // セルを開ける
  function openCell(board_slice: CellStatus[], x: number, y: number): CellStatus[] {
    const pos = lx * y + x;
    // 開いているとき返却
    if (board_slice[pos].isOpen == true) return board_slice;
    // 開ける
    board_slice[pos] = {...board_slice[pos], isOpen: true};
    if (board_slice[pos].number == 0) {
      if (checkUpper(pos)) {  // 上側
        if (checkLeft(pos)) board_slice = openCell(board_slice, x - 1, y - 1);    // 左上
        board_slice = openCell(board_slice, x, y - 1);   // 上
        if (checkRight(pos)) board_slice = openCell(board_slice, x + 1, y - 1);   // 右上
      }
      if (checkBottom(pos)) {
        if (checkLeft(pos)) board_slice = openCell(board_slice, x - 1, y + 1);    // 左下
        board_slice = openCell(board_slice, x, y + 1);  // 下
        if (checkRight(pos)) board_slice = openCell(board_slice, x + 1, y + 1);   // 右下
      }
      if (checkLeft(pos)) board_slice = openCell(board_slice, x - 1, y);    // 左
      if (checkRight(pos)) board_slice = openCell(board_slice, x + 1, y);   // 右
    }
    return board_slice;
  }

  // セルを右クリックしたとき
  function handleRightClickCell(x: number, y: number): void {
    const board_slice = board.slice();
    const pos = lx * y + x;
    // 開いているとき、旗を立てない
    if (board_slice[pos].isOpen == true) return;
    // 旗を立てる
    board_slice[pos] = {...board_slice[pos], isFlagged: !board_slice[pos].isFlagged}
    setBoard(board_slice);
  }

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

  // ランダムに爆弾を生成
  function handleRandomize(x: number, y: number): CellStatus[] {
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
      if (checkUpper(pos)) {  // 上側
        if (checkLeft(pos)) addNumber(pos - lx - 1);  // 左上
        addNumber(pos - lx);  // 上
        if (checkRight(pos)) addNumber(pos - lx + 1); // 右上
      }
      if (checkLeft(pos)) addNumber(pos - 1);   // 左
      if (checkRight(pos)) addNumber(pos + 1);  // 右
      if (checkBottom(pos)) {  // 下側
        if (checkLeft(pos)) addNumber(pos + lx - 1);  // 左下
        addNumber(pos + lx);  // 下
        if (checkRight(pos)) addNumber(pos + lx + 1); // 右下
      }
    }
    
    return board_slice;
  }

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
                    onClick={() => handleClickCell(j, i)}
                    onRightClick={() => handleRightClickCell(j, i)}
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