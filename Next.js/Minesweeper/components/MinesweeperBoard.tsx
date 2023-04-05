import react from "react"

import styles from "./MinesweeperBoard.module.css"

import MinesweeperCell from "./MinesweeperCell"

export default function(): react.ReactElement {
  return (
    <>
      <div>
        {
          function (): react.ReactElement {
            const list = [];
            for (let i = 0; i < 16; i++) {
              const line = [];
              for (let j = 0; j < 30; j++) {
                line.push(<MinesweeperCell />);
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