import React, {useState} from "react"

import styles from "./LightsOut.module.css";

const LightsOutCell = (props) => {
  return (
    <button
      className={`
        ${styles.LightsOutCell}
        ${(props.isLightOn)? styles.LightsOutCellOn : styles.LightsOutCellOff}
      `}
      onClick={() => props.onClick()}
    />
  )
}

const LightsOutBoard = (props) => {
  function handleClick(i) {
    const lights_tmp = props.lights.slice();
    const length = props.length;

    lights_tmp[i] = !lights_tmp[i];
    if (i >= length)              lights_tmp[i - length] = !lights_tmp[i - length];
    if (i + length <= length**2)  lights_tmp[i + length] = !lights_tmp[i + length];
    if (i % length != 0)          lights_tmp[i - 1] = !lights_tmp[i - 1];
    if (i % length < length - 1)  lights_tmp[i + 1] = !lights_tmp[i + 1];
    
    props.setLights(lights_tmp);
  }

  function line(row, length) {
    const list = [];
    for (let i = 0; i < length; i++) {
      list.push(
        <LightsOutCell
          isLightOn={props.lights[row * props.length + i]}
          onClick={() => handleClick(row * props.length + i)}
        />
      );
    }
    return <div className={styles.LightsOutBoardLine}>{list}</div>;
  }

  return (
    <div>
      {
        function () {
          const list = [];
          for (let i = 0; i < props.length; i++) {
            list.push(line(i, props.length));
          }
          return <div className={styles.LightsOutBoard}>{list}</div>;
        }()
      }
    </div>
  );
}

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

  return (
    <div>
      <div className={styles.LightsOutResizePopupParent}>
        <button
          className={styles.LightsOutResizeButton}
          onClick={() => handleResizeButtonClick()}
        >
          Resize
        </button>
        <div className={`
          ${styles.LightsOutResizePopup}
          ${isPopupShown && styles.LightsOutResizePopupShown}
        `}>
          <button onClick={() => handleResize(3)}>3x3</button>
          <button onClick={() => handleResize(4)}>4x4</button>
          <button onClick={() => handleCloseResizePopup()}>Close</button>
        </div>
      </div>
    </div>
  )
}

const LightsOutGame = () => {
  const [lights, setLights] = useState(Array(9).fill(false));
  const [length, setLength] = useState(3);

  function randomize() {
    let lights_tmp = lights.slice();
    for (let i = 0; i < length**2; i++) {
      if (Math.floor(Math.random() * 2)) {
        lights_tmp[i] = true;
      } else {
        lights_tmp[i] = false;
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
          <ResizeButton onClick={(length) => handleResize(length)} />
        </div>
        <LightsOutBoard lights={lights} setLights={setLights} length={length} />
      </div>
    </div>
  );
}

export default function IndexPage() {
  return (
    <div>
      <LightsOutGame />
    </div>
  )
}
