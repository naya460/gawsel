import React, {useState} from "react"

import styles from "../pages/LightsOut.module.css";

export default function LightsOutCell(props) {
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