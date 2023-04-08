import react from "react"

import styles from "./MinesweeperCell.module.css"

type Props = {
  status: boolean;
  onClick: () => void;
}

export default function MinesweeperCell(props: Props): react.ReactElement {
  return (
    <button
      className={`${styles.cell} ${props.status? styles.cell_open : styles.cell_close}`}
      onClick={() => props.onClick()}
    />
  );
}