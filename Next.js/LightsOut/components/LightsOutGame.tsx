import React, {useState} from "react"

import styles from "../pages/LightsOut.module.css";

import LightsOutBoard from "./LightsOutBoard";
import LightsOutMenuBar from "./LightsOutMenuBar"

export default function LightsOutGame() {
  const [lights, setLights] = useState(Array(9).fill(false));
  const [length, setLength] = useState(3);

  function pushLight(lights, pos) {
    lights[pos] = !lights[pos];
    if (pos >= length)              lights[pos - length] = !lights[pos - length];
    if (pos + length <= length**2)  lights[pos + length] = !lights[pos + length];
    if (pos % length != 0)          lights[pos - 1] = !lights[pos - 1];
    if (pos % length < length - 1)  lights[pos + 1] = !lights[pos + 1];
    return lights;
  }

  function randomize() {
    let lights_tmp = lights.slice();
    lights_tmp.fill(false);
    for (let i = 0; i < length**2; i++) {
      if (Math.floor(Math.random() * 2)) {
        lights_tmp = pushLight(lights_tmp, i);
      }
    }
    setLights(lights_tmp);
  }

  function handleResize(resize_length) {
    setLength(resize_length);
    lights.fill(false);
    setLights(lights);
  }

  return (
    <div className={styles.LightsOutGame}>
      <div>
        <LightsOutMenuBar length={length} handleRandomize={() => randomize()} handleResize={(length) => handleResize(length)} />
        <LightsOutBoard pushLight={(lights, pos) => pushLight(lights, pos)} lights={lights} setLights={setLights} length={length} />
      </div>
    </div>
  );
}