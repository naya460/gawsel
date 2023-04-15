/*
  Copyright 2023 naya460

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

import react, {useState} from "react"

import styles from "./MinesweeperMenuBar.module.css"

import ResizeButton from "./ResizeButton"

type Props = {
  mine: number;
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
        <div>Mine : {props.mine}</div>
      </div>
    </div>
  );
}