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