import react, {useState} from "react"

import styles from "./MinesweeperMenuBar.module.css"

import ResizeButton from "./ResizeButton"

type Props = {
  onClickNewGameButton: () => void;
  setSize: (lx: number, ly: number, mine: number) => void;
}

export default function MinesweeperMenuBar(props: Props): react.ReactElement {
  return(
    <div className={styles.menu_bar_parent}>
      <div className={styles.menu_bar}>
        <button
          className={styles.new_game_button}
          onClick={() => props.onClickNewGameButton()}
        >New Game</button>
        <ResizeButton setSize={(lx, ly, mine) => props.setSize(lx, ly, mine)}/>
      </div>
    </div>
  );
}