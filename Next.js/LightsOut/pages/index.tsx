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

    lights_tmp[i] = !lights_tmp[i];
    if (i >= 3)         lights_tmp[i - 3] = !lights_tmp[i - 3];
    if (i + 3 <= 3**2)  lights_tmp[i + 3] = !lights_tmp[i + 3];
    if (i % 3 != 0)     lights_tmp[i - 1] = !lights_tmp[i - 1];
    if (i % 3 < 3 - 1)  lights_tmp[i + 1] = !lights_tmp[i + 1];
    
    props.setLights(lights_tmp);
  }

  function line(row) {
    const list = [];
    for (let i = 0; i < 3; i++) {
      list.push(
        <LightsOutCell
          isLightOn={props.lights[row * 3 + i]}
          onClick={() => handleClick(row * 3 + i)}
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
          for (let i = 0; i < 3; i++) {
            list.push(line(i));
          }
          return <div>{list}</div>;
        }()
      }
    </div>
  );
}

const LightsOutGame = () => {
  const [lights, setLights] = useState(Array(9).fill(false));

  function randomize() {
    let lights_tmp = lights.slice();
    for (let i = 0; i < 3**2; i++) {
      if (Math.floor(Math.random() * 2)) {
        lights_tmp[i] = true;
      } else {
        lights_tmp[i] = false;
      }
    }
    setLights(lights_tmp);
  }

  return (
    <div>
      <button onClick={() => randomize()}>New Game</button>
      <LightsOutBoard lights={lights} setLights={setLights} />
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
