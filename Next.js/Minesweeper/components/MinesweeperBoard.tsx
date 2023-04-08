import react, {useState} from "react"

import styles from "./MinesweeperBoard.module.css"

import MinesweeperCell from "./MinesweeperCell"

type CellStatus = {
  isOpen: boolean;
}

export default function(): react.ReactElement {
  const [lx, setLx] = useState(30);
  const [ly, setLy] = useState(16);
  const [board, setBoard] = useState<Array<CellStatus>>(Array(lx * ly).fill({isOepn: false}));

  function handleClickCell(x: number, y: number) {
    const tmp = board.slice();
    tmp[lx * y + x] = {isOpen: true};
    setBoard(tmp);
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
                    status={board[pos].isOpen}
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