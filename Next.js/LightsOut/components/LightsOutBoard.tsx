import React, {useState} from "react"

import styles from "../pages/LightsOut.module.css";

import LightsOutCell from "./LightsOutCell";

export default function LightsOutBoard(props) {
    function handleClick(i) {
      let lights_tmp = props.lights.slice();
      lights_tmp = props.pushLight(lights_tmp, i);
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