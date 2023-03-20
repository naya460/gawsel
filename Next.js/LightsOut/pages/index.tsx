import React, {useState} from "react"

import styles from "./LightsOut.module.css";

const LightsOutCell = () => {
  const [isLightOn, setLight] = useState(false);

  return (
    <button
      className={`
        ${styles.LightsOutCell}
        ${(isLightOn)? styles.LightsOutCellOn : styles.LightsOutCellOff}
      `}
      onClick={() => setLight(!isLightOn)}
    />
  )
}

const LightsOutBoard = () => {
  function line() {
    const list = [];
    for (let i = 0; i < 3; i++) {
      list.push(<LightsOutCell />);
    }
    return <div className={styles.LightsOutBoardLine}>{list}</div>;
  }

  return (
    <div>
      {
        function () {
          const list = [];
          for (let i = 0; i < 3; i++) {
            list.push(line());
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
