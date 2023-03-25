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
  function line(row: number, length: number) : React.ReactElement {
    const list = [];
    for (let i = 0; i < length; i++) {
      list.push(
        <LightsOutCell
          isLightOn={props.lights[row * props.length + i]}
          onClick={() => handleClick(row * props.length + i)}
        />
      );
    }
    return <div className={styles.line}>{list}</div>;
  }
  
  return (
    <div>
      {
        // 行を縦に並べる
        function () {
          const list = [];
          for (let i = 0; i < props.length; i++) {
            list.push(line(i, props.length));
          }
          return <div className={styles.board}>{list}</div>;
        }()
      }
    </div>
  );
}