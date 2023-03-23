import React, {useState} from "react"

import styles from "../pages/LightsOut.module.css";

import LightsOutBoard from "./LightsOutBoard";

const ResizeButton = (props) => {
  const [isPopupShown, setPopupShown] = useState(false);

  const handleResizeButtonClick = () => {
    if (isPopupShown) {
      setPopupShown(false);
    } else {
      setPopupShown(true);
    }
  }

  const handleCloseResizePopup = () => {
    setPopupShown(false);
  }

  const handleResize = (length) => {
    props.onClick(length);
    handleCloseResizePopup();
  }

  const SizeList = () => {
    let list = [];
    for (let i = 0; i < 8; i++) {
      let length = i + 3;
      list.push(
        <button className={styles.LightsOutSizeButton} onClick={() => handleResize(length)}>{length}x{length}</button>
      )
    }
    return <div>{list}</div>;
  }

  return (
    <div>
      <div className={styles.LightsOutResizePopupParent}>
        <button
          className={styles.LightsOutResizeButton}
          onClick={() => handleResizeButtonClick()}
        >
          Size<br />{props.length}x{props.length}
        </button>
        <div className={`
          ${styles.LightsOutResizePopup}
          ${isPopupShown && styles.LightsOutResizePopupShown}
        `}>
          {SizeList()}
          <button className={styles.LightsOutCloseButton} onClick={() => handleCloseResizePopup()}>Close</button>
        </div>
      </div>
    </div>
  )
}

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
        <div className={styles.LightsOutMenuBar}>
          <button className={styles.LightsOutNewGameButton} onClick={() => randomize()}>New Game</button>
          <ResizeButton onClick={(length) => handleResize(length)} length={length} />
        </div>
        <LightsOutBoard pushLight={(lights, pos) => pushLight(lights, pos)} lights={lights} setLights={setLights} length={length} />
      </div>
    </div>
  );
}