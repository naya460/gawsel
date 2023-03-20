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

const LightsOutBoard = () => {
  const [lights, setLights] = useState(Array(9).fill(false));

  function handleClick(i) {
    const lights_tmp = lights.slice();
    lights_tmp[i] = !lights_tmp[i];
    setLights(lights_tmp);
  }

  function line(row) {
    const list = [];
    for (let i = 0; i < 3; i++) {
      list.push(
        <LightsOutCell
          isLightOn={lights[row * 3 + i]}
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

export default function IndexPage() {
  return (
    <div>
      <LightsOutBoard />
    </div>
  )
}
