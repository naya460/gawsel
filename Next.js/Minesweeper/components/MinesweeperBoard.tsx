import react, {useState} from "react"

import styles from "./MinesweeperBoard.module.css"

import MinesweeperCell from "./MinesweeperCell"

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