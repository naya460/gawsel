import React, {useState} from "react"

import styles from "./LightsOutGame.module.css";

import LightsOutBoard from "../LightsOutBoard/LightsOutBoard";
import LightsOutMenuBar from "../LightsOutMenuBar/LightsOutMenuBar"
import ClearPopup from "./ClearPopup"

export default function LightsOutGame() {
  const [lights, setLights] = useState(Array(9).fill(false));
  const [length, setLength] = useState(3);
  const [clear, setClear] = useState(true);
  const [isPopupShown, setPopupShown] = useState(false);

  // 全てのライトがoffになったか確認
  function checkLights(lights: Array<boolean>) : boolean {
    if (clear) return false;
    for (let i = 0; i < length**2; i++) {
      if (lights[i] == true) {
        return false;
      }
    }
    setClear(true);
    return true;
  }

  // ライトを押したときの処理
  function pushLight(lights: Array<boolean>, pos: number) {
    // ライトを反転
    lights[pos] = !lights[pos];
    if (pos >= length)              lights[pos - length] = !lights[pos - length];
    if (pos + length <= length**2)  lights[pos + length] = !lights[pos + length];
    if (pos % length != 0)          lights[pos - 1] = !lights[pos - 1];
    if (pos % length < length - 1)  lights[pos + 1] = !lights[pos + 1];
    // クリアしたか確認
    if (checkLights(lights)) {
      setPopupShown(true);
    }

    return lights;
  }

  // ランダムに盤面を生成する処理
  function handleRandomize() {
    let lights_tmp = lights.slice();
    lights_tmp.fill(false);
    for (let i = 0; i < length**2; i++) {
      if (Math.floor(Math.random() * 2)) {
        lights_tmp = pushLight(lights_tmp, i);
      }
    }
    setLights(lights_tmp);
    setClear(false);
  }

  // 盤面の大きさを変えたときの処理
  function handleResize(resize_length: number) {
    setLength(resize_length);
    lights.fill(false);
    setLights(lights);
  }

  return (
    <div className={styles.game}>
      <div>
        <LightsOutMenuBar
          length={length}
          onRandomize={() => handleRandomize()}
          onResize={(length) => handleResize(length)}
        />
        <LightsOutBoard
          length={length}
          lights={lights} setLights={setLights}
          pushLight={(lights, pos) => pushLight(lights, pos)}
        />
        {
          function () {
            if (isPopupShown) {
              return <ClearPopup onClick={() => setPopupShown(false)}/>;
            } else {
              return <></>
            }
          }()
        }
      </div>
    </div>
  );
}