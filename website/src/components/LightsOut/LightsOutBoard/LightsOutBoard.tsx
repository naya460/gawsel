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

import styles from "./LightsOutBoard.module.css";

import LightsOutCell from "../LightsOutCell/LightsOutCell";

type Props = {
  lights: Array<boolean>;
  length: number;
  pushLight: (lights: boolean[], position: number) => Array<boolean>;
  setLights: (lights: Array<boolean>) => void;
};

export default function LightsOutBoard(props: Props) : React.ReactElement {
  // クリック時の処理
  // ライトを反転させる
  function handleClick(pos: number) {
    let lights_tmp = props.lights.slice();
    lights_tmp = props.pushLight(lights_tmp, pos);
    props.setLights(lights_tmp);
  }
  
  // 行のReact要素を作成する
  function line(row: number, length: number, key: number) : React.ReactElement {
    const list = [];
    for (let i = 0; i < length; i++) {
      list.push(
        <LightsOutCell
          key={i}
          isLightOn={props.lights[row * props.length + i]}
          onClick={() => handleClick(row * props.length + i)}
        />
      );
    }
    return <div key={key} className={styles.line}>{list}</div>;
  }
  
  return (
    <div>
      {
        // 行を縦に並べる
        function () {
          const list = [];
          for (let i = 0; i < props.length; i++) {
            list.push(line(i, props.length, i));
          }
          return <div className={styles.board}>{list}</div>;
        }()
      }
    </div>
  );
}