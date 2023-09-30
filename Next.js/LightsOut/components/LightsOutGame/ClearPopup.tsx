/*
  Copyright 2023 naya460

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

import React from "react"

import styles from "./ClearPopup.module.css"

type Props = {
  onClick: () => void;
};

export default function ClearPopup(props: Props) {
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