import react from "react"

import styles from "./MinesweeperCell.module.css"

type Props = {
  isOpen: boolean;
  number: number;
  onClick: () => void;
}

export default function MinesweeperCell(props: Props): react.ReactElement {
  function displayNumber(): string {
    if (props.number == 0) {
      return '';
    } else if (props.isOpen) {
      return props.number.toString();
    }
  }

  return (
    <button
      className={`${styles.cell} ${props.isOpen? styles.cell_open : styles.cell_close}`}
      onClick={() => props.onClick()}
    >{displayNumber()}</button>
  );
}