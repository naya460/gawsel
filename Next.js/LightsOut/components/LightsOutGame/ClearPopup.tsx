import React from "react"

import styles from "./ClearPopup.module.css"

export default function ClearPopup(props) {
    return (
      <>
        <div className={styles.popup_background} />
        <div className={styles.popup_parent}>
          <div className={styles.clear_popup}>
            <p className={styles.clear_text}>C L E A R !</p>
            <button
              className={styles.ok_button}
              onClick={() => props.onClick()}
            >O K</button>
          </div>
        </div>
      </>
    )
  }