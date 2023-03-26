import React from "react"

import styles from "./LightsOutMenuBar.module.css";

import ResizeButton from "./ResizeButton";

type Props = {
  length: number;
  onRandomize: () => void;
  onResize: (length: number) => void;
}

export default function LightsOutMenuBar(props: Props) {
  return (
    <div className={styles.menu_bar}>
      <button
        className={styles.new_game_button}
        onClick={() => props.onRandomize()}
      >New Game</button>
      <ResizeButton onClick={(length) => props.onResize(length)} length={props.length} />
    </div>
  )
}