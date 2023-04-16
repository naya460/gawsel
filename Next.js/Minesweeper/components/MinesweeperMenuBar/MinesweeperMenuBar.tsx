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

import react, {useEffect, useState} from "react"

import styles from "./MinesweeperMenuBar.module.css"

import ResizeButton from "./ResizeButton"

type Props = {
  mine: number;
  start: boolean;
  onClickNewGameButton: () => void;
  setSize: (lx: number, ly: number, mine: number) => void;
}

export default function MinesweeperMenuBar(props: Props): react.ReactElement {
  const [time, setTime] = useState(0);

  // 時間のカウント
  useEffect(() => {
    const timer = setInterval(() => {
      if (props.start) {
        setTime((time) => time + 1)
      }
    }, 1000);
    return () => clearInterval(timer);
  }, [props.start])

  // 時間を「時:分:秒」の形にする
  function createTimeText(): string {
    let text = "";
    if (time >= 60 * 60) {
      text += (Math.floor(time / 60 / 60)) + " : ";
      if (Math.floor(time / 60 % 60) < 10) text += "0"
    }
    if (time >= 60) {
      text += (Math.floor(time / 60 % 60) + " : ");
      if (time % 60 < 10) text += "0";
    }
    text += (time % 60) + "";
    return text;
  }

  return(
    <div className={styles.menu_bar}>
      <button
        className={styles.new_game_button}
        onClick={() => {
          props.onClickNewGameButton()
          setTime(0);
        }}
      >New Game</button>
      <ResizeButton
        setSize={(lx, ly, mine) => {
          props.setSize(lx, ly, mine)
          setTime(0);
        }}
      />
      <div className={styles.space}/>
      <div className={styles.text}>Time<br/>{createTimeText()}</div>
      <div className={styles.text}>Mine<br/>{props.mine}</div>
    </div>
  );
}