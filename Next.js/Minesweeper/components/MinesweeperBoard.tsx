import react, {useState} from "react"

import styles from "./MinesweeperBoard.module.css"

import MinesweeperCell from "./MinesweeperCell"

type CellStatus = {
  isOpen: boolean;
  number: number; // -1のとき爆弾
}

export default function(): react.ReactElement {
  const [lx, setLx] = useState(30);
  const [ly, setLy] = useState(16);
  const [board, setBoard] = useState<Array<CellStatus>>(
    Array<CellStatus>(lx * ly).fill({isOpen: false, number: 1})
  );

  function handleClickCell(x: number, y: number) {
    const board_slice = board.slice();
    const pos = lx * y + x;
    board_slice[pos] = {...board_slice[pos], isOpen: true};
    setBoard(board_slice);
  }

  return (
    <>
      <div>
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
                    onClick={() => handleClickCell(j, i)}
                    key={pos}
                  />
                );
              }
              list.push(<div className={styles.line}>{line}</div>);
            }
            return <div className={styles.board}>{list}</div>;
          }()
        }
      </div>
    </>
  );
}