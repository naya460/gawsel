import react from "react"

import styles from "./MinesweeperMenuBar.module.css"

type Props = {
  onClickNewGameButton: () => void;
}

export default function MinesweeperMenuBar(props: Props): react.ReactElement {
  return(
    <div className={styles.menu_bar}>
      <button
      className={styles.new_game_button}
      onClick={() => props.onClickNewGameButton()}>New Game</button>
    </div>
  );
}