import React, {useState} from "react"

import styles from "./LightsOutCell.module.css";

export default function LightsOutCell(props) {
  return (
    <button
      className={`
        ${styles.cell}
        ${(props.isLightOn)? styles.cell_on : styles.cell_off}
      `}
      onClick={() => props.onClick()}
    />
  )
}