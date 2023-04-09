import react from "react"

import styles from "./MinesweeperCell.module.css"

type Props = {
  isOpen: boolean;
  number: number;
  isFlagged: boolean;
  onClick: () => void;
  onRightClick: () => void;
}

export default function MinesweeperCell(props: Props): react.ReactElement {
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
        ${props.isFlagged?
          styles.cell_flagged :
          (props.isOpen? styles.cell_open : styles.cell_close)
        }
      `}
      onClick={() => props.onClick()}
      onContextMenu={() => {props.onRightClick()}}
    >{displayNumber()}</button>
  );
}